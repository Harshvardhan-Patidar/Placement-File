//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class car{
    string name;
    int id;
    float mileage;
    static int numOfCar;

    public:
    car(){
        numOfCar++;
    }
    car(string name,int id){
        this->name=name;
        this->id=id;
        numOfCar++;
    }
    ~car(){
        cout<<"Distructor called"<<endl;
        numOfCar--;
    }
    static 
    string grtName(){
        return this->name;
    }
    int getId(){
        return this->id;
    }
    float getMileage();
    float getnumOfCar();
};
int car::numOfCar=0;
float car::getMileage(){
    cout<<"No of car"<<numOfCar<<endl;
    return mileage;
}
float car:getnumOfCar(){
    return numOfCar;
}
int main(){
    car c('Indore',1234);
    car c2;
    cout<<car::getnumOfCar()<<endl;
    car c3;
    cout<<car::getnumOfCar<<endl;               
}