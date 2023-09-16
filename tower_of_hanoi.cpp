#include<bits/stdc++.h>


using namespace std;

int main(){

    return 0;
}
void tower_of_hanoi(int n,char a,char b,char c){
    if(n==1){
        cout<<a<<"-->"<<c<<endl;
        return;
    }
    tower_of_hanoi(n-1,a,c,b);
    cout<<a<<"-->"<<c<<endl;
    tower_of_hanoi(n-1,b,a,c);
}


int main(){
    int n;
    cin>>n;
    char a,b,c;
    a='A';
    b='B';
    c='C';
    tower_of_hanoi(n,a,b,c);
    return 0;
}
