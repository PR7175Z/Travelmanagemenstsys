#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<fstream>

using namespace std;

int count=0,valid=0;

class login{
    protected:
        char ch;
        string userId, password, fname, lname, address, phone, email, power;
    public:
        bool signin();

        void writeFile();
        void readFile();
        void display();
        void signup();

        string get_userId();
        string get_password();
        string get_fname();
        string get_lname();
        string get_address();
        string get_phone();
        string get_email();
        string get_power(bool);
        string change_password(char*);
};

int main(){
    system("cls");
    fstream fin;
    login l;
    char* change;
    int choice=1;
    while(choice!=0){
        system("cls");
        cout<<"1. Sign In"<<endl
        <<"2. Sign Up"<<endl
        <<"3. Change Password"<<endl
        <<"4. Reset Password"<<endl
        <<"5. Display"<<endl
        <<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                choice=0;
                break;
            case 1:
                l.signin();
                getch();
                break;
            case 2:
                l.signup();
                l.writeFile();
                cout<<endl<<"signup successful";
                break;
            case 3:
                change = "reset";
                l.change_password(change);
                cout<<"Your New Password is: 'reset'";
                getch();
                break;
            case 4:
                change = "change";
                l.change_password(change);
                cout<<"Password Changed Successfully";
                getch();
                break;
            case 5:
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
                cout<<"invalid choice:";
                break;
        }
    }
    return 0;
}

void login :: writeFile(){//check garna baaki xa hae
    fstream fout;
    fout.open("login.txt",ios::out | ios::app | ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}
void login :: signup(){
    int choice;
    cout<<endl<<"1. Register as Admin."
    <<endl<<"2. Register as Author.";
    cin>>choice;
    if(choice == 1){
        get_power(true);
    }
    else if(choice == 2){
        get_power(false);
    }
    else{
        cout<<"Invalid Input";
        signup();
    }
    get_userId();
    get_password();
    get_fname();
    get_lname();
    get_address();
    get_phone();
}
void login :: display(){
    cout<<endl
    <<"userID"<<userId<<endl
    <<"Password:"<<password<<endl
    <<"First name: "<<fname<<endl
    <<"Last name: "<<lname<<endl
    <<"Address: "<<address<<endl
    //<<"Email: "<<email<<endl
    <<"Phone: "<<phone<<endl
    <<"Power: "<<power<<endl;
}
/* void login :: readFile(){
    userId;
    password;
    fname;
    lname;
    address;
    phone;
} */
string login :: get_userId(){
    count = 0;
    userId.clear();
    cout<<endl<<"User ID: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            userId.pop_back();
            count--;
        }
        else if(ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            userId.push_back(ch);
            count++;
        }
        ch=getch();
    }while(ch != 13 && count!=10);
    if(count == 0){
        cout<<"Invalid User ID";
        get_userId();
    }
    return (userId);
}
string login :: get_fname(){
    count = 0;
    fname.clear();
    cout<<endl<<"First Name: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            fname.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets both upper and lowe case
            cout<<ch;
            if(ch>=97 && ch<=122){//converts and store lower to upper case
                ch-=32;
                fname.push_back(ch);
            }
            else{//upper case
                fname.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 15);
    if(count == 0){
        cout<<"Invalid First Name"<<endl<<"Re-Enter ";
        get_fname();
    }
    return(fname);
}
string login :: get_lname(){
    count = 0;
    lname.clear();
    cout<<endl<<"Last Name: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            lname.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){//lower to upper case
                ch-=32;
                lname.push_back(ch);
            }
            else{
                lname.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 20);
    if(count == 0){
        cout<<"Invalid Last Name"<<endl<<"Re-Enter ";
        get_lname();
    }
    return(lname);
}
string login :: get_address(){
    count = 0;
    address.clear();
    cout<<endl<<"Address: ";
    ch=getch();
    do{
        if(ch == 8){
            cout<<"\b";
            address.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){
                ch-=32;
                address.push_back(ch);
            }
            count++;
        }
        else if(ch == 32){//space
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if(ch >= 48 && ch <= 57){//numbers
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if(ch == 44 || ch == 45){//hyphen and comma
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 30);
    if(count == 0){
        cout<<"Invalid Address"<<endl<<"Re-Enter ";
        get_address();
    }
    return(address);
}
string login :: get_phone(){
    valid = 0;
    count = 0;
    phone.clear();
    cout<<endl<<"Phone: ";
    ch=getch();
    do{
        if(count == 0 && ch != 57){
            valid++;
            count++;
            cout<<ch;
            phone.push_back(ch);
        }
        else if(ch!=55 && ch!=56 && count == 1 ){
            valid++;
            count++;
            cout<<ch;
            phone.push_back(ch);
        }
        else if(ch == 8 && count != 0){//backspace
            if(count == 1 || count == 2){
                valid--;
            }
            cout<<"\b";
            phone.pop_back();
            count--;
        }
        else if(ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            phone.push_back(ch);
            count++;
        }
        ch=getch();
        if(ch == 13 && count<9){
            valid++;
        }
        if(count == 10){
            break;
        }
    }while(ch != 13);
    if(valid>0){
        cout<<"Invalid Phone"<<endl<<"Re-Enter ";
        get_phone();
    }
    return (phone);
}
string login :: get_password(){
    count=0;
    password.clear();
    cout<<endl<<"Password: ";
    do{
        ch=getch();
        if(ch == 8 && count != 0){
            cout<<"\b";
            password.pop_back();
            count--;
        }
        else{
            cout<<ch;
            password.push_back(ch);
            count++;
        }
    }while(count != 25 && ch != 13);
    if(count == 0){
        cout<<"Invalid Password"<<"Re-Enter ";
        get_password();
    }
    return(password);
}
string login :: change_password(char* choice){
    string new_password,confirm_password;
    if(choice == "reset"){
        password = "reset";
    }
    else if(choice == "change"){
        cout<<"Enter New  ";
        new_password = get_password();
        cout<<"Confirm  ";
        confirm_password = get_password();
        if(new_password == confirm_password){
            password = confirm_password;
        }
        else{
            cout<<"Password did not match";
            choice = "change";
            change_password(choice);
        }
    }
    return (password);
}
string login :: get_power(bool pow){
    if(pow){
        power = "ADMIN";
    }
    else if(!pow){
        power = "AUTHOR";
    }
    return (power);
}
