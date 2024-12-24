//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;

void modify(int a){
    a++;
}
void modifyRefrence(int &a){
    a++;
}

int main(){
    int a=21;
    int b=a;
    int &ref = a;

    a++;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<ref<<endl;
    cout<<"------------"<<endl;

    a=58;
    b=a;
    ref=a;
    b++;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<ref<<endl;
    cout<<"------------"<<endl;

    a=1;
    b=a;
    ref=a;
    ref++;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<ref<<endl;
    cout<<"------------"<<endl;

    b=100;
    cout<<"Before modify funtion call b: "<<b<<endl;
    modify(b);
    cout<<"After modify funtion call b: "<<b<<endl;

    b=100;
    cout<<"Before modify refrence funtion call b: "<<b<<endl;
    modifyRefrence(b);
    cout<<"After modify refrence funtion call b: "<<b<<endl;

    return 0;
}