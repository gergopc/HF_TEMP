#include <bits/stdc++.h>

#define M 10000

using namespace std;

int n, x;
int t[M];

void beolvas(int t[], int &n, int &x){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    scanf("%d", &x);
}

int biturbo_kereses(int v[], int n, int x){
    int e=0, u=n-1, k, tl;
    while(e<=u){
        k=(e+u)/2;
        if(t[k]<x) {
            tl=t[k];
            u = k - 1;
        }else if(t[k]>x)
            e=k+1;
        else if(t[k]==x)
            return t[k];
    }
    return tl;
}

int main() {
    freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int k;
    beolvas(t, n, x);
    if(x<t[n-1])
        cout<<"nu exista";
    else{
        cout<<biturbo_kereses(t, n, x);
    }
}