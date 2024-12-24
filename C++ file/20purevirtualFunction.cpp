//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    public:
    virtual void func()=0;
    virtual void func1()=0;
    virtual void func2()=0;
};
class B: public A{
    public:
    void func(){
        cout<<"B class function"<<endl;
    }
    void func1(){
        cout<<"Hello"<<endl;
    }
};
class C: public B{
    public:
    void func2(){
        cout<<"C class function"<<endl;
    }
};
int main(){
    A a;
    B b;
    C c;
    return 0;
}