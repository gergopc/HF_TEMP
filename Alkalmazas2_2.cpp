#include <bits/stdc++.h>

#define M 50

using namespace std;

bool bPontElMatrix[M][M];
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

void felepitPontElMatrix(int iN, int &iElIndex, bool bontElMatrix[][M], bool bPontPontMatrix[][M]) {
    int iKezdopont, iVeggpont;

    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iN; ++j) {
            if(bPontPontMatrix[i][j]==1){
               iElIndex++;
                bontElMatrix[i][iElIndex]=1;
                bontElMatrix[j][iElIndex]=1;
            }
        }
    }
}

void kiiratPontElMatrix(int iN, int iM, bool bPontElMatrix[][M]) {
    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iM; ++j) {
            cout << bPontElMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}


int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(iN, bPontPontMatrix);
    kiirKepernyorePontPontMatrixot(iN, bPontPontMatrix);
    felepitPontElMatrix(iN, iM, bPontElMatrix, bPontPontMatrix);
    cout<<endl;
    kiiratPontElMatrix(iN, iM, bPontElMatrix);
}

