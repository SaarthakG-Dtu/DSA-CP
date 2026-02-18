#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    int n ;
    for (int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for (int j=0;j<n;j++){
            cin>>arr[j];
        }

        int ones=0;
        int zeros=0;

        for (int j=0;j<n;j++){
            if (arr[j]%2 != j%2){
                if (arr[j]%2==0){
                    zeros++;
                }
                else{
                    ones++;
                }
            }

        }

        if (zeros==ones){
            cout<<zeros<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;    
}