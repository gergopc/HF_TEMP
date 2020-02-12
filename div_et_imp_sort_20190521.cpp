#include <bits/stdc++.h>

#define M 20

using namespace std;

int n, m, k, ok = 0;
int v[M], e[M];
int tb[]={4, 1, 9, 2, 3, 10, 10, 2};
void osszefesul(int a[], int b[], int n, int m, int c[], int &k) {
    int i = 0, j = 0;
	k = 0;
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

void reszleges_rendezes(int t[], int n, int &k){
    int s=t[0], e=0, u=n-1;
    while(e<=u){
        while(t[u]>s && e<=u) u--;
            if(e<=u)
                t[e++]=t[u];

        while(t[e]<s && e<=u) e++;
        if(e<=u)
            t[u--]=t[e];
    }
    t[u]=s;
    k=u;
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/

    int n=8, k;
    reszleges_rendezes(tb, n, k);
    cout<<k<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<tb[i]<<' ';
    }
}