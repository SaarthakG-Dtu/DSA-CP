#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;cin>>n>>t;
    char q[n];

    cin>>q;

    for (int j=0;j<t;j++){
        for (int k=0;k<n-1;k++){
            if (q[k]=='B'&&q[k+1]=='G'){
                swap(q[k],q[k+1]);
                k++;
            }
        }
    }

    // for (int i=0;i<n;i++){
    //     cout<<q[i];
    // }
    // cout<<endl;
    cout<<q<<endl;
    
    return 0;
}