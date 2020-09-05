//complete implementation of deque
//05/09/2020

#include<iostream>
#define m 5

using namespace std;

int arr[m],lleft=-1,rright=-1; //declaring queue named arr and left and right pointers

void sel(void); //function to make selection of functions
void rrightin(void); // function to enqueue an element from right side
void lleftin(void); // function to enqueue an element from left
void rrightout(void); // function to dequeue an element from right
void lleftout(void); // function to dequeue an element from left
void display(void); // function to display the queue
bool isempty(void); // function to check whether the queue is empty
bool isfull(void); // to check whether the queue is full

void sel(void){ //definition of function to make selection
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
    if(lleft==rright&&lleft==-1) //condition of being empty
        return 1;
    return 0;
}

bool isfull(){
    if(lleft==(rright+1)%m) //condition of queue being full
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
        arr[++rright]=a; //incrementing both to enqueue in empty queue
    }else{
        rright=(rright+1)%m; //updating rright to make it go circular 
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
        arr[++lleft]=a;  //incrementing both to enqueue in empty queue
    }else{
        lleft=(lleft-1)%m; //updating lleft value to make it go circular
        arr[lleft]=a;
    }
    display();
    sel();
}

void rrightout(void){
    if(isempty()){
        cout<<"Underflow!"<<endl;
        return;
    }else if(lleft==rright&&lleft!=-1){ //checking the condition of queue having just one element
        cout<<"Element: "<<arr[rright]<<" is deleted from right!"<<endl;
        rright=-1;
        lleft=-1;
    }else{
        cout<<"Element: "<<arr[rright]<<" is deleted from right!"<<endl;
        rright=(rright-1)%m; //updating rright value to delete from right and to make it go circular
    }
    display();
    sel();
}

void lleftout(void){
    if(isempty()){
        cout<<"Underflow!"<<endl;
        return;
    }else if(lleft==rright&&lleft!=-1){ //condition of having single element
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
        int n=(m+rright-lleft)%m; //setting n to total number of elements in the queue
        int i=lleft; //setting i to lleft and queue goes from left to right
        cout<<"Queue is: "<<endl;
        cout<<"--------------------------------------"<<endl;
        while(n+1){
            cout<<arr[i]<<"\t";
            i=(i+1)%m; //updating value of i to make it go circular for n times
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
