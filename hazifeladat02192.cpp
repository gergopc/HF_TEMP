#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct CD {
    char e_nev[256];
    char lk_nev[256];
    int dalok_szama;
    float ar;
};

CD adatok[200];
int n;

void beolvas() {
    ifstream fin("file.in");

    while (!fin.eof()) {
        fin >> adatok[n].e_nev;
        fin >> adatok[n].dalok_szama;
        fin >> adatok[n].lk_nev;
        fin >> adatok[n++].ar;
    }
}

void b_alpont() {
    char s[256];
    int ls = 0;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (strcmp(adatok[i].e_nev, s) == 0) {
            cout << adatok[i].dalok_szama << '\t' << adatok[i].lk_nev << '\t' << adatok[i].ar << endl;
        }
    }

}

void p_novel() {
        float p;
        char s[256];
        cin>>p>>s;
        p+=100;
        p/=100;
    for (int i = 0; i < n; ++i) {
        if (strcmp(adatok[i].lk_nev, s) == 0) {
           adatok[i].ar*=p;
            cout << adatok[i].e_nev << '\t' << adatok[i].dalok_szama << '\t' << adatok[i].ar << endl;
        }
    }
}

float atlagar(){
    float med=0;
    for (int i = 0; i < n; ++i) {
        med+=adatok[i].ar;
    }
    med/=n;
    return  med;
}

int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    beolvas();
    b_alpont();
    p_novel();
    cout<<atlagar()<<endl;
}