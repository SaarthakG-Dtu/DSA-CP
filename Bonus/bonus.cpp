# include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for (int i=0;i<t;i++){
        int n; cin>>n;
        string s; cin>>s;
        if (s[0] != 'm' && s[0] != 'M'){
            cout<<"No"<<endl;
            continue;
        }
        for (int j=0; j<n; ++j){
            if (s[j] == 'm' || s[j] == 'M'){
                if (s[j+1] =='e' || s[j+1] =='E'|| s[j+1] =='m' || s[j+1] =='M' ){

                    continue;
                }
                else{
                    cout<<"No"<<endl;
                    break;
                }


            }

            if (s[j] == 'e' || s[j] == 'E'){
                if (s[j+1] =='o' || s[j+1] =='O'|| s[j+1] =='e' || s[j+1] =='E' ){

                    continue;
                }
                else{
                    cout<<"No"<<endl;
                    break;
                }


            }

            if (s[j] == 'o' || s[j] == 'O'){
                if (s[j+1] =='o' || s[j+1] =='O'|| s[j+1] =='w' || s[j+1] =='W' ){

                    continue;
                }
                else{
                    cout<<"No"<<endl;
                    break;
                }


            }
            if (s[j] == 'w' or s[j] == 'W'){
                if(j==n-1){
                    cout<<"Yes"<<endl;
                }
                else if (s[j+1] =='w' || s[j+1] =='W' ){

                    continue;
                }
                else{
                    cout<<"No"<<endl;
                    break;
                }


            }

        }



    }
    return 0;

}