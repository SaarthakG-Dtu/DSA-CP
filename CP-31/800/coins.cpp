#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >>t;
    for (int i=0;i<t;i++){
        long long n,k;
        cin>>n>>k;

        if (n==1){
            
        }

        if(n%2==0 || n%k==0 || n%(k+2)==0){
            cout<<"YES"<<endl;
            continue;
        }

        else {
            if ((n%k)%2==0 || (n%2)%k==0){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
    }
    return 0;

}
