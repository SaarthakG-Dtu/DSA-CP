#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;

    cin >>a>>b>>c;

    if (a >= b){
        if (b>=c){
            cout<<c<<' '<<a;
        }
        else{
            if (a>=c){
                cout<<b<<' '<<a;
            }
            else{
                cout<<b<<' '<<c;
            }
            
        }
    }
    else {
        if (a>=c){
            cout<<c<<' '<<b;
        }
        else{
            if (b>=c){
                cout<<a<<' '<<b;
            }
            else{
                cout<<a<<' '<<c;
            }          
        }
    }

    return 0;
}


