#include <bits/stdc++.h>

using namespace std;

struct Diak {
    char *nev;
    int atlag;
};

Diak **osztaly;

int n;

Diak *ujDiak(char strNev[], int iHossz, int iAtlag) {
    Diak *diak = new Diak;
    diak->nev = new char[iHossz];
    strcpy(diak->nev, strNev);
    diak->atlag = iAtlag;

    return diak;
}

void beolvas() {
    int iAtlag, iHossz;
    char strNev[256];
    ifstream fin("file.in");
    fin >> n;
    osztaly = new Diak *[n];
    for (int i = 0; i < n; ++i) {
        fin >> strNev;
        fin >> iAtlag;
        iHossz = strlen(strNev);
        osztaly[i] = ujDiak(strNev, iHossz, iAtlag);
    }

}

int main() {

    beolvas();
    int k;
    cin >> k;
    Diak ***p;
    p = &osztaly;

    for (int i = 0; i < n; ++i) {
        if ((*p)[i]->atlag <= k)
            cout << (*p)[i]->nev << ' ';
    }

}