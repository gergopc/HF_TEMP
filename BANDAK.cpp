#include <bits/stdc++.h>

#define MAX_CSOMOPONT 100
#define MAX_EL 10001

//#define fin cin

using namespace std;

struct El {
    int honnan, hova;
} Ellista[MAX_EL];

int n, m;
int iBandakDb;
int iMax;

bool bPpm[MAX_CSOMOPONT][MAX_CSOMOPONT];

int iFokszamok[MAX_CSOMOPONT];
int iOsszefuggoKomponensek[MAX_CSOMOPONT];
int iBandak[MAX_CSOMOPONT];
int iBandakLetszam[MAX_CSOMOPONT];

void beolvas() {
    ifstream fin("file.in");
    fin >> n;
    int iKezdopont = -1, iVegpont = -1;
    fin >> iKezdopont >> iVegpont;
    while (iKezdopont != 0 && iVegpont != 0) {
        Ellista[m].honnan = min(iKezdopont, iVegpont);
        Ellista[m].hova = max(iVegpont, iKezdopont);
        m++;
        iFokszamok[iKezdopont]++;
        iFokszamok[iVegpont]++;
        bPpm[iVegpont][iKezdopont] = bPpm[iKezdopont][iVegpont] = 1;
        fin >> iKezdopont >> iVegpont;
    }
}

void meghatarozMaganyosBunozok() {
    for (int i = 1; i <= n; ++i) {
        if (iFokszamok[i] == 0)
            cout << i << ' ';
    }
    cout << endl;
}

void felepitOsszefuggoKomponensek() {

    int iKezdopont, iVegpont;
    for (int i = 1; i <= n; ++i) {
        iOsszefuggoKomponensek[i] = i;
        /*if (iFokszamok[i] == 0)
            iOsszefuggoKomponensek[i] = -1;*/
    }
    for (int i = 1; i <= m; ++i) {
        iKezdopont = Ellista[i].honnan;
        iVegpont = Ellista[i].hova;
        if (iOsszefuggoKomponensek[iVegpont] > iOsszefuggoKomponensek[iKezdopont]) {
            iOsszefuggoKomponensek[iVegpont] = iOsszefuggoKomponensek[iKezdopont];
            for (int j = iVegpont + 1; j <= n; ++j) {
                if (iOsszefuggoKomponensek[j] == iVegpont)
                    iOsszefuggoKomponensek[j] = iKezdopont;
            }
        } else {
            iOsszefuggoKomponensek[iKezdopont] = iOsszefuggoKomponensek[iVegpont];
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        cout<<iOsszefuggoKomponensek[i]<<' ';
    }
cout<<endl;//*/
}

void meghatarozBandakSzama() {
    int iKezdet = 1, iVeg = 0;
    bool bOk;
    for (int i = 1; i <= n; ++i) {
        if (iOsszefuggoKomponensek[i] == iOsszefuggoKomponensek[i + 1]) {
            bOk = 1;
            iVeg = i + 1;
        } else {
            if (bOk == 1) {
                iBandak[iBandakDb] = iOsszefuggoKomponensek[i];
                iBandakLetszam[iOsszefuggoKomponensek[i]] = iVeg - iKezdet + 1;
                iMax = max(iMax, iVeg - iKezdet + 1);
                iKezdet = i + 1;
                iBandakDb++;
                bOk = 0;
            }
        }
    }
    cout << iBandakDb << endl;
}

void meghatarozLegtobbKapcsolat() {
    int iKivalasztottBanda, iMaxKapcsolat = 0;
    for (int i = 0; i < iBandakDb; ++i) {
        iKivalasztottBanda = iBandak[i];
        iMaxKapcsolat = 0;
        for (int j = iKivalasztottBanda; iOsszefuggoKomponensek[j] == iKivalasztottBanda; ++j) {
            if (iFokszamok[j] > iFokszamok[iMaxKapcsolat])
                iMaxKapcsolat = j;
        }
        cout << iMaxKapcsolat << ' ';
    }
    cout << endl;
}

void meghatarozLegnagyobbBandaLetszam() {
    cout << iMax << endl;
}

void meghatarozTotalisanSzervezettBandak() {
    int iKivalasztottBanda, iMaxKapcsolat = 0, iTotalisDb = 0;
    bool bOk = 0;
    for (int i = 0; i < iBandakDb; ++i) {
        iKivalasztottBanda = iBandak[i];
        iMaxKapcsolat = 0;
        bOk = 1;
        for (int j = iKivalasztottBanda; iOsszefuggoKomponensek[j] == iKivalasztottBanda; ++j) {
            int iLetszam = iBandakLetszam[iKivalasztottBanda];
            if (iFokszamok[j] != (iLetszam * (iLetszam - 1)) / 2)
                bOk = 0;
        }
        if (bOk == 1)
            iTotalisDb++;
    }
    cout << iTotalisDb << endl;//*/
}

int main() {
//    freopen("file.in", "r", stdin);
//freopen("file.out", "w", stdout);
    beolvas();
    meghatarozMaganyosBunozok();
    felepitOsszefuggoKomponensek();
    meghatarozBandakSzama();
    meghatarozLegtobbKapcsolat();
    meghatarozLegnagyobbBandaLetszam();
    meghatarozLegtobbKapcsolat();
    meghatarozTotalisanSzervezettBandak();

}