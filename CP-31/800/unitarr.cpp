# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;

    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int pos=0,neg=0;

        for(int j=0;j<n;j++){
            if(arr[j]==-1){
                neg++;
            }
            else{
                pos++;
            }
        }

        if(pos>=neg && neg%2==0){
            cout<<0<<endl;  
            continue;          
        }

        int count=0;

        while(pos-neg<0 || neg%2!=0){
            if(pos-neg<0){
                pos++;
                neg--;
                count++;
            }
            else{
                neg--;
                count++;
            }

        }
        cout<<count<<endl;
    }
    return 0;
}