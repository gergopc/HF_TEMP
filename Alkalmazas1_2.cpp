#include <bits/stdc++.h>

#define M 50

using namespace std;

int iEllista[2][M];
int iN, iM;
bool bPontPontMatrix[M][M];

void beolvas(int &iN, bool bPontPontMatrix[][M]) {
    int iKezdopont, iVegpont;
    ifstream sIn("BOOLE.txt");
    sIn >> iN;
    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iN; ++j) {
            sIn >> bPontPontMatrix[i][j];
        }
    }
}

void kiirKepernyorePontPontMatrixot(int iN, bool bPontPontMatrix[][M]) {

    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iN; ++j) {
            cout << bPontPontMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void felepitEllista(int iN, int &iM, int iEllista[][M], bool bPontPontMatrix[][M]) {
    int iKezdopont, iVeggpont;

    for (int i = 1; i <= iN; ++i) {
        for (int j = i; j <= iN; ++j) {
            if(bPontPontMatrix[i][j]==1){
                iKezdopont=i;
                iVeggpont=j;
                iEllista[0][iM]=iKezdopont;
                iEllista[1][iM++]=iVeggpont;
            }
        }
    }
}

void kiiratEllista(int iM, int iEllista[][M]) {
    for (int i = 0; i < iM; ++i) {
        cout<<iEllista[0][i]<<' '<<iEllista[1][i]<<endl;
    }
}


int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(iN, bPontPontMatrix);
    kiirKepernyorePontPontMatrixot(iN, bPontPontMatrix);
    felepitEllista(iN, iM, iEllista, bPontPontMatrix);
    kiiratEllista(iM, iEllista);
}

