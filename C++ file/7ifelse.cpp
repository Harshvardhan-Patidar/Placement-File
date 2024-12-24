//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;

void checkeven(num){
    if(num%2==0){
        cout<<num<<" is Even"<<endl;
    }
    else{
        cout<<num<<" is not Even"<<endl;
    }
}

void checksign(num){
    if(num>0){
        cout<<num<<" is a +ve number"<<endl;
    }
    else if(num<0){
        cout<<num<<" is a -ve number"<<endl;
    }
    else{
        cout<<num<<" is zero"<<endl;
    }
}

int main(){
    int choice,num;
    cout<<"1. Check if even"<<endl;
    cout<<"2. Check the sign"<<endl;
    cout<<"3. Exit"<<endl;

    cout<<"Enter your choice"<<endl;
    cin>>choice<<endl;
    switch(choice){
        case 1:
            cout<<"Enter a Number ";
            cin>>num<<endl;
            checkeven(num);
            break;
        case 2:
            cout<<"Enter a Number ";
            cin>>num<<endl;
            checksign(num);
            break;
        case 3:
        default:
            cout<<"Choose the right option"
            break;
    }
    return 0;
}