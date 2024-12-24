//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin,s);

    cout<<"S Before: ";
    cout<<s.length()<<endl;

    cout<<"S After: ";
    s.push_back('p');
    cout<<s.length()<<endl;

    cout<<s.substr(1,3)<<endl;  // it print the value from 1 to 3
    string s2(s,1,2);
    cout<<"S2: "<<s2<<endl;

    int pos=s.find('a');
    if(pos==string::npos){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found "<<s.at(pos)<<" at: "<<pos<<endl;  //s[pos]
    }

    cout<<s.compare(s2)<<endl;
    cout<<s+s2<<endl;
    s.append(s2);
    cout<<s<<endl;
}