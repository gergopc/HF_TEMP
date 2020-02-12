#include <bits/stdc++.h>

#define MAX 102

using namespace std;

int n, k;
int iMatrix[MAX][MAX];
int iVerem[MAX];
int iMin=9999;

void beolvas(int &n, int iMatrix[][MAX]) {
    ifstream fin("file.in");
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> iMatrix[i][j];
        }
    }
}

bool ellenoriz(int n, int k) {
    bool bOk = 1;
    for (int i = k - 1; i >= 1 && bOk == 1; --i) {
        if (iVerem[k] == iVerem[i])
            bOk = 0;
    }
    return bOk;
}

bool megoldas(int n, int k) {
    return k == n;
}

void feldolgozMegoldas(int n) {
    int iOsszeg = 0;
    for (int i = 1; i <= n; ++i) {
        iOsszeg += iMatrix[i][iVerem[i]];
    }
    iMin = min(iMin, iOsszeg);
}

void backtrack(int n, int k) {
    k = 1;
    while (k > 0) {
        if (iVerem[k] < n) {
            iVerem[k]++;
            if (ellenoriz(n, k)) {
                if (megoldas(n, k)) {
                    feldolgozMegoldas(n);
                } else {
                    k++;
                    iVerem[k] = 0;
                }
            }
        } else k--;
    }


}

int main() {

    beolvas(n, iMatrix);
    backtrack(n, k);
    cout << iMin;
}