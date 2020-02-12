#include <bits/stdc++.h>

#define M 50

using namespace std;


long long int iA, iB;

void beolvas(long long int &iA, long long int &iB) {
    cin >> iA >> iB;
}

long long int osszeg(long long int iA, long long int iB){
    long long int iOsszeg=0, iHatvany=1;
    int iEgyikSzamjegy, iMasikSzamjegy, iTovabbmegy=0, iEredmenySzamjegy=0;
    while(iA>0 || iB>0 || iTovabbmegy>0){
        //kimentjuk A es B ket utolso szamjegyet
        iEgyikSzamjegy=iA%10;
        iMasikSzamjegy=iB%10;
        iA/=10;
        iB/=10;
        //osszeadjuk a ket szamjegyet
        iEredmenySzamjegy=iEgyikSzamjegy+iMasikSzamjegy+iTovabbmegy;
        iTovabbmegy=0;
        //ha az eredmeny tulhaladja az egyet, feldolgozzuk
        if(iEredmenySzamjegy==2){
            iEredmenySzamjegy=0;
            iTovabbmegy=1;
        }else if(iEredmenySzamjegy==3){
            iEredmenySzamjegy=1;
            iTovabbmegy=1;
        }
        iOsszeg+=iEredmenySzamjegy*iHatvany;
        iHatvany*=10;

    }

    return iOsszeg;
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(iA, iB);
    cout << osszeg(iA, iB);
}

