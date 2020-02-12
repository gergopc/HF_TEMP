#include <bits/stdc++.h>

using namespace std;

void kiirBajtok(int n){

    bool bBajt[16];
    for(int i=0; i<16; i++) {
        bBajt[i]=(n&1);
        n >>= 1;
    }

    for (int i = 15; i >= 0; --i) {
      cout<<bBajt[i];
      if(i==8)
          cout<<endl;
    }

}

int main(){
    int a, b;
    cin>>a;
    kiirBajtok(a);
}