#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Lista {
    int eh;
    int fsz;
    Lista *kovetkezo;
};

Lista *f1, *f2, *lOrszem1, *lOrszem2, *lOsszeg, *lSzorzat;

int n, m;

Lista *ujElem(int eh, int fsz) {
    Lista *lUj = new Lista;
    lUj->eh = eh;
    lUj->kovetkezo = nullptr;
    lUj->fsz = fsz;
    return lUj;
}

ifstream finPOL1("POL1.TXT");
ifstream finPOL2("POL2.TXT");
ofstream foutPOL("POL.TXT");

void beszur(Lista *&lista, Lista *&lOrszem, int eh, int fsz) {
    if (lista == nullptr) {
        lista = ujElem(eh, fsz);
        lOrszem = lista;
    } else {
        lOrszem->kovetkezo = ujElem(eh, fsz);
        lOrszem = lOrszem->kovetkezo;
    }
}

void beszur(Lista *&lista, Lista *&lOrszem, int x) {
    Lista *lUj = ujElem(0, x);
    if (lista == nullptr) {
        lista = lUj;
        lOrszem = lista;
    } else {
        lOrszem->kovetkezo = lUj;
        lOrszem = lUj;
    }
}

void beszurOsszead(Lista *&lista, Lista *&lOrszem, int eh, int fsz) {


    if (lista == nullptr)
        beszur(lista, lOrszem, eh, fsz);
    else {
        Lista *lElotte = new Lista;
        lElotte->kovetkezo = lista;
        Lista *lUtana = lista;

        while (lUtana != nullptr && lUtana->fsz >= fsz) {
            lElotte = lElotte->kovetkezo;
            lUtana = lUtana->kovetkezo;
        }

        if (lElotte->fsz == fsz) {
            lElotte->eh += eh;
        } else {
            Lista *lUj = ujElem(eh, fsz);
            lElotte->kovetkezo = lUj;
            lUj->kovetkezo = lUtana;
            if (lUtana == lista)
                lista = lUj;
        }


    }
}

void beolvas(Lista *&lista, Lista *&lOrszem, ifstream &fin) {
    int x;
    Lista *lSeged2 = nullptr;
    Lista *lSeged = nullptr;
    Lista *lOrszemSeged;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> x;
        beszur(lSeged, lOrszemSeged, x);
    }
    lSeged2 = lSeged;
    for (int i = 0; i < n; ++i) {
        fin >> x;
        lSeged2->eh = x;
        lSeged2 = lSeged2->kovetkezo;
    }
    lSeged2 = lSeged;
    while (lSeged2 != nullptr) {
        beszurOsszead(lista, lOrszem, lSeged2->eh, lSeged2->fsz);
        lSeged2 = lSeged2->kovetkezo;
    }

}


Lista *osszead(Lista *f1, Lista *f2) {
    //int iLegnagyobbFok = 0;
    int iEh, iFok;
    Lista *lOsszeg = nullptr;
    Lista *lOsszegOrszem = nullptr;
    Lista *lSeged1 = f1;
    Lista *lSeged2 = f2;
    if (f1 == nullptr)
        return f2;
    else if (f2 == nullptr)
        return f1;
    while (lSeged1 != nullptr && lSeged2 != nullptr) {
        if (lSeged1->fsz > lSeged2->fsz) {
            beszur(lOsszeg, lOsszegOrszem, lSeged1->eh, lSeged1->fsz);
            lSeged1 = lSeged1->kovetkezo;
        } else if (lSeged2->fsz > lSeged1->fsz) {
            beszur(lOsszeg, lOsszegOrszem, lSeged2->eh, lSeged2->fsz);
            lSeged2 = lSeged2->kovetkezo;
        } else {
            beszur(lOsszeg, lOsszegOrszem, lSeged2->eh + lSeged1->eh, lSeged2->fsz);
            lSeged2 = lSeged2->kovetkezo;
            lSeged1 = lSeged1->kovetkezo;
        }
    }
    while (lSeged1 != nullptr) {
        beszur(lOsszeg, lOsszegOrszem, lSeged1->eh, lSeged1->fsz);
        lSeged1 = lSeged1->kovetkezo;
    }
    while (lSeged2 != nullptr) {
        beszur(lOsszeg, lOsszegOrszem, lSeged2->eh, lSeged2->fsz);
        lSeged2 = lSeged2->kovetkezo;
    }
    return lOsszeg;
}

void kiirat(Lista *lista) {
    Lista *lSeged = lista;
    while (lSeged != nullptr) {
        foutPOL << lSeged->fsz << ' ';
        lSeged = lSeged->kovetkezo;
    }
    foutPOL << endl;
    lSeged = lista;
    while (lSeged != nullptr) {
        foutPOL << lSeged->eh << ' ';
        lSeged = lSeged->kovetkezo;
    }
    foutPOL << endl;
}

Lista *szoroz(Lista *f1, Lista *f2) {
    Lista *lSzorzat = nullptr, *lSzorzatOrszem = nullptr;
    Lista *lSeged1 = f1;
    Lista *lSeged2 = f2;
    while (lSeged1 != nullptr) {
        lSeged2 = f2;
        while (lSeged2 != nullptr) {
            if (lSeged2->eh * lSeged1->eh != 0) {
                beszurOsszead(lSzorzat, lSzorzatOrszem, lSeged2->eh * lSeged1->eh, lSeged2->fsz + lSeged1->fsz);
            }
            lSeged2 = lSeged2->kovetkezo;
        }
        lSeged1 = lSeged1->kovetkezo;
    }

    return lSzorzat;
}

int main() {
    beolvas(f1, lOrszem1, finPOL1);
    beolvas(f2, lOrszem2, finPOL2);
    lOsszeg = osszead(f1, f2);
    lSzorzat = szoroz(f1, f2);
    kiirat(lOsszeg);
    kiirat(lSzorzat);
}