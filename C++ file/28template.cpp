//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
template<typename T>
T maximum(T a,T b){
    return a>b?a:b;
}

template<>
string maximum<string>(string a,string b){
    if(a.length()>b.length) return a;
    return b;
}

template<typename A,class B>
void fun2(A a,B b){
    cout<<a+b<<endl;
}

template<typename T>
class A{
    T a;
    public:
    A(){}
    A(T a):a(a){}

    void show();
    void test(T m){
        cout<<m+a<<end;
    }
    template<typename M> M fum(M b){
        b+=10;
        return b;
    }
};

template <typename T>
void A<t>::show(){
    cout<<this->a<<endl;
}
int main(){
    maximum<int>(1,2)<<endl;
    maximum<string>("Hello I am HARSH","HARSH");
    fun2<float,int>(12,12);

    A<int>obj(10);
    obj.show();
    obj.test(21);
    cout<<obj.fun<int>(10)<<endl;
}