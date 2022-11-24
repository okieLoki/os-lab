#include<iostream>
using namespace std;

class fcfs{
    public:

    int pid, at, bt, ct, tat, wt;

    void getData(int pid, int at, int bt){
        this->pid = pid;
        this->at = at;
        this->bt = bt;
    }

    void calculate(int t){
        ct = t + bt;
        tat = ct - at;
        wt = tat - bt;
    }

    void display(){
        cout<<pid<<"\t"<<at<<"\t"<<bt<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt;
    }

};

int main(){

    int size;
    cout<<"Enter no. of processes: ";
    cin>>size;

    fcfs obj[size];

    for(int i=0; i<size; i++){
        int at, bt;
        cout<<"Enter at and bt: ";
        cin>>at>>bt;
        obj[i].getData(i+1, at, bt);
    }

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(obj[j].at > obj[j+1].at){
                swap(obj[j], obj[j+1]);
            }
        }
    }

    int time = 0;

    for(int i=0; i<size; i++){
        if(i==0) time = obj[i].at;
        else{
            time = max(obj[i].at, obj[i-1].ct);
        }
        obj[i].calculate(time);
    }

    cout<<"pid\tat\tbt\tct\ttat\twt\n";
    for(int i=0; i<size; i++){
        obj[i].display();
        cout<<endl;
    }
}