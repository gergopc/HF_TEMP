#include <bits/stdc++.h>

using namespace std;

void kiiratBinaris(int n){
    if(n>0)
        kiiratBinaris(n>>1);
    cout<<(n&1);
}

int bitrotacio(int n, int db){
    int a=n;
    a&=255;
    a=(a >> db)|(a << (8 - db));
    a&=255;
    n>>=8;
    n<<=8;
    n|=a;
    return n;
}

int main(){
    int a, b;
    cin>>a;
    cout<<bitrotacio(a, 3);
}