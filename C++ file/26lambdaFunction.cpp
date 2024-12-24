//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
void call(auto f){
    int a=21;
    int b=58;
    cout<<f(10)<<endl;
    cout<<"Internal "<<a<<" "<<b<<endl;
}
int main(){
    int a=21;
    int b=58;

    auto func1 = [&](int c)->{
        a+=c;
        b+=c;
        retyrn 100;
    };

    auto func2 = [a,&b](int c){
        b=a+c;
    };

    cout<<func1(10)<<endl;
    cout<<a<<" "<<b<<endl;

    cout<<func2(100);
    cout<<a<<" "<<b<<endl;

    auto func3 = [](){
        int a=10;
        cout<<a<<endl;
    };
    func3();
    call(fun1);
    return 0;
}