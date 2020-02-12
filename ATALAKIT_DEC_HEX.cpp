#include <iostream>
#include <cstdio>
#include <cstring>

#define M 202

using namespace std;

int iDecimalis;
char strHexadecimalis[256];

void atalakitDecimalisHexadecimalis(int iDecimalis, char strHexadecimalis[]) {
    int iSzamjegy;
    char cSzamjegy;
    while (iDecimalis > 0) {
        iSzamjegy = iDecimalis % 16;
        if (iSzamjegy < 10)
            cSzamjegy = iSzamjegy + '0';
        else if (iSzamjegy == 10)
            cSzamjegy = 'A';
        else if (iSzamjegy == 11)
            cSzamjegy = 'B';
        else if (iSzamjegy == 12)
            cSzamjegy = 'C';
        else if (iSzamjegy == 13)
            cSzamjegy = 'D';
        else if (iSzamjegy == 14)
            cSzamjegy = 'E';
        else if (iSzamjegy == 15)
            cSzamjegy = 'F';
        iDecimalis /= 16;
        strcpy(strHexadecimalis + 1, strHexadecimalis);
        strHexadecimalis[0] = cSzamjegy;
    }
}

int main() {
    // freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> iDecimalis;
    atalakitDecimalisHexadecimalis(iDecimalis, strHexadecimalis);
    cout << strHexadecimalis;
}