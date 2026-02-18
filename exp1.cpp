#include <iostream>
using namespace std;

int linearsearch(int arr[],int n, int key){
    for (int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[],int n, int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(high-low)/2+low;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main() { 
    int n, key, result;
    cout << "Enter number of elements:"; cin >> n; 
    int arr[n]; 
    cout << "Enter elements:"; 
    for(int i = 0; i < n; i++)
    cin >> arr[i];     
    cout << "Enter element to search:"; cin >> key; 

    result = linearsearch(arr, n, key); 
    if(result != -1){
        cout << "Element found at position " << result + 1 << " using Linear Search" <<endl; 
    } 
    else {
        cout << "Element not found using Linear Search" << endl; 
    }
    

    result = binarysearch(arr, n, key); 
    if(result != -1){
        cout << "Element found at position " << result + 1 << " using Binary Search" <<endl;
    } 
    else {
        cout << "Element not found using Binary Search" << endl;
    }
    
return 0; 
} 