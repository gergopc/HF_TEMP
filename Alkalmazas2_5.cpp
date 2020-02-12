#include <bits/stdc++.h>

#define M 50

using namespace std;


long long int iA, iB;

void beolvas(long long int &iA, long long int &iB) {
    cin >> iA >> iB;
}

long long int kulonbseg(long long int iA, long long int iB){
    long long int iKulonbseg=0, iHatvany=1;
    int iEgyikSzamjegy, iMasikSzamjegy, iTovabbmegy=0, iEredmenySzamjegy=0;
    while(iA>0 || iB>0 || iTovabbmegy>0){
        //kimentjuk A es B ket utolso szamjegyet
        iEgyikSzamjegy=iA%10;
        iMasikSzamjegy=iB%10;
        iA/=10;
        iB/=10;
        //kivonjuk egymasbol a ket szamjegyet
        iEredmenySzamjegy=iEgyikSzamjegy-iMasikSzamjegy-iTovabbmegy;
        iTovabbmegy=0;
        //ha az eredmeny kisebb mint egy, feldolgozzuk
        if(iEredmenySzamjegy==-1){
            iEredmenySzamjegy=1;
            iTovabbmegy=1;
        }else if(iEredmenySzamjegy==-2){
            iEredmenySzamjegy=0;
            iTovabbmegy=1;
        }
        iKulonbseg+=iEredmenySzamjegy*iHatvany;
        iHatvany*=10;

    }

    return iKulonbseg;
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(iA, iB);
    cout << kulonbseg(iA, iB);
}

