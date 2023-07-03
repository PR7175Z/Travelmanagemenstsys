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
        void getpassword(char* choice){
            string newPs,cfmPs;
            if(choice == "reset"){
                password = "reset";
            }
            else if(choice == "change"){
                do{
                    cout<<"Enter New Password: ";
                    cin>>newPs;
                    cout<<"Confirm Password: ";
                    cin>>cfmPs;
                    if(newPs == cfmPs){
                        password = cfmPs;
                    }
                    else{
                        cout<<"password did not match";
                    }
                }while(newPs != cfmPs);
            }
        }
        string get_userId();
        string get_password();
        string get_fname();
        string get_lname();
        string get_address();
        string get_phone();
        string get_email();
        string get_power();

        string validEmail();
        void writetofile();
        void resetPassword(char* , char*);
        void changePassword(char* , char*);
        void signin();
        void signup();
        void display();
};
int main(){
    system("cls");
    login l,m;
    fstream fin,fout;
    char id[10], ph[10], ps[25];
    int choice=1;
    cout<<"Welcome to TMS"<<endl;
    while(choice != 10){
        system("cls");
        cout<<"1. Login"<<endl
        <<"2. Register"<<endl
        <<"3. Forgot Password"<<endl
        <<"4. Change Passwotd"<<endl
        <<"5. Display"<<endl
        <<"Enter your Choice:";
        cin>>choice;
        switch (choice){
            case 0://nothin
                choice = 10;
                break;
            case 1://login to system
                l.signin();
                break;
            case 2://register t system
                l.signup();
                l.writetofile();
                break;
            case 3://reset password
                cout<<"User Id";
                cin>>id;
                cout<<"phone number";
                cin>>ph;
                l.resetPassword(id,ph);
                break;
            case 4:
                cout<<"User Id";
                cin>>id;
                cout<<"Password";
                cin>>ps;
                l.changePassword(id,ps);
                break;
            case 5://display all account
                fin.open("login.txt",ios::in | ios::binary);
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
void login :: writetofile(){//check garna baaki xa hae
    fstream fout;
    fout.open("login.txt",ios::out | ios::app | ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void login :: signin(){//to get username and password
    login l;//object of class login
    int count = 0;
    fstream fin;
    userId.clear();
    password.clear();
    fin.open("login.txt",ios::in | ios::binary);
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
int count=0,check=0;
    fname.clear();
    cout<<"First Name: ";{
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
    }
    
    lname.clear();
    cout<<endl<<"Last Name: ";{
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
    }
    
    cout<<endl<<"Address: ";{
        cin.ignore();
        getline(cin,address);
    }

    cout<<endl<<"Email: ";

    cout<<endl<<"Phone No.: ";
    count =0;
    while(count <10){
        ch=getch();
        if(count==1 && ch!=9){
            check++;
            phone.push_back(ch);
            cout<<ch;
        }
        else if(count==2 && (ch!=8 || ch!=7)){
            check++;
            phone.push_back(ch);
            cout<<ch;
        }
        else if (ch == 8){
            count--;
            cout<<"\b";
            phone.pop_back();
        }
        else{
            count++;
            phone.push_back(ch);
            cout<<ch;
        }
    }
    
    cout<<"User ID: ";
    cin>>userId;

    cout<<"Password: ";
    cin.ignore();
    getline(cin,password);
}
void login :: resetPassword(char* id , char* ph){
    int count = 0;
    fstream file;
    file.open("login.txt",ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0,ios::beg);
    file.read((char*)this, sizeof(*this));
    while(!file.eof()){
        if(id == userId && ph == phone){
            count = 1;
            getpassword("reset");
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char*)this, sizeof(*this));
        }
        else if(id == userId && ph != phone){
            count =2;
        }
        file.read((char*)this, sizeof(*this));
    }
    file.close();
    if(count == 0){
        cout<<"User id not found";
    }
    else if(count == 1){
        cout<<"Password reset to : happy123";
    }
    else if(count == 2){
        cout<<"invalid input";
    }
    getch();
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
void login :: changePassword(char* id , char* ps){
    int count = 0;
    fstream file;
    file.open("login.txt",ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0,ios::beg);
    file.read((char*)this, sizeof(*this));
    while(!file.eof()){
        if(id == userId && ps == password){
            count = 1;
            getpassword("change");
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char*)this, sizeof(*this));
        }
        else if(id == userId && ps != password){
            count =2;
        }
        file.read((char*)this, sizeof(*this));
    }
    file.close();
    if(count == 0){
        cout<<"User id not Found";
    }
    else if(count == 1){
        cout<<"Password Changed Successfully";
    }
    else if(count == 2){
        cout<<"Invalid Input";
    }
    getch();
}


