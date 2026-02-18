#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[101];
    cin>>s;

    int uppercase=0,lowercase=0;

    for (int i=0;s[i]!='\0';i++){
        if (isupper(s[i])){
            uppercase++;
        }
        else{
            lowercase++;
        }
    }

    if (uppercase>lowercase){
        for (int j=0;s[j]!='\0';j++ ){
            s[j]=toupper(s[j]);
        }
    }
    else{
        for (int j=0;s[j]!='\0';j++ ){
            s[j]=tolower(s[j]);
        }
    }

    cout<<s<<endl;
    return 0;
}