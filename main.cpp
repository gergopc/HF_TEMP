#include <bits/stdc++.h>

using namespace std;

struct Lista {
    int ertek;
    Lista *kovetkezo;
    Lista *elozo;
};

Lista *lista, *lOrszem;

int n;

Lista *ujElem(int x) {
    Lista *lUj = new Lista;
    lUj->ertek = x;
    lUj->kovetkezo = nullptr;
    lUj->elozo = nullptr;
    return lUj;
}

ifstream fin("file.in");

void beszur(Lista *&lista, Lista *&lOrszem, int x) {
    Lista *lUj = ujElem(x);
    Lista *lSeged = lista;
    if (lista == nullptr) {
        lista = lUj;
        lista->kovetkezo = lista;
        lista->elozo = lista;
        lOrszem = lista;
    } else {
        lOrszem->kovetkezo = lUj;
        lUj->elozo = lOrszem;
        lOrszem = lUj;
        lOrszem->kovetkezo = lista;
    }
}

void beolvas() {
    fin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        fin >> x;
        beszur(lista, lOrszem, x);
    }
}

void kiir(Lista *lista) {
    Lista *lSeged = lista;
    do {
        cout << lSeged->ertek << ' ';
        lSeged = lSeged->kovetkezo;
        if (lSeged->elozo == lSeged)
            cout << "Serult mutato ";
    } while (lSeged != lista);
}

bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
    return gen();
}

void elront(Lista *&lista) {
    bool bRandom = randomBool();
    Lista *lSeged = lista;
    do {
        bRandom = randomBool();
        if (bRandom)
            lSeged->elozo = lSeged;
        lSeged = lSeged->kovetkezo;
    } while (lSeged != lista);

}

void megjavit(Lista *&lista) {
    Lista *lSeged1, *lSeged2;
    lista->elozo = nullptr;
    lSeged1 = lista;
    lSeged2 = lista->kovetkezo;
    do {
        lSeged2->elozo = lSeged1;
        lSeged1 = lSeged1->kovetkezo;
        lSeged2 = lSeged2->kovetkezo;

    } while (lSeged1 != lista);
}

int main() {

    beolvas();
    kiir(lista);
    cout << endl;
    elront(lista);
    kiir(lista);
    cout << endl;
    megjavit(lista);
    kiir(lista);
}