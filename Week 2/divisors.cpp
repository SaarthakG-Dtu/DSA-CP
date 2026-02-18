#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;

    if (n==1){
        cout<<"NO"<<endl;
        return 0;
    }
    else if (n==2){
        cout<<"YES"<<endl;
        return 0;
    }

    else{ 

        for (int i=2;i<=n;++i){
            if (i==n){
                cout<<"YES"<<endl;
            }
            else if (n%i==0){
                cout<<"NO"<<endl;
                break;
            }
            else{
                continue;
            }
            
        }
    }
    return 0;

}