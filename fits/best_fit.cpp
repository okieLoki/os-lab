#include<bits/stdc++.h>
using namespace std;

void bestFit(vector<int> p, vector<int> b){
    int alloc[p.size()];
    memset(alloc, -1, sizeof(alloc));

    int temp[b.size()];
    for(int i=0; i<b.size(); i++){
        temp[i] = b[i]; 
    }

    for(int i=0; i<p.size(); i++){
        int bestIndex = -1;
        for(int j=0; j<b.size(); j++){
            if(b[j] >= p[i]){
                if(bestIndex == -1){
                    bestIndex = j;
                }
                else if(b[bestIndex] > b[j]){
                    bestIndex = j;
                }
            }
        }
        if(bestIndex != -1){
            alloc[i] = bestIndex;
            b[bestIndex]-=p[i];
        }
    }
    cout<<"PNo.\tPSize\tBNo\n";

    for(int i=0; i<p.size(); i++){
        cout<<i+1<<"\t"<<p[i]<<"\t";
        if(alloc[i]!=-1){
            cout<<alloc[i] + 1;
        }
        else{
            cout<<"Not allocated";
        }
        cout<<endl;
    }

    cout<<"\nBNo\tSize\tUsed\tleft\n";

    for(int i=0; i<b.size(); i++){
        cout<<i+1<<"\t"<<temp[i]<<"\t"<<abs(temp[i]-b[i])<<"\t"<<b[i];
        cout<<endl;
        
    }
}

int main(){

    vector<int> pSize = {212, 417, 112, 426};
    vector<int> bSize = {100, 500, 200, 300, 600};

    bestFit(pSize, bSize);
}