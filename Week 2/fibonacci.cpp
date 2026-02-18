// # include <bits/stdc++.h>
// using namespace std;



// int fib(int n){
//     if (n==1){
//         return 0;
//     }
//     else if(n==2){
//         return 1;
//     }
//     else{
//         return fib(n-1)+fib(n-2); 
//     }
    
// }

// int main(){
//     int n;cin>>n;

//     cout<<fib(n);

//     return 0;
// } TIME LIMIT EXCEEDED

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    long long a = 0, b = 1;
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }

    cout << b;
    return 0;
}
