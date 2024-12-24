//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
struct demostruct{
    int val1;
    double val2;
};
typedef struct demostruct dstruct;

class demo{
    string name;
    public:
        demo(){}
        demo(string ip):name(ip){}

        void printName(){
            cout<<"Name: "<<name<<endl;
        }
};
typedef demo dem;
int main(){

    //Primitive data types
    int num;
    float dec = 21.58;
    char ch='h';
    double dec2 = 21.58;
    bool val = true;

    //Derived data types
    int arr[]={1,2,3,4,5,6};
    int *ptr = &num;
    int &numRef=num;

    //User define data types
    enum day{
        sunday = 1,
        monday,tuesday,wednesday,thursday,friday,saturday
    };
    day d=sunday;
    cout<<"Day is: "<<d<<endl;

    // struct demostruct s;
    dstruct s{0,1};
    cout<<s.val2<<endl;

    demo demoobject("Harsh");
    demoobject.printName();

    return 0;
}