//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
using namespace std;
int main(){
    int arr[]={0,1,2,3,4,5};
    int arr2[][]={{1,2,3},{4,5,6}};

    // arr2[][];    *((*arr + i)+j )
    int **ptr=new (int*)[5];
    for(int row=0;row<=6;row++){
        ptr2[row] = new int[6];
    }
    for(int row;row<=6;row++){
        delete []ptr2[row];
    }
    delete []ptr2;
    

    int a=21;
    int *ptr = &a;
    int **ptr2 = &ptr;

    cout<<ptr2<<" "<<&ptr<<endl;
    cout<<*ptr2<<" "<<ptr<<endl;
    cout<<**ptr<<" "<<*ptr<<endl;
    return 0;
}
