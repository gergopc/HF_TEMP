#include <bits/stdc++.h>

#define M 20

using namespace std;

int mat[M][M];

int ranguri(int n){
    int db=0;
    for (int i = 0; n>0; ++i) {
        if(n%10==i)
            db++;
        n/=10;
    }
    return db;
}

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
    cout<<ranguri(6594270);
}