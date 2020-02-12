#include <bits/stdc++.h>

#define M 10000

using namespace std;

int n, m, k, ok = 0;
int t[M], v[M], e[M];

void osszefesul(int a[], int b[], int n, int m, int c[], int &k) {
    int i = 0, j = 0;
    k = 0;
    while (i < n && j < m) {

        if (a[i] < b[j]) {
            if (a[i] % 2 == 0)
                c[k++] = a[i++];
            else i++;
        } else {
            if (b[j] % 2 == 0)
                c[k++] = b[j++];
            else j++;
        }
    }

    while (i < n) {
        if (a[i] % 2 == 0)
            c[k++] = a[i++];
        else i++;
    }
    while (j < m) {
        if (b[j] % 2 == 0)
            c[k++] = b[j++];
        else j++;
    }
}

void reszleges_rendezes(int t[], int n, int &k) {
    int s = t[0], e = 0, u = n - 1;
    while (e <= u) {
        while (t[u] > s && e <= u) u--;
        if (e <= u)
            t[e++] = t[u];

        while (t[e] < s && e <= u) e++;
        if (e <= u)
            t[u--] = t[e];
    }
    t[u] = s;
    k = u;
}

void beolvas(int &n, int &m, int t[], int v[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &v[i]);
    }
}
void kiirat(int tb[], int n){
    for (int i = n-1; i >= 0; --i) {
        printf("%d ", tb[i]);
    }
}
int main() {
    freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    beolvas(n, m, t, v);
    osszefesul(t, v, n, m, e, k);
    kiirat(e, k);
}