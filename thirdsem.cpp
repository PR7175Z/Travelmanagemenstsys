#include <iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int i;
class author{
    protected:
    string name,address,startingplace,destination,title;
    float cost;
    int userid,lenghtofdays;
    public:
    void additinery();
    void edititinery();
    void removeitinery();
    void checkbooking();
    void changepassword();

    cout<<"enter 1 to add itinery"<<endl
        <<"enter 2 to edit itinery"<<endl
        <<"enter 3 to remove itinery"<<endl
        <<"enter 4 to check booking"<<endl
        <<"enter 5 to chnage password"<<endl;
    cin>>i;
    switch(i)
    {
        case 1:
        additinery();
        break;

        case 2:
        edititinery();
        break;

        case 3:
        removeitinery();
        break; 

        case 4:
        checkbooking();
        break;

        case 5:
        changepassword();
        break;

        case 6:
        main();
        break;

    }

    void writeonfile()
    {
        fstream finout;
        finout.open("author.txt",ios::in|ios::out);
    }

     void additinery()
     {
        cout<<"enter userid:";
        cin>>userid;
      
        cout<<"package title";
        cin>>title;

        cout<<"starting place";
        cin>>startingplace;

        cout<<"destination";
        cin>>destination;  
        
        cout<<"days";
        cin>>lengthofdays; 
        
        cout<<"expenses(rs)";
        cin>>cost;
     }


}