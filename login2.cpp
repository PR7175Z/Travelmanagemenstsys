#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<fstream>
using namespace std;
int count,valid;
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
};
string login :: get_userId(){
    userId.clear();
    cout<<"User ID: ";
    ch=getch();
    do{
        if(ch == 8){//backspace
            cout<<"\b";
            userId.pop_back();
        }
        else if(ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            userId.push_back(ch);
        }
        else{//invalid input
            count++;
        }
        ch=getch();
    }while(ch != 13);
    return (userId);
}
string login :: get_fname(){
    fname.clear();
    cout<<"First Name: ";
    ch=getch();
    do{
        if(ch == 8){//backspace
            cout<<"\b";
            fname.pop_back();
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
        }
        else{//invalid input
            count++;
        }
        ch=getch();
    }while(ch != 13);
    return(fname);
}
string login :: get_lname(){
    lname.clear();
    cout<<"Last Name: ";
    ch=getch();
    do{
        if(ch == 8){//backspace
            cout<<"\b";
            lname.pop_back();
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
        }
        else{
            count++;
        }
        ch=getch();
    }while(ch != 13);
    return(lname);
}
string login :: get_address(){
    address.clear();
    cout<<"Address: ";
    ch=getch();
    do{
        if(ch == 8){
            cout<<"\b";
            address.pop_back();
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){
                ch-=32;
                address.push_back(ch);
            }
        }
        else if(ch == 32){//space
            cout<<ch;
            address.push_back(ch);
        }
        else if(ch >= 48 && ch <= 57){//numbers
            cout<<ch;
            address.push_back(ch);
        }
        else if(ch == 44 || ch == 45){//hyphen and comma
            cout<<ch;
            address.push_back(ch);
        }
        else{
            count++;
        }
        ch=getch();
    }while(ch != 13);
    return(address);
}
string login :: get_phone(){
    valid = 0;
    count = 0;
    phone.clear();
    cout<<"Phone: ";
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
        cout<<"Invalid Phone"<<endl;
        get_phone();
    }
    return (phone);
}

int main(){
    system("cls");
    login a;
    string id;
    //id = ;
    cout<<"\nchecked phone:"<<a.get_phone();
}