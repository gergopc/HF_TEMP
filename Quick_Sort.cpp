#include <bits/stdc++.h>

#define M 20

using namespace std;

int n, m, k, ok = 0;
int v[M], e[M];
int tb[]={4, 1, 9, 2, 3, 10, 10, 2};

int reszleges_rendezes(int t[], int e, int u){
    int s=t[e];
    while(e<u){
        while(t[u]>s && e<u) u--;
            if(e<u)
                t[e++]=t[u];

        while(t[e]<s && e<u) e++;
        if(e<u)
            t[u--]=t[e];
    }
    t[u]=s;
    return u;
}

void QuickSort(int t[], int e, int u){
    if(e<u){
        int k=reszleges_rendezes(t, e, u);
        QuickSort(t, e, k-1);
        QuickSort(t, k+1, u);
    }
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/

    int n=8, k;

    QuickSort(tb, 0, n-1);


    for (int i = 0; i < n; ++i) {
        cout<<tb[i]<<' ';
    }
}