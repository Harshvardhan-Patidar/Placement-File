//                      ********* !!  BY HARSH PATIDAR  !! ********

#include<iostream>
using namespace std;
//Use of friend class
class A{
    int a;
    public:
    A(){
        a=0;
    }
    A(int a):a(a){}
    void modifyA(){
        a+=21;
    }
    void show(){
        cout<<"A: "<<a<<endl;
    }

    friend class B;
};

class B{
    int b;
    public:
    B(){
        b=0;
    }
    B(int b):b(b){}
    void modifyB(){
        b+=10;
    }
    void modifyusingB(A &obj){
        cout<<"A using B: "<<obj.a<<endl;
        obj.a+=100;
    }
    void createAndmodifyNewA(){
        A obj(21);
        obj.show();
        cout<<obj.a<<endl;
    }
};

//use of friend funtion
class C,class D{
    public:
    void dIncreamentC(C &obj);
}

class C{
    int c;
    public:
    C():c(0){}
    C(int c):c(c){}
    void show(){
        cout<<c<<endl;
    }
    friend void increment(C &obj);
    friend void D:dIncreamentC(C &obj);
};
void increment(C &obj){
    cout<<obj.c+10<<endl;
}

void D:dIncreamentC(C &obj){
    obj.c+=100;
}

int main(){
    A obj(10);
    B obj2(11);
    obj.show()
    obj2.modifyusingB(obj);
    obj2.show()
}