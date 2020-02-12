#include <bits/stdc++.h>

#define MAX_CSOMOPONT 10001
#define MAX_EL 100001
#define fIn cin

using namespace std;

struct El {
    int honnan, hova;
};
El ellista[MAX_EL];

int n, m;

int iBaratok[MAX_CSOMOPONT];

void beolvas(int &n, int &m, El ellista[]) {
    //  ifstream fIn("file.in");
    fIn >> n >> m;
    for (int i = 0; i < m; ++i) {
        fIn >> ellista[i].honnan >> ellista[i].hova;

    }
}

void elokeszitBaratok(int iBaratok[], int n) {
    for (int i = 0; i < n; ++i) {
        iBaratok[i] = i;
    }
}

void feldolgozTarsasagok(int n, int m, int iBaratok[], El ellista[]){
    for (int i = 0; i < m; ++i) {
        iBaratok[ellista[i].hova]=iBaratok[ellista[i].honnan];
        for (int j = i+1; j < n; ++j) {
            if(iBaratok[j]==iBaratok[ellista[i].hova])
                iBaratok[j]=iBaratok[ellista[i].honnan];
        }
    }
}

void kiolvasTarsasagok(int n, int iBaratok[]){

}

int main() {
    beolvas(n, m, ellista);
    elokeszitBaratok(iBaratok, n);
    feldolgozTarsasagok(n, m, iBaratok, ellista);
    kiolvasTarsasagok(n, iBaratok);
}

