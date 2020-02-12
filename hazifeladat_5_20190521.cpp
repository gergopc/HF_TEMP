#include <bits/stdc++.h>

#define M 10000

using namespace std;

int n, x, mini, maxi;
bool fr[M];

void beolvas(int &n, bool fr[]){
    ifstream fin("file.in");
    fin>>n;
    fin>>x;
    fr[x]=1;
    maxi=mini=x;
    while(!fin.eof()){
        fin>>x;
        fr[x]=1;
        mini=min(mini, x);
        maxi=max(maxi, x);
    }
}

int feldolgoz(int &n, bool fr[]){
    int db=0;
    for (int i = mini; i <= maxi; ++i) {
        if(fr[i]==1) {
            db++;
            if(db==n)
                return i;
        }
    }
    return -1;
}

int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
   beolvas(n, fr);
   int k=feldolgoz(n, fr);
   if(k==-1)
       cout<<"nu exista";
   else
       cout<<k;
}