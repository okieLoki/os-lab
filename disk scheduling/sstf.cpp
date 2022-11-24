#include<bits/stdc++.h>
using namespace std;

int minIndex(int arr[], int size){
    int min = 0;
    for(int i=0; i<size; i++){
        if(arr[min] > arr[i]){
            min = i;
        }
    }
    return min;
}

void sstf(int arr[], int size, int head){
    int seek_time = 0;
    int itr = size;
    while(itr--){
        int closest[size];
        for(int i=0; i<size; i++){
            closest[i] = abs(head-arr[i]);
        }
        seek_time+= abs(head - arr[minIndex(closest, size)]);
        head = arr[minIndex(closest, size)];
        arr[minIndex(closest, size)] = INT_MAX;
    }

    cout<<seek_time<<endl;
}

int main(){
    int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    sstf(arr, 8, 50);
}