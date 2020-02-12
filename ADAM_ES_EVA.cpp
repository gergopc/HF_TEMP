//
// Created by gergo on 2019. 10. 09..
//
#include <iostream>
#include <fstream>

#define MAX_CSP 1002
#define MAX_EL 1000001

//#define fin cin

using namespace std;

int n, m;
int iAdam, iEva;
int iUt[MAX_CSP];
int iFrekvenciaAdam[MAX_CSP];
int iFrekvenciaEva[MAX_CSP];
int iUtAdam[MAX_CSP];
int iUtEva[MAX_CSP];

bool bPpm[MAX_CSP][MAX_CSP];


struct El {
    int honnan, hova;
};
El Ellista[MAX_EL];

void beolvas(El Ellista[], int &n) {
    ifstream fin("file.in");
    fin >> n >> m >> iAdam >> iEva;
    El el;
    for (int i = 1; i <= m; ++i) {
        fin >> el.honnan >> el.hova;
        bPpm[el.honnan][el.hova] = 1;
    }

}

void szelessegiElmegy(bool bPpm[][MAX_CSP], int n, int iKiinduloCsp, int iVegpont, int iFr[], int iUt[]) {
    int e, u, iCsp;
    bool bOk = 0;
    e = u = 0;
    iUt[u++] = iKiinduloCsp;
    iFr[iKiinduloCsp] = 1;
    while (e < u && bOk == 0) {
        iCsp = iUt[e];
        for (int i = 1; i <= n && bOk == 0; i++) {
            if (bPpm[iCsp][i] == 1 && iFr[i] == 0) {
                iUt[u++] = i;
                iFr[i] = iFr[iCsp] + 1;
                if (i == iVegpont)
                    bOk = 1;
            }
        }
        e++;
    }

}

void szelessegiBejar(bool bPpm[][MAX_CSP], int n, int iKiinduloCsp, int iFr[], int iUt[]) {
    int e, u, iCsp;
    e = u = 0;
    iUt[u++] = iKiinduloCsp;
    iFr[iKiinduloCsp] = 1;
    while (e < u) {
        iCsp = iUt[e];
        for (int i = 1; i <= n; i++) {
            if (bPpm[iCsp][i] == 1 && iFr[i] == 0) {
                iUt[u++] = i;
                iFr[i] = iFr[iCsp] + 1;
            }
        }
        e++;
    }

}

void kiir(int iUt[], int n) {
    for (int i = 0; i < n; i++)
        cout << iUt[i] << ' ';
}


int main() {
    beolvas(Ellista, n);
    szelessegiBejar(bPpm, n, iAdam, iFrekvenciaAdam, iUt);
    szelessegiBejar(bPpm, n, iEva, iFrekvenciaEva, iUt);
    int iMinIndex = -1, iMin = 99999;
    /*for (int i = 1; i <= n; ++i) {
        cout << iFrekvenciaAdam[i] << ' ';
    }
    cout<<endl;
    for (int i = 1; i <= n; ++i) {
        cout<<iFrekvenciaEva[i]<<' ';
    }*/

    for (int i = 1; i <= n; ++i) {
        if (iFrekvenciaEva[i] < iMin && (iFrekvenciaEva[i] != 0 && iFrekvenciaAdam[i] != 0)) {
            iMin = iFrekvenciaEva[i];
            iMinIndex = i;
        } else if (iFrekvenciaEva[i] == iMin && (iFrekvenciaEva[i] != 0 && iFrekvenciaAdam[i] != 0)) {
            if (iFrekvenciaAdam[i] < iFrekvenciaAdam[iMinIndex])
                iMinIndex = i;

        }
    }
    if (iMinIndex != -1) {
        cout << iMinIndex << ' ' << iFrekvenciaAdam[iMinIndex] - 1 << ' ' << iFrekvenciaAdam[iMinIndex] - 1 << endl;

    }

    iUtAdam[0] = iFrekvenciaAdam[iMinIndex];
    for (int i = iFrekvenciaAdam[iMinIndex] - 1; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
         if(iFrekvenciaAdam[j]==)
        }
    }
    iUtAdam[0] = iFrekvenciaEva[iMinIndex];
    for (int i = iFrekvenciaEva[iMinIndex] - 1; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {

        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << iFrekvenciaAdam[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        cout << iFrekvenciaEva[i] << ' ';
    }
}


