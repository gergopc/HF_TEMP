#include <bits/stdc++.h>

#define M 50

using namespace std;

int iEllista[2][M];
int iN, iM;
bool bPontElMatrix[M][M];

void beolvas(int &iN, int &iM, int iEllista[][M]) {
    int iKezdopont, iVegpont;
    ifstream sIn("ELLISTA.txt");
    sIn >> iN >> iM;
    for (int i = 1; i <= iM; ++i) {
        sIn >> iKezdopont >> iVegpont;
        iEllista[0][i] = iKezdopont;
        iEllista[1][i] = iVegpont;
    }
}

void kiirKepernyoreEllistat(int iM, int iEllista[][M]) {

    for (int i = 1; i <= iM; ++i) {
        cout << iEllista[0][i] << ' ' << iEllista[1][i] << endl;
    }
}

void felepitPontElMatrix(int iM, int iEllista[][M], bool bPontElMatrix[][M]) {
    int iKezdopont, iVeggpont;
    for (int i = 1; i <= iM; ++i) {
        iKezdopont = iEllista[0][i];
        iVeggpont = iEllista[1][i];
        bPontElMatrix[iKezdopont][i]=1;
        bPontElMatrix[iVeggpont][i]=1;
    }
}

void kiiratPontElMatrix(int iN, int iM, bool bPontPontMatrix[][M]) {
    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iM; ++j) {
            cout << bPontPontMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}


int main() {
    beolvas(iN, iM, iEllista);
    kiirKepernyoreEllistat(iM, iEllista);
    felepitPontElMatrix(iM, iEllista, bPontElMatrix);
    kiiratPontElMatrix(iN, iM, bPontElMatrix);
}

