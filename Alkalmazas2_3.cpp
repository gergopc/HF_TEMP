#include <bits/stdc++.h>

#define M 50

using namespace std;


int iN, iM;
int iEllista[2][M];
bool bPontPontMatrix[M][M];
bool bPontElMatrix[M][M];

void beolvas(int &iN, bool bPontPontMatrix[][M]) {
    int iKezdopont, iVegpont;
    ifstream sIn("PONTEL.txt");
    sIn >> iN >> iM;
    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iM; ++j) {
            sIn >> bPontElMatrix[i][j];
        }
    }
}

void kiirKepernyoreEllistat(int iM, int iEllista[][M]) {

    for (int i = 1; i <= iM; ++i) {
        cout << iEllista[0][i] << ' ' << iEllista[1][i] << endl;
    }
}

void felepitEllista(int iN, int iM, bool bPontElMatrix[][M], int iEllista[][M]) {
    int iKezdopont, iVeggpont;
    bool bTalalt = false;
    for (int j = 1; j <= iM; ++j) {
        iKezdopont = -1;
        iVeggpont = -1;
        bTalalt = false;
        for (int i = 1; i <= iN; ++i) {
            if (bPontElMatrix[i][j] == 1) {
                bTalalt = !bTalalt;
                if(bTalalt)
                    iKezdopont=i;
                else
                    iVeggpont=i;
            }
        }
        if(iKezdopont!=-1){
            iEllista[0][j]=iKezdopont;
            if(iVeggpont!=-1)
                iEllista[1][j]=iVeggpont;
            else
                iEllista[1][j]=iKezdopont;
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

void felepitPontPontMatrix(int iM, int iEllista[][M], bool bPontPontMatrix[][M]) {
    int iKezdopont, iVeggpont;
    for (int i = 0; i < iM; ++i) {
        iKezdopont = iEllista[0][i];
        iVeggpont = iEllista[1][i];
        bPontPontMatrix[iKezdopont][iVeggpont] = 1;
        bPontPontMatrix[iVeggpont][iKezdopont] = 1;
    }
}

void kiiratPontPontMatrix(int iN, bool bPontPontMatrix[][M]) {
    for (int i = 1; i <= iN; ++i) {
        for (int j = 1; j <= iN; ++j) {
            cout << bPontPontMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(iN, bPontPontMatrix);
    kiiratPontElMatrix(iN, iM, bPontElMatrix);
    felepitEllista(iN, iM, bPontElMatrix, iEllista);
    cout << endl;
    kiirKepernyoreEllistat(iM, iEllista);
    cout<<endl;
    felepitPontPontMatrix(iM, iEllista, bPontPontMatrix);
    kiiratPontPontMatrix(iN, bPontPontMatrix);
}

