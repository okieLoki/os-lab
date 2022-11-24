#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5; // number of process
    int m = 3; // number of resources

    int alloc[n][m] = {{0, 1, 0},
                        {2, 0, 0},
                        {3, 0, 2},
                        {2, 1, 1},
                        {0, 0, 2}};

    int max[n][m] = {{7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2},
                    {4, 3, 3}};

    int avail[m] = {3,3,2};

    int f[n], ans[n], idx = 0;

    for(int i=0; i<n; i++){
        f[i] = 0;
    }
    
    int need[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){

            if(f[i]==0){
                int flag =0;
                for(int j=0; j<m; j++){
                    if(need[i][j]>avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag ==0){
                    ans[idx++] = i;
                    for(int y=0; y<m; y++){
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for(int i=0; i<n; i++){
        if(f[i]==0){
            cout<<"Not safe"<<endl;
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout<<"Safe seq: ";
        for(int i=0; i<n; i++){
            cout<<"P"<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
