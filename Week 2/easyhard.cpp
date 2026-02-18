#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    int ones=0;

    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int j =0; j<n;j++){
        if (a[j] == 1){
            ones++;
        }
    }

    if (ones>0){
        cout<<"Hard";
    }
    else{
        cout<<"Easy";
    }


}