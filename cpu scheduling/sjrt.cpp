#include<bits/stdc++.h>
using namespace std;

class SJRT{
    public:
    int pid, at, bt, ct, tat, wt, btcopy;
    bool opr = false;

    void getData(int pid, int at, int bt){
        this->pid = pid;
        this->at = at;
        this->bt = bt;
        this->btcopy = bt;
    }

    void calculate(int time){
        ct = time;
        tat = ct - at;
        wt = tat - btcopy;
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

    SJRT s[5];

    for(int i=0; i<5; i++){
        int at, bt;
        cout<<"Enter at and bt: ";
        cin>>at>>bt;
        s[i].getData(i+1, at, bt);
    }

    int comp =0, curr = 0;

    while(comp != 5){
        int index = -1;
        int min = INT_MAX;
        for(int i=0; i<5; i++){
            if(s[i].at <= curr && !s[i].isComp()){
                if(s[i].bt < min){
                    min = s[i].bt;
                    index = i;
                }
            }
        }

        if(index != -1){
            curr++;
            s[index].bt--;
            if(s[index].bt == 0){
                curr += s[index].bt;
                s[index].calculate(curr);
                comp++;
            }
        }
        else{
            curr++;
        }
    }

    cout<<"pid\tat\tbt\tct\ttat\twt\n";
    for(int i=0; i<5; i++){
        s[i].display();
        cout<<endl;
    }
}