//complete implementation of deque
//05/09/2020

#include<iostream>
#define m 5

using namespace std;

int arr[m],lleft=-1,rright=-1;

void sel(void);
void rrightin(void);
void lleftin(void);
void rrightout(void);
void lleftout(void);
void display(void);
bool isempty(void);
bool isfull(void);

void sel(void){
    int n;
    cin>>n;
    switch(n){
    case 1:
        rrightin();
        break;
    case 2:
        lleftin();
        break;
    case 3:
        rrightout();
        break;
    case 4:
        lleftout();
        break;
    default:
        cout<<"Invalid Input!"<<endl;
    }
}

bool isempty(){
    if(lleft==rright&&lleft==-1)
        return 1;
    return 0;
}

bool isfull(){
    if(lleft==(rright+1)%m)
        return 1;
    return 0;
}

void rrightin(void){
    int a;
    cout<<"Enter element: "<<endl;
    cin>>a;
    if(isfull()){
        cout<<"Overflow!"<<endl;
        return;
    }else if(isempty()){
        ++lleft;
        arr[++rright]=a;
    }else{
        rright=(rright+1)%m;
        arr[rright]=a;
    }
    display();
    sel();
}

void lleftin(void){
    int a;
    cout<<"Enter element: "<<endl;
    cin>>a;
    if(isfull()){
        cout<<"Overflow!"<<endl;
        return;
    }else if(isempty()){
        ++rright;
        arr[++lleft]=a;
    }else{
        lleft=(lleft-1)%m;
        arr[lleft]=a;
    }
    display();
    sel();
}

void rrightout(void){
    if(isempty()){
        cout<<"Underflow!"<<endl;
        return;
    }else if(lleft==rright&&lleft!=-1){
        cout<<"Element: "<<arr[rright]<<" is deleted from right!"<<endl;
        rright=-1;
        lleft=-1;
    }else{
        cout<<"Element: "<<arr[rright]<<" is deleted from right!"<<endl;
        rright=(rright-1)%m;
    }
    display();
    sel();
}

void lleftout(void){
    if(isempty()){
        cout<<"Underflow!"<<endl;
        return;
    }else if(lleft==rright&&lleft!=-1){
        cout<<"Element: "<<arr[lleft]<<" is deleted from left!"<<endl;
        rright=-1;
        lleft=-1;
    }else{
        cout<<"Element: "<<arr[lleft]<<" is deleted from left!"<<endl;
        lleft=(lleft+1)%m;
    }
    display();
    sel();
}

void display(){
    if(isempty()){
        cout<<"Queue is empty!"<<endl;
        sel();
        return;
    }else{
        int n=(m+rright-lleft)%m;
        int i=lleft;
        cout<<"Queue is: "<<endl;
        cout<<"--------------------------------------"<<endl;
        while(n+1){
            cout<<arr[i]<<"\t";
            i=(i+1)%m;
            --n;
        }
        cout<<"\n--------------------------------------"<<endl;
    }
}



int main(){
    cout<<"Make a selection: "<<endl;
    cout<<"1. Enqueue from right"<<endl;
    cout<<"2. Enqueue from left"<<endl;
    cout<<"3. Dequeue from right"<<endl;
    cout<<"4. Dequeue from left"<<endl;
    sel();

}
