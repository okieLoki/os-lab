#include<bits/stdc++.h>
using namespace std;

class sjf{
    public:
    int pid, at, bt, ct, tat, wt;
    bool opr = false;

    void getData(int pid, int at, int bt){
        this->pid = pid;
        this->at = at;
        this->bt = bt;
    }

    void calculate(int time){
        ct = time;
        tat = ct - at;
        wt = tat - bt;
        opr = true;
    }

    bool isComp(){
        return opr;
    }

    void display(){
        cout<<pid<<"\t"<<at<<"\t"<<bt<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt;
    }
};

int main(){

    sjf s[5];

    for(int i=0; i<5; i++){
        int at, bt;
        cout<<"Enter at and bt: ";
        cin>>at>>bt;
        s[i].getData(i+1,at,bt);
    }

    int comp = 0, cur = 0;

    while(comp!=5){
        int index = -1;
        int min = INT_MAX;

        for(int i=0; i<5; i++){
            if(s[i].at <= cur && !s[i].isComp()){
                if(s[i].bt < min){
                    min = s[i].bt;
                    index = i;
                }
            }
        }

        if(index != -1){
            cur = cur + s[index].bt;
            s[index].calculate(cur);
            comp++;
        }
        else{
            cur++;
        }
    }

    cout<<"pid\tat\tbt\tct\ttat\twt\n";
    for(int i=0; i<5; i++){
        s[i].display();
        cout<<endl;
    }

}