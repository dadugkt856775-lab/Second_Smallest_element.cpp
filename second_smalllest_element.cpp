#include<iostream>
using namespace std;
int main(){
    int arr[ ] = {2,4,10,5,7,8,12,3,1};
    int n = sizeof(arr)/4;
    int mn = arr[0];
    for(int i=0; i<=n; i++){
        mn = min(mn,arr[i]);
    }
    int smin = arr[0];
    for(int i=0; i<=n; i++){
        if(arr[i]!=mn) smin = min(smin,arr[i]);
    }
    cout<<smin;
}