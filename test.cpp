#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
class test{
string num;
public:
void fetch(){    
    cin>>num;
}
void display(){
    cout<<"number is: "<<num;
}
};
int main(){
    system("cls");
    test t;
    fstream fin, fout;
    fout.open("test.txt",ios::out | ios::app);
    t.fetch();
    fout.write((char*)&t, sizeof(t));
    fout.close();

    fin.open("test.txt",ios::in);
    fin.seekg(0,ios::beg);
    fin.read((char*)&t, sizeof(t));
    while(!fin.eof()){
    t.display();
    fin.read((char*)&t, sizeof(t));
    }
    fin.close();
    return 0;

}