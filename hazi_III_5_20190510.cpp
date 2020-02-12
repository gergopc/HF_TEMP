#include <bits/stdc++.h>

#define M 20

using namespace std;

int n, m, ok = 0;
int t[M], v[M], e[M];

void osszefesul(int a[], int b[], int n, int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {

        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < n)
        c[k++] = a[i++];

    while (j < m)
        c[k++] = b[j++];
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    ifstream fin("file.in");
    fin >> n >> m;
    for (int i = 0; i < n; ++i) {
        fin >> t[i];
    }
    for (int i = 0; i < m; ++i) {
        fin >> v[i];
    }
    osszefesul(t, v, n, m, e);
    for (int i = n+m-1; i >= 1; --i) {
        if(e[i]%2==0 && e[i-1]!=e[i]){
            ok=1;
            cout<<e[i]<<' ';
        }
    }
    if(e[0]!=e[1] && e[0]%2==0)
        cout<<e[0];
    if(ok==0)
        cout<<"nu exista";
}