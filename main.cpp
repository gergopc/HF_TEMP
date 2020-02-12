#include <bits/stdc++.h>

using namespace std;

void be(int &n, int &iCsp, char strFa[]) {
    ifstream in("file.in");
    in >> strFa;
}

void direkt(int csp, char strFa[]) {
    cout << "Direkt leszarmazottak: ";

    char strCsp[100];
    char strKeres[100], strKi[100] = "";
    int k = 0, ok = 1, iDb = 0;
    bool bOk = 0;
    itoa(csp, strCsp, 10);

    strcpy(strKeres, strstr(strFa, strCsp));

    for (int i = 0; strKeres[i] != '\0' && ok == 1; i++) {
        if (strKeres[i] == '(') k++;
        if (strKeres[i] == ')') {
            k--;
            if (k == 0)
                ok = 0;
        }
        if (strKeres[i] == ',' && k == 0)
            ok = 0;
        if (k == 1 and strKeres[i] > '0' and strKeres[i] < '9') {
            strKi[iDb++] = strKeres[i];
            strKi[iDb] = '\0';
            bOk = 1;
        } else if (bOk == 1) {
            bOk = 0;
            cout << strKi << ' ';
            iDb = 0;
            strKi[0] = '\0';
        }
    }

    cout << endl;
}

int magassag(char strFa[]) {
    int iBalZarojelek = 0;
    int iMax = 0;

    for (int i = 0; strFa[i] = '\0'; i++) {
        if (strFa[i] == '(') {
            iBalZarojelek++;
            if (iBalZarojelek > iMax) iMax = iBalZarojelek;
        } else if (strFa[i] == ')') {
            iBalZarojelek--;
        }
    }
    return iMax;
}

void osszesLeszarmazott(int iCsp, char strFa[]) {
    cout << "Osszes leszarmazott: ";

    char strCsp[100];
    char strKeres[100], strKi[100] = "";
    int k = 0, ok = 1, iDb = 0;
    bool bOk = 0;
    itoa(iCsp, strCsp, 10);

    strcpy(strKeres, strstr(strFa, strCsp));

    for (int i = 0; strKeres[i] != '\0' && ok == 1; i++) {
        if (strKeres[i] == '(') k++;
        if (strKeres[i] == ')') {
            k--;
            if (k == 0)
                ok = 0;
        }
        if (strKeres[i] == ',' && k == 0)
            ok = 0;
        if (k >= 1 and strKeres[i] > '0' and strKeres[i] < '9') {
            strKi[iDb++] = strKeres[i];
            strKi[iDb] = '\0';
            bOk = 1;
        } else if (bOk == 1) {
            bOk = 0;
            cout << strKi << ' ';
            iDb = 0;
            strKi[0] = '\0';
        }
    }
    cout << endl;

}

void levelek(char strFa[]) {
    cout << "Levelek: ";
    char strKi[256] = "";
    int iHossz = strlen(strFa), iDb = 0;
    bool bOk = 0;
    for (int i = 0; strFa[i] != '\0'; i++) {

        if (strFa[i] > '0' and strFa[i] < '9') {
            strKi[iDb++] = strFa[i];
            strKi[iDb] = '\0';
            bOk = 1;
        } else if (bOk == 1) {
            bOk = 0;
            if (strFa[i] != '(')
                cout << strKi << ' ';
            iDb = 0;
            strKi[0] = '\0';
        }
    }
    cout << endl;
}

void preorder(char strFa[]) {
    char strKi[256];
    int iDb = 0;
    bool bOk = 0;
    cout << "Preorder bejaras: ";
    for (int i = 0; strFa[i] != '\0'; ++i) {
        if (strFa[i] > '0' and strFa[i] < '9') {
            strKi[iDb++] = strFa[i];
            strKi[iDb] = '\0';
            bOk = 1;
        } else if (bOk == 1) {
            bOk = 0;
            cout << strKi << ' ';
            iDb = 0;
            strKi[0] = '\0';
        }
    }
    cout << endl;
}

void kiirSzam(char str[]) {
    for (int i = 0; str[i] >= '0' && str[i] <= '9'; ++i) {
        cout << str[i];
    }
    cout << ' ';
}

/*
void postorder(char strFa[]) {   //BJGY
    bool bZarojel = 0, bVesszo = 0, bOk = 0;
    int iSzint=0;
    //bal
    bOk = 1;
    for (int i = 0; strFa[i] != '\0' && bVesszo == 0 && bOk == 1; i++) {
        if (strFa[i] == '(') {
            postorder(strFa + i + 1);
            bOk = 0;
        } else if (strFa[i] == ',') bVesszo = 1;
    }

    //jobb
    bOk = 1;
    for (int i = 0; strFa[i] != '\0' && bZarojel == 0 && bOk == 1; i++) {
        if (strFa[i] == ',') {
            postorder(strFa + i + 1);
            bOk = 0;
        } else if (strFa[i] == '(') bZarojel = 1;
    }
    //gyoker
    kiirSzam(strFa);
}
*/

void postorder(char strFa[]) {   //BJGY
    bool bZarojel = 0, bOk = 0;
    int iSzint = 0, iBal = -1, iJobb = -1, iVesszo = 0;
    //bal
    bOk = 1;
    for (int i = 0; strFa[i] != '\0' && iSzint >= 0; i++) {
        if (strFa[i] >= '0' && strFa[i] <= '9') {
            if (iVesszo == 0 && iSzint == 1 && iBal == -1 && bOk == 1)
                iBal = i;
            else if (iVesszo == 1 && iSzint == 1 && iJobb == -1 && bOk == 1)
                iJobb = i;
        } else if (strFa[i] == ',') {
            iVesszo = 1;
            if (iSzint == 0)
                bOk = 0;
        } else if (strFa[i] == '(') {
            iSzint++;
        } else if (strFa[i] == ')')
            iSzint--;
    }
    //bal
    if (iBal >= 0)
        postorder(strFa + iBal);
    //jobb
    if (iJobb >= 0)
        postorder(strFa + iJobb);
    //gyoker
    kiirSzam(strFa);
}

void inorder(char strFa[]) {   //BGYJ
    bool bZarojel = 0, bOk = 0;
    int iSzint = 0, iBal = -1, iJobb = -1, iVesszo = 0;
    //bal
    bOk = 1;
    for (int i = 0; strFa[i] != '\0' && iSzint >= 0; i++) {
        if (strFa[i] >= '0' && strFa[i] <= '9') {
            if (iVesszo == 0 && iSzint == 1 && iBal == -1 && bOk == 1)
                iBal = i;
            else if (iVesszo == 1 && iSzint == 1 && iJobb == -1 && bOk == 1)
                iJobb = i;
        } else if (strFa[i] == ',') {
            iVesszo = 1;
            if (iSzint == 0)
                bOk = 0;
        } else if (strFa[i] == '(') {
            iSzint++;
        } else if (strFa[i] == ')')
            iSzint--;
    }
    //bal
    if (iBal >= 0)
        inorder(strFa + iBal);
    //gyoker
    kiirSzam(strFa);
    //jobb
    if (iJobb >= 0) {
        inorder(strFa + iJobb);
    }
}

int main() {
    int n, csp;
    char fa[100];
    be(n, csp, fa);
    cin >> csp;
    direkt(csp, fa);
    //cout<<"Fa magassaga: "<<magassag(fa);
    osszesLeszarmazott(csp, fa);
    levelek(fa);
    preorder(fa);
    cout << "Postorder: ";
    postorder(fa);
    cout << endl;
    cout << "Inorder: ";
    inorder(fa);
}