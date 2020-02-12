#include <bits/stdc++.h>

using namespace std;

void kiiratBinaris(int n) {
    if (n > 0)
        kiiratBinaris(n >> 1);
    cout << (n & 1);
}

int felcserelBajtok(int n) {
    short int a, b, c;
    a=n;
    b=(a&255);
    a>>=8;
    c=(a&255);
    a=b;
    a<<=8;
    a|=c;
    return a;
}

int main() {
    int a, b;
    cin >> a;
    cout << felcserelBajtok(a);
}