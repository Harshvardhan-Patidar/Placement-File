//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    public:
    virtual void func1(){
        cout<<"A class function"<<endl;
    }
};
class B: public A{
    public:
    void func1(){
        cout<<"B class function"<<endl;
    }
};
int main(){
    A *ptr;
    B b;
    ptr = &b;
    ptr->func1();
    return 0;
}