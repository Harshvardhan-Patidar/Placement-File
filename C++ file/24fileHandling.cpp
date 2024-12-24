//                      ********* !!  BY HARSH PATIDAR  !! ********

#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream fout;
    ifstream fin;
    fin.open("harsh.cpp");
    string str;
    fin>>str;
    cout<<str<<<endl;
    getline(fin,str);
    cout<<str<<endl;

    fin.seekg(-10,ios::cur); //this is a file pointer
    fin>>str;
    cout<<str<<endl;
    fin.seekg(0,ios::beg);
    while(!fin.eof()){
        getline(fin,str,'\n');
        cout<<str<<endl;
    }
    fin.close();


    fout.open("text.txt",ios::app);
    fout<<"Hi Iam Harsh, I like you so much ss"<<endl;
    fout.close();

    return 0;
}