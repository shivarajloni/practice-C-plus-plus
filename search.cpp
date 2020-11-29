#include<iostream>

using namespace std;

int firstoccr(int arr[], int n, int i, int key) {
    
    if(i==n) {
        return -1;
    }
    
    if(arr[i]==key) {
        return i;
    }
    return firstoccr(arr, n, i+1, key);
}

int lastoccr(int arr[], int n, int i, int key) {
    if(i==n) {
        return -1;
    }
    int restArray = lastoccr(arr, n, i+1, key);
    if(restArray!=-1) {
        return restArray;
    }
    if(arr[i]==key) {
        return i;
    }
    return -1;
}
int main() {
    int arr[]={4,2,1,2,5,2,7};
    cout<<firstoccr(arr,7,0,2)<<endl;
    cout<<lastoccr(arr,7,0,2)<<endl;

    return 0;
}