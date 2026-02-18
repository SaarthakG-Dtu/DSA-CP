#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;int k;
        cin>>n>>k;

        string s,m;
        int count=1;
        for(int j=0;j<n;j++){
            if (j==0){
                cin>>s;
            }
            else{
                cin>>m;
                if (m==s){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}