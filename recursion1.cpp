#include<bits/stdc++.h>
using namespace std;


void func(int n){
    if(n==1)
        return;
    cout<<n<<endl;
    func(n-1);
    //cout<<n<<endl;
}


int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}


int power_linear(int x,int n){
    if(n==0)
        return 1;
    return x*power_linear(x,n-1);
}


void f(int n){
    if(n==0)
        return;
    cout<<"Pre "<<n<<endl;
    f(n-1);
    cout<<"In "<<n<<endl;
    f(n-1);
    cout<<"Post "<<n<<endl;
}


void display_array(int arr[],int n){
    if(n==0)
        return;
    display_array(arr,n-1);
    cout<<arr[n-1]<<endl;
}


void displayArr(int arr[],int n,int idx){
    if(idx==n)
        return;

    displayArr(arr,n,idx+1);
    cout<<arr[idx]<<endl;
}


int max_of_array(int arr[],int idx,int n){
    if(idx==n-1)
        return arr[idx];
    int misa=max_of_array(arr,idx+1,n);
    return max(misa,arr[idx]);
}


int min_of_array(int arr[],int idx,int n){
    if(idx==n-1)
        return arr[idx];
    int misa=min_of_array(arr,idx+1,n);
    if(misa<arr[idx])
        return misa;
    else
        return arr[idx];
}


int first_index(int arr[],int idx,int n,int x){
    if(idx==n)
        return -1;
    int fisa=first_index(arr,idx+1,n,x);
    if(arr[idx]==x)
        return idx;
    else
        return fisa;
}


int lastIndex(int arr[],int idx,int n,int x){
    if(idx == n)
        return -1;
    int liisa = lastIndex(arr, idx+1, n, x);
    if(liisa == -1){
        if(arr[idx] == x)
            return idx;
        else
            return -1;
    }
    else
        return liisa;
}


//Generating all the indexes for the given element in the array.
int asize=0;
int *allIndices(int arr[],int x,int idx,int fsf,int n){
    if(idx == n){
        asize=fsf;
        return new int[fsf];
    }
    if(arr[idx] == x){
        int *iarr=allIndices(arr,x,idx+1,fsf+1,n);
        iarr[fsf]=idx;
        return iarr;
    }
    else{
        int *iarr=allIndices(arr,x,idx+1,fsf,n);
        return iarr;
    }
}


