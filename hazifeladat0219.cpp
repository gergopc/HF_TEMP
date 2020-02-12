#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct hely{
    char varos[256];
    char megye[256];
    int lakossag;
};

hely adatok[200];
int n;

void beolvas(){
    ifstream fin("ORASE.TXT");
    fin>>n;
    for (int i = 0; i < n;  ++i) {
        fin>>adatok[i].varos;
        fin>>adatok[i].megye;
        fin>>adatok[i].lakossag;
    }
}

void b_alpont(){
    char s[256];
    int ls=0;
    cin>>s;
    for (int i = 0; i < n; ++i) {
        if(strcmp(adatok[i].megye, s)==0){
            cout<<adatok[i].varos<<endl;
            ls+=adatok[i].lakossag;
        }
    }
    cout<<ls<<endl;
}

void rendez(){
    int mini;
    for (int i = 0; i < n-1; ++i) {
        mini=i;
        for (int j = i+1; j < n; ++j) {
            if(strcmp(adatok[j].varos, adatok[mini].varos)==-1)
                mini=j;
        }
        swap(adatok[i], adatok[mini]);
    }
}

void kiirat(){
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<adatok[i].varos<<'\t'<<adatok[i].megye<<'\t'<<adatok[i].lakossag<<endl;
    }
}

int main(){
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    beolvas();
    b_alpont();
    rendez();
    kiirat();
}