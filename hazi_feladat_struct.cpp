#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct{
    int aru_kod, mennyiseg;
    char aru_neve[256];
    float egyseg_ar;
} termek;

termek aru[102];

int n;

void beolvas(termek tr[], int &n){
    ifstream fin("file.in");
        fin>>n;
    for (int i = 0; i < n; ++i) {
      fin>>tr[i].aru_kod;
        fin>>tr[i].aru_neve;
        fin>>tr[i].egyseg_ar>>tr[i].mennyiseg;
    }
}

void ellenoriz(termek tr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(tr[i].aru_kod==tr[j].aru_kod)
                tr[j].aru_kod++;
        }
    }
}

void rendez(termek tr[], int n){
    int mini;
    for (int i = 0; i < n-1; ++i) {
        mini=i;
        for (int j = i+1; j < n; ++j) {
            if(tr[j].aru_kod<tr[i].aru_kod)
                mini=j;
        }
        swap(tr[mini], tr[i]);
    }
}

void kiirat(termek tr[], int n){
    printf("Kod   Nev   Egyseg Ar   Mennyiseg\n");
    for (int i = 0; i < n; ++i) {
        printf("%d   %s   %f   %d\n", tr[i].aru_kod, tr[i].aru_neve, tr[i].egyseg_ar, tr[i].mennyiseg);
    }
}

void kiir_legdragabb_termek(termek tr[], int n){
    int mi=0;
    for (int i = 0; i < n; ++i) {
        if(tr[i].egyseg_ar>tr[mi].egyseg_ar)
            mi=i;
    }
    printf("%s\n", tr[mi].aru_neve);
}

void kiir_mennyiseg_termek_kod(termek tr[], int n, int k){
    for (int i = 0; i < n; ++i) {
        if(tr[i].mennyiseg==k)
            printf("%d\n", tr[i].aru_kod);
    }
}
void kiir_mennyiseg_termek_adat(termek tr[], int n, int k){
    for (int i = 0; i < n; ++i) {
        if(tr[i].mennyiseg<k)
            printf("%d   %s   %f   %d\n", tr[i].aru_kod, tr[i].aru_neve, tr[i].egyseg_ar, tr[i].mennyiseg);
    }
}

void kiir_aru_osszertek(termek tr[], int n, int a, int b){
    float s=0;
    for (int i = 0; i < n; ++i) {
        if(tr[i].aru_kod>=a && tr[i].aru_kod<=b)
            s+=tr[i].egyseg_ar*tr[i].mennyiseg;
    }
    printf("%f\n", s);
}

int main() {
    int k, a, b;
    //freopen("file.in", "r", stdin);
    // freopen("comori.out", "w", stdout);
    beolvas(aru, n);
    ellenoriz(aru, n);
    rendez(aru, n);
    kiirat(aru, n);
    kiir_legdragabb_termek(aru, n);
    cin>>k;
    kiir_mennyiseg_termek_kod(aru, n, k);
    cin>>k;
    kiir_mennyiseg_termek_adat(aru, n, k);
    cin>>a>>b;
    kiir_aru_osszertek(aru, n, a, b);
}
