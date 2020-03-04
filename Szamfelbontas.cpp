#include <bits/stdc++.h>

#define MAX 102

using namespace std;

int n, k;
int iHalmaz[MAX];
int iVerem[MAX];
int iMin = 9999;

void beolvas(int &n) {
    ifstream fin("file.in");
    fin >> n;
}


bool megoldas(int n, int k) {
    int iOsszeg = 0;
    for (int i = k; i >= 1; --i) {
        iOsszeg += iVerem[i];
    }
    return iOsszeg == n;
}


void feldolgozMegoldas(int k) {
    int iOsszeg = 0;
    for (int i = 1; i <= k; ++i) {
        cout << iVerem[i] << ' ';
    }
    cout << endl;
}

void backtrack(int n, int k) {
    k = 1;
    iVerem[1] = 0;
    while (k > 0) {
        if (iVerem[k] < n - k + 1) {
            iVerem[k]++;
            if (megoldas(n, k)) {
                feldolgozMegoldas(k);
            } else {
                k++;
                iVerem[k] = 0;
            }
        } else k--;
    }


}

int main() {

    beolvas(n);
    backtrack(n, k);
}