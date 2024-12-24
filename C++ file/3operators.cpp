//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
int main(){
    int a,b;
    a=21,b=58;
    //Arithmetic operations
    cout<<a+b;
    cout<<a-b;
    cout<<a*b;
    cout<<a/b;
    cout<<a%b<<endl; // during module, the sign of the left opreand will be the sign of output

    //Lodical operations
    // <,>,<=,>=,==,!=
    if(a>b){
        cout<<"A is greater"<<endl;
    }
    else{
        cout<<"B is greater"<<endl;
    }

    //Relational operator
    // &&,||,!
    if(a>b && b!=0){
        cout<<"Result1"<<endl;
    }
    else{
        cout<<"Result2"<<endl;
    }

    //Bitwise operator
    // &,|,^,<<,>>,~
        cout<<a|b<<endl;
        cout<<a&b<<endl;
        cout<<a<<b<<endl;
        cout<<~a<<endl;

    //Ternary operator
    // condition ? expression1 : expression2
    c=(a>b)?a:b<<endl;

    //Unary operator
    // ++,--
    a=1;
    c=a++;
    cout<<c" "<<a<<<<endl;

    //Shortcut assignment operator
    // +=,-=,*=,/=
    cout<<c+=a<<endl;

    //Other operator
    // sizeof,new,delete,&(address assign),*(dereferencing perator),->
    int *ptr = new int(10);
    delete ptr;
}