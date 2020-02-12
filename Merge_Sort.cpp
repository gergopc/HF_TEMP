#include <bits/stdc++.h>

#define M 100

using namespace std;

int n, m, k, ok = 0;
int v[M], e[M];
int tb[]={1,3,4,2};

void osszefesul(int t[], int e, int u, int k) {
    int i = e, j = k+1;
	int p=0;
	int c[M];
    while (i <= k && j <= u) {

        if (t[i] < t[j])
            c[p++] = t[i++];
        else
            c[p++] = t[j++];
    }

    while (i <= k)
        c[p++] = t[i++];

    while (j <= u)
        c[p++] = t[j++];

    for (int l = 0; l < p; ++l) {
        t[l+e]=c[l];
    }

}

void MergeSort(int t[], int e, int u){
    if(e<u){
        int k=(e+u)/2;
        MergeSort(t, e, k);
        MergeSort(t,k+1,u);
        osszefesul(t, e, u, k);
    }

}

void kiirat(int t[], int n){
    for (int i = 0; i < n; ++i) {
        printf("%d ", t[i]);
    }
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/

    int n=4, k;
   MergeSort(tb, 0, n-1);
   kiirat(tb, n);
}