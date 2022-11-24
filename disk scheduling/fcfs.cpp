#include<bits/stdc++.h>
using namespace std;

void fcfs(vector<int> arr, int head){
    int seek_time = 0;
    int current, distance;

    for(int i=0; i<arr.size(); i++){
        current = arr[i];
        distance = abs(head - current);
        seek_time = seek_time + distance;
        head = current;
    }

    cout<<"Seek time is: "<<seek_time<<endl;
}

int main(){

    vector<int> arr = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    fcfs(arr,head);

}