#include <bits/stdc++.h>

using namespace std;

void kiiratBinaris(int n){
    if(n>0)
        kiiratBinaris(n>>1);
    cout<<(n&1);
}

int bitrotacio(int n, int db){
   /* int iHosszusag=0;
    int m=n;
    while(m){
        iHosszusag++;
        m>>=1;
    }*/

    return (n >> db)|(n << (32 - db));
}

int main(){
    int a, b;
    cin>>a;
    cout<<bitrotacio(a, 3);
}