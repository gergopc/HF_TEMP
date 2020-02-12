#include <bits/stdc++.h>

using namespace std;

int titkosit(int n){
  n^=(1<<3);
 n^=(1<<6);
 return n;
}

int main(){
    int a, b;
    cin>>a;
    b=titkosit(a);
    cout<<b<<endl;
    b=titkosit(b);
    cout<<b<<endl;
}