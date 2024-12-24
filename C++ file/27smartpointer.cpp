//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
class A{
    int a;
    public:
    A(){cout<<"Constructor"<<endl;}
    ~A(){cout<<"Distructor"<<endl;}
    void fun(){
        cout<<"Harsh!"<<endl;
    }
};
int main(){
    {
        unique_ptr<A> ptr = make_unique<A>();
        ptr->fun();
    }

    shared_ptr<A> ptr01;
    shared_ptr<A> ptr02;
    weak_ptr<A> wp;
    {
        shared_ptr<A> ptr=make_unique<A>();
        cout<<ptr.use_count()<<endl;
        shared_ptr<A> ptr2=make_unique<A>();
        cout<<ptr2.use_count()<<endl;
        ptr01=ptr2;
        cout<<ptr.use_count()<<endl;
        ptr->fun();
        ptr2->fun();
        wp=ptr;  // we do wp=ptr2, it is same
        cout<<ptr.use_count()<<endl;
    }
    if(wp.expired){
        cout<<"Expired"<<endl;
    }
    else{
        cout<<wp.use_count()<<endl;
        ptr02=wp.lock();
    }
    cout<<ptr01.use_count()<<endl;
    cout<<"After all blocks"<<endl;
}