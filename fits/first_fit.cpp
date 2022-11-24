#include<bits/stdc++.h>
using namespace std;

void firstFit(vector<int> pSize, vector<int> bSize){
    int alloc[pSize.size()];
    memset(alloc, -1, sizeof(alloc));

    int temp[bSize.size()];
    for(int i=0; i<bSize.size(); i++){
        temp[i] = bSize[i]; 
    }

    for(int i=0; i<pSize.size(); i++){
        for(int j=0; j<bSize.size(); j++){
            if(bSize[j] >= pSize[i]){
                alloc[i] = j;
                bSize[j] = bSize[j] - pSize[i];
                break;
            }
        }
    }

    cout<<"PNo.\tPSize\tBNo\n";

    for(int i=0; i<pSize.size(); i++){
        cout<<i+1<<"\t"<<pSize[i]<<"\t";
        if(alloc[i]!=-1){
            cout<<alloc[i] + 1;
        }
        else{
            cout<<"Not allocated";
        }
        cout<<endl;
    }

    cout<<"\nBNo\tSize\tUsed\tleft\n";

    for(int i=0; i<bSize.size(); i++){
        cout<<i+1<<"\t"<<temp[i]<<"\t"<<abs(temp[i]-bSize[i])<<"\t"<<bSize[i];
        cout<<endl;
        
    }
}

int main(){

    vector<int> pSize = {100,10,35,15,23,6,25,55,88,100};
    vector<int> bSize = {50,200,70,115,15};

    firstFit(pSize, bSize);
}