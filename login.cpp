#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<fstream>
using namespace std;
class login{
    protected:
        char ch;
        string userId, password, fname, lname, address, email, phone;
    public:
        void readlogin();
        bool checklogin(string, string);
        void read();
        void display();
        void signup();
    
};
int main(){
    system("cls");
    login l;
    cout<<"Welcome to TMS"<<endl;
    cout<<"1.Login"<<endl
    <<"2. Register"<<endl
    <<"3. Forgot Password";
    l.readlogin();
    return(0);
}
void login :: readlogin(){
    cout<<endl<<"User ID: ";
    ch = getch();
    while(ch != 13){
        if(ch != 8){
            cout<<ch;
            userId.push_back(ch);
            ch = getch();
        }
        else if(ch == 8){
            cout<<"\b";
            userId.pop_back();
            ch = getch();
        }
    }
    cout<<endl<<"Password: ";
    ch = getch();
    while(ch != 13){
        if(ch != 8){
            cout<<ch;
            password.push_back(ch);
            ch = getch(); 
        }
        else if(ch == 8){
            cout<<"\b";
            password.pop_back();
            ch = getch();
        }
    }
    if(checklogin(userId, password)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
bool login :: checklogin(string id, string ps){
    login l;
    int count = 0;
    fstream fin;
    fin.open("login.txt",ios::in);
    fin.seekg(0,ios::beg);
    fin.read((char*)&l, sizeof(l));
    while(!fin.eof()){
        if(id == userId ){
            count = 1;
        }
        fin.read((char*)&l, sizeof(l));
    }
    fin.close();
    if(count == 1){
        return true;
    }
    else{
        return false;
    }
}
void login :: read(){
    login l;
    fstream fout;
    fout.open("login.txt",ios::out | ios::app | ios::in);
    while(!fout.eof()){
    fout.read((char*)&l, sizeof(l));
    display();
    }
    fout.close();
    getch();
}
void login :: display(){
    cout<<endl<<"user"<<userId<<"\tpass:"<<password<<endl;
}
void login :: signup(){
    cout<<"First Name: ";
    ch=getch();
    while(ch != 13){
        if(ch >= 54 && ch<=64){

        }
    }
    cout<<"Last Name: ";
    cout<<"Address: ";
    cout<<"Email ";
}
