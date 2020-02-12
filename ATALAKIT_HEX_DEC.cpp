#include <iostream>
#include <cstdio>
#include <cstring>

#define M 202

using namespace std;

int iDecimalis;
char strHexadecimalis[256];

void atalakitHexadecimalisDecimalis(int &iDecimalis, char strHexadecimalis[]) {
    int iSzamjegy;
    char cSzamjegy;
    iDecimalis = 0;
    for (int i = 0; i < strHexadecimalis[i] != '\0'; ++i) {
        cSzamjegy = strHexadecimalis[strlen(strHexadecimalis) - 1 - i];
        if (cSzamjegy >= '0' && cSzamjegy <= '9') {
            iSzamjegy = cSzamjegy - '0';
            iDecimalis += (1 << (4 * i)) * iSzamjegy;
        } else if (cSzamjegy >= 'A' && cSzamjegy <= 'F') {
            iSzamjegy = cSzamjegy - 'A' + 10;
            iDecimalis += (1 << (4 * i)) * iSzamjegy;
        }

    }

}

int main() {
    // freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> strHexadecimalis;
    atalakitHexadecimalisDecimalis(iDecimalis, strHexadecimalis);
    cout << iDecimalis;
}