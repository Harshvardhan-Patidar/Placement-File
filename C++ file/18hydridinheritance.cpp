//                      ********* !!  BY HARSH PATIDAR  !! ********

// in this code we resolve the ambiguty problem
// we can also solve it with the help of "virtual" keyword
#include <iostream>
using namespace std;
class A{
    public:
    int a;
    A(){cout<<"A"<<endl;}
    void show(){
        cout<<"a: "<<a<<endl;
    }
};
class B: public A{
    public:
    B(){cout<<"B"<<endl;}
};
class C: public A{
    public:
    C(){cout<<"C"<<endl}
};
class D: public B,public C{
    public:
    void sample(){
        B::show();
        C::show();
        cout<<B::a<<endl;
        cout<<C::a<<endl;
    }
    D(){cout<<"D"<<endl;}
};
int main(){
    D d;
    d.sample();
    return 0;
}