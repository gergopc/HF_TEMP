#include <bits/stdc++.h>

#define MAX 102

using namespace std;

int n, k;
int iMatrix[MAX][MAX];
int iVerem[MAX];
int iMax = 0;
int iOsszeg;

bool bOszlop[MAX];

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
    return !bOszlop[iVerem[k]];
}

bool megoldas(int n, int k) {
    return k == n;
}

void feldolgozMegoldas(int n) {

    for (int i = 1; i <= n; ++i) {
        iOsszeg += iMatrix[i][iVerem[i]];
    }

}

void backtrack(int n, int k) {
    k = 1;
    bool bOk = 0;
    while (k > 0) {
        if (iVerem[k] < n) {
            iVerem[k]++;

            if (ellenoriz(n, k)) {
                bOk = 1;
                bOszlop[iVerem[k]] = 1;
                iOsszeg += iMatrix[k][iVerem[k]];
                if (megoldas(n, k)) {
                    iMax = max(iMax, iOsszeg);
                } else {
                    k++;
                    iVerem[k] = 0;
                }
            }
        } else {
            iOsszeg -= iMatrix[k][iVerem[k]];
            bOszlop[iVerem[k]] = 0;
            k--;
            bOszlop[iVerem[k]] = 0;
            iOsszeg -= iMatrix[k][iVerem[k]];
        }
    }


}

int main() {

    beolvas(n, iMatrix);
    backtrack(n, k);
    cout << iMax;
}