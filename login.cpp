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
        string userId, password, fname, lname, address, phone, email, power;
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
    system("cls");
    cout<<"1. Login"<<endl
    <<"2. Register"<<endl
    <<"3. Forgot Password";
    l.readlogin();
    return(0);
}
void login :: readlogin(){//to get username and password
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
            cout<<'*';
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
        cout<<"Login Successful";
    }
    else{
        cout<<"Invalid Login Attempt";
    }
}
bool login :: checklogin(string id, string ps){//verifies if input user name and password are true or not
    login l;//object of class login
    int count = 0;
    fstream fin;
    fin.open("login.txt",ios::in);
    fin.seekg(0,ios::beg);
    fin.read((char*)&l, sizeof(l));
    while(!fin.eof()){
        if(id == userId && ps == password){
            count = 1;//condition met if both id and passwird are correct
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
void login :: read(){//just for study purpose will be removed after wards 
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
void login :: display(){//just for study purpose will be removed after wards
    cout<<endl<<"user"<<userId<<"\tpass:"<<password<<endl;
}
void login :: signup(){// to create new user
    cout<<"First Name: ";
    ch=getch();
    while(ch != '\n' && ch != ' '){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            cout<<ch;
            fname.push_back(ch);
            ch=getch();
        }
        else if(ch == 8){
            fname.pop_back();
            cout<<"\b";
            ch=getch();
        }
    }
    cout<<"Last Name: ";
    ch=getch();
    while(ch != '\n' && ch != ' '){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            cout<<ch;
            fname.push_back(ch);
            ch=getch();
        }
        else if(ch == 8){
            fname.pop_back();
            cout<<"\b";
            ch=getch();
        }
    }
    cout<<"Address: ";
    cin>>address;
    cout<<"Email ";
    cout<<"phone no.";
}
