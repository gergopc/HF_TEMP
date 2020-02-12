#include <bits/stdc++.h>

#define M 20

using namespace std;

int mat[M][M];

int main() {
    /*freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);*/
   int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        mat[i][n-1]=n-i;
        mat[0][i]=n;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = n-2; j >= 0; --j) {
            mat[i][j]=mat[i-1][j]+mat[i][j+1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}