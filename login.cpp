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
        void signin();
        void signup();
        void resetPassword();
        void display();
}l;
int main(){
    system("cls");
    login l,m;
    fstream fin,fout;
    int choice=1;
    cout<<"Welcome to TMS"<<endl;
    while(choice != 0){
        system("cls");
        cout<<"1. Login"<<endl
        <<"2. Register"<<endl
        <<"3. Forgot Password"<<endl
        <<"Enter your Choice:";
        cin>>choice;
        switch (choice){
            case 0:
                choice = 0;
                break;
            case 1:
                l.signin();
                break;
            case 2:
                fout.open("login.txt",ios::out | ios:: app);
                l.signup();
                fout.write((char*)&l, sizeof(l));
                fout.close();
                break;
            case 3:
                fin.open("login.txt",ios::in);
                fin.seekg(0,ios::beg);
                fin.read((char*)&l, sizeof(l));
                while(!fin.eof()){
                l.display();
                fin.read((char*)&l, sizeof(l));
                }
                fin.close();
                getch();
                break;
            default:
                cout<<"INVALID REQUEST";
                getch();
                break;
        }
    }    
    return(0);
}
void login :: signin(){//to get username and password
    login l;//object of class login
    int count = 0;
    fstream fin;
    userId.clear();
    password.clear();
    fin.open("login.txt",ios::in);
    cout<<"value of count: "<<count<<endl;
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
    fin.seekg(0,ios::beg);
    fin.read((char*)&l, sizeof(l));
    while(!fin.eof()){
        if(userId == l.userId && password == l.password){
            count = 1;//condition met if both id and passwird are correct
            exit;
        }
        fin.read((char*)&l, sizeof(l));
    }
    fin.close();
    cout<<"value of count: "<<count<<endl;
    if(count==1){
        cout<<"Login Successful";
        getch();
    }
    else if(count == 0){
        cout<<"Invalid Login Attempt";
        getch();
    }
}
void login :: signup(){// to create new user
    fname.clear();
    lname.clear();
    cout<<"First Name: ";
    ch=getch();
    while(ch != 13){
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
    cout<<endl<<"Last Name: ";
    ch=getch();
    while(ch != 13){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            cout<<ch;
            lname.push_back(ch);
            ch=getch();
        }
        else if(ch == 8){
            lname.pop_back();
            cout<<"\b";
            ch=getch();
        }
    }
    cout<<endl<<"Address: ";
    cin>>address;
    cout<<"Email ";
    cin>>email;
    cout<<"phone no.";
    cin>>phone;
    userId="1234";
    password="happy1234";
    
}
void login :: resetPassword(){//check garna baaki xa hae
    login l;
    fstream fin, fout;
    fin.open("login.txt", ios::in);
    fin.seekg(0,ios::beg);
    fout.open("login2.txt", ios::app | ios::out);
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
            lname.push_back(ch);
            ch=getch();
        }
        else if(ch == 8){
            lname.pop_back();
            cout<<"\b";
            ch=getch();
        }
    }
    cout<<"phone:";
    cin>>phone;
    fin.read((char*)&l,sizeof(l));
    while(!fin.eof()){
        if(fname == l.fname && userId == l.userId && phone == l.phone){
            l.password = "happy123";
        }
        fout.write((char*)&l,sizeof(l));
        fin.read((char*)&l,sizeof(l));
    }
    fin.close();
    fout.close();
    remove("login.txt");
    rename("login2.txt","login.txt");
    cout<<"Password: ";
}
void login :: display(){
    cout<<endl
    <<"userID"<<userId<<endl
    <<"Password:"<<password<<endl
    <<"First name: "<<fname<<endl
    <<"Last name: "<<lname<<endl
    <<"Address: "<<address<<endl
    <<"Email: "<<email<<endl
    <<"Phone: "<<phone<<endl;
}