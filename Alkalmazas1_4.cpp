#include <bits/stdc++.h>
#include <iomanip>

#define M 50

using namespace std;

double dblBinaris;
char strBinaris[256];

void beolvas(double &dblBe) {
    cin >> dblBe;
}

void beolvasKarakterlanc(char strBe[]) {
    cin >> strBe;
}

//szamokkal dolgozik, de a tizedesresz levelasztasanal elromolnak az ertekek
double atalakitBinarisDecimalis(double dblBinaris) {
    double dblDecimalis = 0, dblHatvany = 1;
    double dblBinarisTizedes = dblBinaris - floor(dblBinaris);
    long long int iBinaris;
    //binaris szam egesz reszenek atalakitasa decimalis szamma
    iBinaris = floor(dblBinaris);
    while (iBinaris != 0) {
        dblDecimalis += iBinaris % 10 * dblHatvany;
        dblHatvany *= 2;
        iBinaris /= 10;
    }
    //binaris szam tizedes reszenek atalakitasa decimalis szamma
    dblHatvany = 1;
    while (dblBinarisTizedes) {

    }

    return dblDecimalis;
}
//karakterlancokkal megirva mar jobban mukodik
double atalakitBinarisDecimalisKarakterlanccal(char strBinaris[]) {
    double dblDecimalis = 0;
    char strEgeszresz[256], strTizesdes[256];
    bool bDecimalisPont = false;
    int iInd = 0, iHatvany = 1, iSzamjegy;
    
    //binaris szam egesz es tizedes reszenek kettevalasztasa
    for (int i = 0; strBinaris[i] != '\0'; ++i) {
        if (strBinaris[i] == '.') {
            iInd = 0;
            bDecimalisPont = true;
            strEgeszresz[i] = '\0';
        } else {
            if (!bDecimalisPont)
                strEgeszresz[iInd++] = strBinaris[i];
            else
                strTizesdes[iInd++] = strBinaris[i];
        }
    }
    strTizesdes[iInd] = '\0';
    //egesz resz atalakitasa decimalis szamma
    iInd = strlen(strEgeszresz) - 1;
    while (iInd >= 0) {
        iSzamjegy = strEgeszresz[iInd] - '0';
        dblDecimalis += iSzamjegy * iHatvany;
        iHatvany *= 2;
        iInd--;
    }

    //tizedes resz atalakitasa decimalis szamma
    iHatvany = 2;
    iInd = 0;
    while (strTizesdes[iInd] != '\0') {
        iSzamjegy = strTizesdes[iInd++] - '0';
        dblDecimalis += iSzamjegy * (1.0 / iHatvany);
        iHatvany *= 2;
    }
    //visszaterites
    return dblDecimalis;

}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvasKarakterlanc(strBinaris);
    printf("%.5f", atalakitBinarisDecimalisKarakterlanccal(strBinaris));
}

