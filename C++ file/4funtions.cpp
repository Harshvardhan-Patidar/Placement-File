//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
    void greeting(){
        cout<<"Hello!!!"<<endl;
    }

    bool isleapyear(int year){
        if(year%100==0){
            if(year%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else if(year%4==0){
            return true;
        }
        else{
            return false;
        }
    }

    void checkleapyear(int year){
        if(isleapyear(year)){
            cout<<year<<" is a leap year"<<endl;
        }
        else{
            cout<<year<<" is not leap year"<<endl;
        }
    }
int main(){
    greeting();
    cout<<"Enter the year"<<endl;
    int year;
    cin>>year;
    checkleapyear(year);
}