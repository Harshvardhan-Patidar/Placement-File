//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
void printbyfor(int num){
    for(int i=0;i<num;i++){
        cout<<"Harsh"<<endl;
    }
}
void printbywhile(int num){
    int i=0;
    while(true){
        if(i>num){
            break;
        }
        if(i%2==0){
            cout<<i<<" is even"<<endl;
        }
    i++;
    }
}
void printbydowhile(int num){
    int i;
    do{
        cout<<"Hi Harsh"<<endl;
        i++;
    }while(i<num);

}
int main(){
    printbyfor(20);
    printbywhile(20);
    printbydowhile(20);
    return 0;
}