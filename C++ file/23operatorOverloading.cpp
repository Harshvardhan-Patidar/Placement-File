//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    int a;
    public:
    A(){}
    void show(){
        cout<<"A: "<<a<<endl;
    }
    void setA(int a){
        this->a=a;
    }
    A operator-(A const &obj){
        A intermediate;
        intermediate.a=a-obj.a;
        return intermediate;
    }
    friend ostream& operator<<(ostream & out,A &obj);
};
ostream& operator<<(ostream& out, A &obj){
    out<<obj.a;
    return out;
}
int main(){
    A a,b;
    a.setA(20);
    b.setA(10);
    A c=a-b;
    c.show();
}