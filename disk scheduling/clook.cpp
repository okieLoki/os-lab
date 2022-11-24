#include<bits/stdc++.h>
using namespace std;

int disk_size = 200;

void look(int arr[], int size, int head){
    int seek_count = 0;
    int distance, current;

    vector<int> left, right;

    for(int i=0; i<size; i++){
        if(arr[i] < head){
            left.push_back(arr[i]);
        }
        if(arr[i] > head){
            right.push_back(arr[i]);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for(int i=0; i<right.size(); i++){
        current = right[i];
        distance = abs(head - right[i]);
        seek_count+= distance;
        head = current;
    }

    seek_count += abs(head - left[0]);
    head = left[0];

    for(int i=0; i<left.size(); i++){
        current = left[i];
        distance = abs(head - left[i]);
        seek_count+= distance;
        head = current;
    }
    
    cout<<seek_count<<endl;
}

int main(){

    int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    look(arr,8,50);
}