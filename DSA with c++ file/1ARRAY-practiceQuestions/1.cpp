#include <iostream>
#include <cmath>
using namespace std;
/*
double factorial(int num){
    double result=sqrt(2*M_PI*n)*pow(num/M_E,num);
    return result;
}
*/
long long factorial(int num){
    long long int factorial=1;
    for(int i=1;i<=num;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int noOfZero(){
    long long fact=factorial(20);
    int flag=0;
    while(fact%10==0){
        fact/=10;
        flag++;
    }
    return flag;
}
// it will directly find no of zerowithout finding factorial
int totalZero(int num){
    int q=0;
    int no_of_zero=0;
    while(num!=0){
        q=num/5;
        no_of_zero=no_of_zero+q;
        num=num/5;
    }
    return no_of_zero;
}
int main(){
    // cout<<factorial(20);
    // cout<<endl;
    // cout<<noOfZero();
    // cout<<endl;
    cout<<totalZero(20);
    return 0;
}