#include <bits/stdc++.h>

using namespace std;

struct ember {
    char nev[30];
    int eletkor;
};

ember embereim[201];
int n;

void javit_nev(char s[]) {
    strlwr(s);
    s[0] -= 'a' - 'A';
    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i - 1] == ' ' && s[i] != ' ')
            s[i] -= 'a' - 'A';
    }

}

void torol_szokoz(char s[]) {
    int i, k, v;
    for (i = 0; s[i] == ' '; i++);
    strcpy(s, s + i);
    for (i = 1; s[i] != '\0'; ++i) {
        if (s[i - 1] != ' ' && s[i] == ' ')
            k = i;
        else if (s[i - 1] == ' ' && s[i] != ' ') {
            v = i;
            strcpy(s + k + 1, s + v);
        }
    }
    for (i = strlen(s) - 1; s[i] == ' '; --i)
        s[i] = '\0';

}

void beolvas(int &n, ember emberek[]) {
    ifstream fin("file.in");
    while (!fin.eof()) {
        fin.getline(emberek[n].nev, 30);
        torol_szokoz(emberek[n].nev);
        javit_nev(emberek[n].nev);
        fin >> emberek[n].eletkor;
        fin.ignore();
        n++;
    }
    n--;
}

void rendez_nev(int n, ember *emberek) {
    int mini;
    for (int i = 0; i < n - 1; ++i) {
        mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(emberek[j].nev, emberek[mini].nev) == -1) {
                mini = j;
            }
        }
        swap(emberek[i], emberek[mini]);
    }
}

void rendez_eletkor(int n, ember *emberek) {
    int mini;
    for (int i = 0; i < n - 1; ++i) {
        mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (emberek[j].eletkor<emberek[mini].eletkor) {
                mini = j;
            }
        }
        swap(emberek[i], emberek[mini]);
    }
}

void torol_azonos(int &n, ember emberek[]) {
    int i = 1;
    while (i < n) {
        if (strcmp(emberek[i].nev, emberek[i - 1].nev) == 0) {
            for (int j = i; j < n - 1; ++j) {
                strcpy(emberek[j].nev, emberek[j + 1].nev);
                emberek[j].eletkor = emberek[j + 1].eletkor;
            }
            i--;
            n--;
        }
        i++;
    }


}

void kiir(int n, ember emberek[]) {
    for (int i = 0; i < n; ++i) {
        cout << emberek[i].nev << endl;
    }

}

int adott_eletkor(int n, ember emberek[], int k) {
    int db = 0;
    for (int i = 0; i < n; ++i) {
        if (emberek[i].eletkor == k)
            db++;
    }
    return db;
}

void kiir_korcsoport(int n, ember emberek[]){
    cout<<emberek[0].eletkor<<':'<<endl;
    cout<<emberek[0].nev<<endl;
    for (int i = 1; i < n; ++i) {
        if(emberek[i-1].eletkor!=emberek[i].eletkor)
            cout<<emberek[i].eletkor<<':'<<endl;
        cout<<emberek[i].nev<<endl;
    }
}

int legnepesebb_eletkor(int n, ember emberek[], int &fk, int &fv){
    int maxi=0, meletkor, k=0, v;
    
    for (int i = 1; i < n; ++i) {
        if(emberek[i-1].eletkor!=emberek[i].eletkor){
            v=i-1;
            if(v-k>maxi){
                maxi=v-k;
                meletkor=emberek[i-1].eletkor;
                fk=k;
                fv=v;
            }
            k=i;
        }
    }
    return meletkor;
}

void kiir_legnepesebb_csoport(ember emberek[], int k, int v){
    for (int i = k; i <= v; ++i) {
        cout<<emberek[i].nev<<endl;
    }
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(n, embereim);
    rendez_nev(n, embereim);
    torol_azonos(n, embereim);
    kiir(n, embereim);
    int k, v;
    cin >> k;
    cout << adott_eletkor(n, embereim, k)<<endl;
    rendez_eletkor(n, embereim);
    kiir_korcsoport(n, embereim);
    cout<<legnepesebb_eletkor(n, embereim, k, v)<<endl;
    kiir_legnepesebb_csoport(embereim, k, v);
}