//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    int a;
    public:
    void dummy(){
        cout<<"Harsh"<<rndl;
    }
    A(){cout<<"A"<<endl}
    void show(){
        cout<<"A: "<<a<<endl;
    }
    void dummy(float val){
        cout<<val<<endl;
    }
    void dummy(float val1,int val2){
        cout<<val1<<" "<<val2<<endl;
    }
};
class B: public A{
    public:
    B(){cout<<"B"<<endl;}
};
int main(){
    A a;
    a.dummy(10);
    a.dummy(10.2);
    a.dummy(10.2,10);
    return 0;
}