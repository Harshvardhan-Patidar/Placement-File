//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    public:
    void func(){
        cout<<"A function"<<<endl;
    }
    void func2(){
        cout<<"A function1"<<endl;
    }
};
class B: public B{
    public:
    void func(){
        cout<<"B function"<<endl;
    }
};
int main(){
    A a;
    B b;
    a.func();
    a.func1();
    b.func();
}