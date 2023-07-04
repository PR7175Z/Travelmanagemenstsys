#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<fstream>

using namespace std;
static int id;
int count=0,valid=0;

class login{
    protected:
        char ch;
        string userId, password, fname, lname, address, phone, email, power;
    public:
        bool signin(bool);

        void writeFile();
        void readFile();
        void display();
        void signup(bool);

        string get_userId();
        string get_password();
        string get_fname();
        string get_lname();
        string get_address();
        string get_phone();
        string get_email();
        string cpassword();
        string get_power(bool);
};

int main(){
    system("cls");
    fstream fin;
    login l;
    int choice=1,operation=1;
    while(choice!=5){
        system("cls");
        cout<<"1. Admin"<<endl
        <<"2. Author"<<endl
        <<"3. List Package"<<endl
        <<"4. Search Package"<<endl
        <<"5. Exit"<<endl
        <<"6. Display Accounts"<<endl
        <<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:{//for admin
                //this is inside admin panel
                operation=0;
                while(operation != 4){
                    system("cls");
                    cout<<"Admin Menu"<<endl
                    <<"1. Log In"<<endl
                    <<"2. Register"<<endl
                    <<"3. Forgot Password"<<endl
                    <<"4. Exit"<<endl
                    <<"Enter choice: ";
                    cin>>operation;
                    switch(operation){
                        case 1://login
                            if(l.signin(true)){
                                cout<<"Welcome ADMIN";
                            }
                            getch();
                            break;
                        case 2://register
                            l.signup(true);
                            l.writeFile();
                            getch();
                            break;
                        case 4://exit
                            operation=4;
                            break;
                        default:
                            cout<<"Invalid Operation";
                            getch();
                            break;
                    }
                }
                break;
            }
            case 2:{//for author
                //this is inside author panel
                operation=0;
                while(operation != 4){
                    system("cls");
                    cout<<"Author Menu"<<endl
                    <<"1. Log In"<<endl
                    <<"2. Register"<<endl
                    <<"3. Forgot Password"<<endl
                    <<"4. Exit"<<endl
                    <<"Enter choice: ";
                    cin>>operation;
                    switch(operation){
                        case 1:
                            if(l.signin(true)){
                                cout<<"Welcome AUTHOR";
                            }
                            getch();
                            break;
                        case 2:
                            l.signup(false);
                            l.writeFile();
                            getch();
                            break;
                        case 4:
                            operation=4;
                            break;
                        default:
                            cout<<"Invalid Operation";
                            getch();
                            break;
                    }
                }
                break;
            }
            case 3:{//check
                cout<<"List Package";
                getch();
                break;
            }
            case 4:{//search
                cout<<"Search Package";
                getch();
                break;
            }
            case 5:{//exit
                choice = 5;
                break;
            }
            case 6:{//display
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
            }
            default:{
                cout<<"invalid choice:";
                break;
            }
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
bool login :: signin(bool sign){
    count = -1;
    login r;
    fstream fin;
    fin.open("login.txt",ios::in | ios::binary);
    get_userId();
    get_password();
    fin.seekg(0,ios::beg);
    if(sign){
        while(!fin.eof()){
            fin.read((char*)&r,sizeof(r));
            if(userId==r.userId && password == r.password && r.power == "ADMIN"){
                count = 1;
            }
        }
    }
    else if(!sign){
        while(!fin.eof()){
            fin.read((char*)&r,sizeof(r));
            if(userId==r.userId && password == r.password && r.power == "AUTHOR"){
                count = 1;
            }
        }
    }
    fin.close();
    if(count == 1){
        return (true);//true for admin
    }
    else{
        cout<<"ID not Found please try again";
        signin(sign);
    }
}
void login :: signup(bool sign){
    get_fname();
    get_lname();
    get_address();
    get_phone();
    get_password();
    get_power(sign);//true for admin, false for author
    get_userId();
    cout<<endl<<"Please Note Your User Id for Future Login."<<endl<<"Your User ID is: "<<userId;
}
void login :: display(){
    cout<<endl
    <<"userID: "<<userId<<endl
    <<"Password: "<<password<<endl
    <<"First name: "<<fname<<endl
    <<"Last name: "<<lname<<endl
    <<"Address: "<<address<<endl
    //<<"Email: "<<email<<endl
    <<"Phone: "<<phone<<endl
    <<"Power: "<<power<<endl;
}
string login :: get_userId(){
    //here power is already stored from signup
    login l;
    fstream fin;
    userId.clear();
    if(power == "ADMIN"){
        srand(time(0));
        id=870000+rand()%10000;
    }
    else if(power == "AUTHOR"){
        srand(time(0));
        id=370000+rand()%10000;
    }
    userId=to_string(id);
    fin.open("login.txt",ios::in | ios::binary);
    fin.seekg(0,ios::beg);
    while(!fin.eof()){
        fin.read((char*)&l,sizeof(l));
        if(l.userId == userId){
            get_userId();
        }
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
string login :: get_power(bool pow){
    power.clear();
    if(pow){
        power = "ADMIN";
    }
    else if(!pow){
        power = "AUTHOR";
    }
    return (power);
}