//Generating all the subsequences for the giving string
vector<string> gss(string s){
    if(s.length()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch=s[0];
    string ros=s.substr(1);
    vector<string> rres=gss(ros);
    vector<string> myResult;
    for(string x:rres){
        myResult.push_back(""+x);
        myResult.push_back(ch+x);
    }
    return myResult;

}



//Printing the Keypad Combinations
//Codes for the key 0 1 2 3 4 5 6 7 8 9
string codes[10]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> getKPC(string s){
    if(s.length() == 0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch=s[0];
    string ros=s.substr(1);
    vector<string> rres=getKPC(ros);
    vector<string> myres;
    string codeforch=codes[ch-48];
    for(char chcode: codeforch){
        for(string rstr: rres)
            myres.push_back(chcode+rstr);
    }
    return myres;
}


int countways(int n){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int call1=countways(n-1);
    int call2=countways(n-2);
    return call1+call2;
}


//Generate all the stair path from nth to 0th stair by either taking 1,2 or 3 steps at a time.
vector<string> getStairPaths(int n){
    if(n==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    if(n<0){
        vector<string> bres;
        return bres;
    }
    vector<string> paths1=getStairPaths(n-1);
    vector<string> paths2=getStairPaths(n-2);
    vector<string> paths3=getStairPaths(n-3);
    vector<string> paths;
    for(string path:paths1)
        paths.push_back("1"+path);
    for(string path:paths2)
        paths.push_back("2"+path);
    for(string path:paths3)
        paths.push_back("3"+path);
    return paths;
}


//Generating all the maze paths from (sr,sc) to (dr,dc)
vector<string> getMazePaths(int sr,int sc,int dr,int dc){
    if(sr==dr and sc==dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> hpaths;
    vector<string> vpaths;
    if(sc<dc){
        hpaths=getMazePaths(sr,sc+1,dr,dc);
    }
    if(sr<dr){
        vpaths=getMazePaths(sr+1,sc,dr,dc);
    }
    vector<string> paths;
    for(string path:hpaths)
        paths.push_back("h"+path);
    for(string path:vpaths)
        paths.push_back("v"+path);
    return paths;
}


//Get maze paths with jumps
vector<string> getMazePathJumps(int sr,int sc,int dr,int dc){
    if(sr==dr and sc==dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    vector<string> paths;
    //Horizontal moves
    for(int moves=1;moves<=dc-sc;moves++){
        vector<string> hpaths=getMazePathJumps(sr,sc+moves,dr,dc);
        for(string path:hpaths)
            paths.push_back("h"+to_string(moves)+path);
    }

    //Vertical moves
    for(int moves=1;moves<=dr-sr;moves++){
        vector<string> vpaths=getMazePathJumps(sr+moves,sc,dr,dc);
        for(string path:vpaths)
            paths.push_back("v"+to_string(moves)+path);
    }

    //Diagonal moves
    for(int moves=1;moves<=dr-sr and moves<=dc-sc;moves++){
        vector<string> dpaths=getMazePathJumps(sr+moves,sc+moves,dr,dc);
        for(string path:dpaths)
            paths.push_back("d"+to_string(moves)+path);
    }

    return paths;
}


//Printing the subsequences
void printSS(string ques,string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string ros=ques.substr(1);
    printSS(ros, ans+ch);
    printSS(ros, ans+"");
}


//Printing the Keypad Combination
void printKPC(string ques,string ans){
    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string ros=ques.substr(1);
    string codeforch=codes[ch-48];
    for(char chcode: codeforch){
        printKPC(ros,ans+chcode);
    }
}


//Printing the stair paths
void printStairPaths(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(n<0){
        return;
    }
    printStairPaths(n-1,ans+"1");
    printStairPaths(n-2,ans+"2");
    printStairPaths(n-3,ans+"3");
}


//Printing the maze paths
void printMazePaths(int sr,int sc,int dr,int dc,string ans){
    if(sr==dr and sc==dc){
        cout<<ans<<endl;
        return;
    }
    if(sc<dc)
        printMazePaths(sr,sc+1,dr,dc,ans+"h");
    if(sr<dr)
        printMazePaths(sr+1,sc,dr,dc,ans+"v");
}


//Printing the maze paths with jumps
void printMazePathsJumps(int sr,int sc,int dr,int dc,string ans){
    if(sr==dr and sc==dc){
        cout<<ans<<endl;
        return;
    }
    for(int x=1;x<=dc-sc;x++){
        printMazePathsJumps(sr,sc+x,dr,dc,ans+"h"+to_string(x));
    }
    for(int x=1;x<=dr-sr;x++){
        printMazePathsJumps(sr+x,sc,dr,dc,ans+"v"+to_string(x));
    }
    for(int x=1;x<=dr-sr and x<=dc-sc;x++){
        printMazePathsJumps(sr+x,sc+x,dr,dc,ans+"d"+to_string(x));
    }
}


//Printing the permutations of the string
void printPermutations(string str,string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string left_str=str.substr(0,i);
        string right_str=str.substr(i+1);
        printPermutations(left_str+right_str,ans+ch);
    }
}


//Printing the flood fill solutions
void floodfill(vector<vector<int>> &arr,int row,int col,string ans,vector<vector<bool>> &visited){
    if(row<0 or row==arr.size() or col<0 or col==arr[0].size() or arr[row][col]==1 or visited[row][col]==true){
        return;
    }
    if(row==arr.size()-1 and col==arr[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    visited[row][col]=true;
    floodfill(arr,row-1,col,ans+"t",visited);
    floodfill(arr,row,col-1,ans+"l",visited);
    floodfill(arr,row+1,col,ans+"d",visited);
    floodfill(arr,row,col+1,ans+"r",visited);
    visited[row][col]=false;
}


//Target Sum Subsets
void printTargetSumSubsets(vector<int> &arr,int idx,string subset,int subsum,int target){
    if(idx==arr.size()){
        if(subsum == target){
            cout<<subset.substr(0,subset.length()-2)<<endl;
        }
        return;
    }
    printTargetSumSubsets(arr,idx+1,subset+to_string(arr[idx])+", ",subsum+arr[idx],target);
    printTargetSumSubsets(arr,idx+1,subset,subsum,target);

}

//********N-Queens Problem****************
//Checking the current cell is safe for the queen or not.
bool isQueenSafe(vector<vector<int>> &chess,int row,int col){
    //Checking Vertically
    for(int i=row-1,j=col;i>=0;i--){
        if(chess[i][j]==1)
            return false;
    }

    //Checking diagonally in \ direction
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
        if(chess[i][j]==1)
            return false;
    }

    //Checking diagonally in / direction
    for(int i=row-1,j=col+1;i>=0 and j<chess.size();i--,j++){
        if(chess[i][j]==1)
            return false;
    }
    //If none of the above condition is hindrance then that cell is safest position for that queen
    return true;
}


//Placing N-Queens in N*N Chess Board
void printNQueens(vector<vector<int>> &chess,string ans,int row){
    if(row==chess.size()){
        cout<<ans.substr(0,ans.length()-1)+"."<<endl;
        return;
    }
    for(int col=0;col<chess.size();col++){
        if(isQueenSafe(chess,row,col)){
            chess[row][col]=1;
            printNQueens(chess,ans+to_string(row)+"-"+to_string(col)+",",row+1);
            chess[row][col]=0;
        }
    }
}


//Knights Tour Problems
void displayBoard(vector<vector<int>> &);
void printKnightTour(vector<vector<int>> &chess,int r,int c,int moveNo){
    if(r<0 or c<0 or r>=chess.size() or c>=chess.size() or chess[r][c]>0){
        return;
    }
    if(moveNo == (chess.size()*chess.size())){
        chess[r][c]=moveNo;
        displayBoard(chess);
        chess[r][c]=0;
        return;
    }
    chess[r][c]=moveNo;
    printKnightTour(chess,r-2,c+1,moveNo+1);
    printKnightTour(chess,r-1,c+2,moveNo+1);
    printKnightTour(chess,r+1,c+2,moveNo+1);
    printKnightTour(chess,r+2,c+1,moveNo+1);
    printKnightTour(chess,r+2,c-1,moveNo+1);
    printKnightTour(chess,r+1,c-2,moveNo+1);
    printKnightTour(chess,r-1,c-2,moveNo+1);
    printKnightTour(chess,r-2,c-1,moveNo+1);
    chess[r][c]=0;
}


void displayBoard(vector<vector<int>> &chess){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


//Printing all possible encodings of a string
void printEncodings(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    if(ques.length()==1){
        char ch=ques[0];
        if(ch=='0')
            return;
        else{
            int chv=ch-48;
            char code=(char)('a'+chv-1);
            ans+=code;
            cout<<ans<<endl;
            return;
        }
    }
    char ch=ques[0];
    string roq=ques.substr(1);
    if(ch=='0'){
        return;
    }
    else{
        int chv=ch-48;
        char code=(char)('a'+chv-1);
        printEncodings(roq,ans+code);
    }
    string f12=ques.substr(0,2);
    string roq12=ques.substr(2);
    int ch12v=stoi(f12);
    if(ch12v<=26){
        char chcode=(char)('a'+ch12v-1);
        printEncodings(roq12,ans+chcode);
    }
}


bool isSafe(int *arr,int pos,int n){
    for(int i=0;i<n;i++){
        if(arr[i] == pos){
            return false;
        }
    }
    return true;
}

const int mod = 1e9 + 7;
int ans = 0;
void fnc(int steps,int n,int *arr,int &cnt){
    if(steps > n or isSafe(arr, steps, n) == false){
        return;
    }
    if(steps == n){
        cnt=((cnt%mod)+(1%mod))%mod;
        ans++;
        return;
    }
    cout<<n<<" ";
    fnc(steps + 1,n,arr,cnt);
    fnc(steps + 2,n,arr,cnt);
}


int main(){
    int arr[]={0};
    int cnt = 0;
    int n = 6;
    for(int i=1;i<n;i++){
        fnc(i, n, arr, cnt);
        cout<<endl;
    }
    cout<<ans;
    //int x=2,n=6;
    //int arr[]={1,2,1,5,6,1};
    //f(3);
    //displayArr(arr,n,0);
//    int *ans=allIndices(arr,1,0,0,n);
//    cout<<asize<<"\n";
//    int i=0,temp=-1;
//    while(ans[i]>=0 and ans[i]<n and ans[i]>temp){
//        temp=ans[i];
//        cout<<ans[i]<<" ";
//        i++;
//    }
//    vector<string> ans=gss("abc");
//    for(string x:ans)
//        cout<<x<<endl;
//    vector<string> ans=getKPC("678");
//    cout<<"All the possible keypad combinations for 452 is:- "<<endl;
//    for(string x: ans){
//        cout<<x<<endl;
//    }
//    vector<string> ans=getMazePathJumps(1,1,3,3);
//    for(string x:ans)
//        cout<<x<<endl;
    //printSS("abc","");
    //printKPC("678","");
    //printStairPaths(4,"");
    //printMazePathsJumps(1,1,2,2,"");
    //printPermutations("abc","");
//    int n=6,m=7;
//    vector<vector<int>> arr{
//        {0, 1, 0, 0, 0, 0, 0},
//        {0, 1, 0, 1, 1, 1, 0},
//        {0, 0, 0, 0, 0, 0, 0},
//        {1, 0, 1, 1, 0, 1, 1},
//        {1, 0, 1, 1, 0, 1, 1},
//        {1, 0, 0, 0, 0, 0, 0}
//    };
//    vector<vector<bool>> visited(n,vector<bool>(m,false));
//    floodfill(arr,0,0,"",visited);
//    vector<int> arr{10,20,30,40,50};
//    printTargetSumSubsets(arr,0,"",0,70);
//    int n=8;
//    vector<vector<int>> chess(n,vector<int>(n,0));
//    printNQueens(chess,"",0);
//    int n=5;
//    vector<vector<int>> chess(n,vector<int>(n,0));
//    printKnightTour(chess,2,0,1);
//    printEncodings("303","");
//    return 0;
}
