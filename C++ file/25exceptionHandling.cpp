//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    try{
        if(x<0) throw 10;
        x++;
    }
    catch(int e){
        cout<<"Exception: "<<e<<endl
    }
    catch(...){
        cout<<"Generic Exception: "<<endl;
    }
    return 0;
}