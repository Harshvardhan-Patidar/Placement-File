//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
#include <ios>
#include <limits>
using namespace std;

int main(){
    int a;
    float b;
    char c;
    string str;

    cout<<"HI HARSH"<<endl;
    cout<<"Enter a number"<<endl;
    cin>>a>>b>>c;
    cout<<a<<b<<c<<endl;

    cout<<"Enter a word"<<endl;
    cin>>str;
    cout<<str<<endl;

    cout<<"Enter a sentance"<<endl;
    getline(cin,str,'$');    //we can use by default getline(cin,str)
    cout<<str<<endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // in above input if we write the word after '$' 
    cout<<"Enter a sentance"<<endl;                     // it print on next cout rather than take input
    getline(cin,str);
    cout<<str<<endl;

    //manipulator
    string s="Harsh";
    cout<<s<<endl;
    cout<<setw(8)<<setfill('#');
    cout<<right<<s<<endl;

    return 0;
}