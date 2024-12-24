//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;

class car{
    string name,id;
    float mileage;
    float distanceTravel

    public:
    car(){
        cout<<"Default constructor"<<endl;
        distanceTravel=0;
    }
    car(string name,string id){
        cout<<"parameterized constructor"<<endl;
        this->name=name;
        this->id=id;
        distanceTravel=0;
    }
    ~car(){
        cout<<"Distructor called"<<endl;
    }
    string getName(){
        return this->name;
    }
    int getId(){
        return this->id;
    }

    float getMileage();
    void travel(float);
}
float car::getMileage(){
    return mileage;
}
void car::travel(float kmsTravel){
    distanceTravel+=kmsTravel;
}
int main(){
    car c('Jamli',1234);
    return 0;
}