#include<bits/stdc++.h>
using namespace std;

int disk_size = 200;

void scan(int arr[], int size, int head, string direction){
    int seek_count = 0;
    int distance, current;

    vector<int> left, right;

    if(direction=="left"){
        left.push_back(0);
    }
    else if(direction == "right"){
        right.push_back(disk_size-1);
    }

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

    int run = 2;
    while(run--){
        if(direction == "left"){
            for(int i= left.size()-1; i>=0; i--){
                current = left[i];
                distance = abs(head - left[i]);
                seek_count+= distance;
                head = current;
            }
            direction = "right";
        }
        else if(direction == "right"){
            for(int i=0; i<right.size(); i++){
                current = right[i];
                distance = abs(head - right[i]);
                seek_count+= distance;
                head = current;
            }
            direction = "left";            
        }
    }

    cout<<seek_count<<endl;
}

int main(){

    int arr[8] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    scan(arr,8,50,"left");
    scan(arr,8,50,"right");
}