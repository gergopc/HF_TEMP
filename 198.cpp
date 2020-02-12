#include <bits/stdc++.h>

#define MAX 102

using namespace std;

int n, k;
int iHalmaz[MAX];
int iVerem[MAX];
int iMin = 9999;

void beolvas(int &n, int iHalmaz[]) {
    ifstream fin("file.in");
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> iHalmaz[i];
    }
}


bool megoldas(int n, int k) {
    return k == n;
}

bool ellenoriz(int n, int k) {
    bool bOk = 1;
    for (int i = k - 1; i >= 1 && bOk == 1; --i) {
        if (iVerem[i] > 1)
            bOk = 0;
    }
    return bOk;
}

void feldolgozMegoldas(int n) {
    int iOsszeg = 0;
    for (int i = 1; i <= n; ++i) {
        if (iVerem[i] == 1)
            cout << iHalmaz[i]<<' ';
    }
    cout << endl;
}

void backtrack(int n, int k) {
    k = 1;
    iVerem[1] = -1;
    while (k > 0) {
        if (iVerem[k] < 1) {
            iVerem[k]++;
            if (ellenoriz(n, k)) {
                if (megoldas(n, k)) {
                    feldolgozMegoldas(n);
                } else {
                    k++;
                    iVerem[k] = -1;
                }
            }
        } else k--;
    }


}

int main() {

    beolvas(n, iHalmaz);
    backtrack(n, k);
}