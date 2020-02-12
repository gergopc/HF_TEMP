#include <bits/stdc++.h>
#include <iomanip>

#define M 50

using namespace std;

double dblDecimalis;

void beolvas(double &dblBe) {
    cin >> dblBe;
}

double atalakitDecimalisBinaris(double dblDecimalis) {
    double dblHatvany = 1, dblBinaris = 0;

    int iEgeszresz = floor(dblDecimalis);
    double dblTizedesresz = dblDecimalis - floor(dblDecimalis);

    //egesz resz atalakitasa binaris szamrendszerbe
    while (iEgeszresz) {
        dblBinaris += iEgeszresz % 2 * dblHatvany;
        dblHatvany *= 10;
        iEgeszresz /= 2;
    }

        //tizedes resz atalakitasa binaris szamrendszerbe
        dblHatvany = 1;
        while(dblTizedesresz!=floor(dblTizedesresz)){
            dblHatvany*=10;
            dblTizedesresz*=2;
            dblBinaris+=floor(dblTizedesresz)*(1/dblHatvany);
        }

        return dblBinaris;

}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    beolvas(dblDecimalis);
    printf("%.5f",atalakitDecimalisBinaris(dblDecimalis));
}

