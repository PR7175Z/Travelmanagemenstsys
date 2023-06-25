#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<strings.h>
#define def "AARC"

using namespace std;

int Login();
int Registers();
int ListPackage();
int SearchPackage();



class packagelist
{
    string pid;     //package id
    string ptitle; //package title
    string stplace; //start place
    string endplace; //end destination
    int days;
    int exp;  //expense of the package
public:
    void viewdetail();
    void addpackage();
    void display();
    void DeletePackage();
};


void packagelist::addpackage()
{
    fstream createfile;  //write in file
    createfile.open("PackageList.txt",ios::app);
    cout<<"Package Title:";
    getline(cin,ptitle);
    cout<<"Starting Place:";
    getline(cin,stplace);
    cout<<"End Destination:";
    getline(cin,endplace);
    cout<<"No of days:";
    cin>>days;
    cout<<"Expenses of Package:";
    cin>>exp;
    fstream gpid;  //get package id
    int id=1;
    string tid;   //temporary
    gpid.open("pid.txt",ios::in);
    gpid>>id;
    tid=to_string(id);
    pid=def+tid;
    id++;
    gpid.close();
    fstream wpid;
    wpid.open("pid.txt",ios::out);
    wpid<<id;
    wpid.close();

    createfile<<pid<<";"<<ptitle<<";"<<stplace<<";"<<endplace<<";"<<days<<";"<<exp<<endl;
    createfile.close();

}

void packagelist::display()
{
    string ch;
    string pkg;
    int lenofstplace, lenofendplace;
    fstream readfile; //open file in read mode
    readfile.open("PackageList.txt",ios::in);
    cout<<"Package ID  \tPackage Title  \tStarting place  \tEnd place  \tNo of days  \tExpenses of package"<<endl;
    string line;
    while(getline(readfile,line))
    {
        size_t pos;  //pos=position
        string temp;
        int count=0;
        while ((pos = line.find(';')) != string::npos)   //line string  ma ; khojera variable seperate garxa
        {
            temp=line.substr(0,pos);
            switch(count)
            {
            case 0:
                pid=temp;
            break;

            case 1:
                ptitle=temp;
                break;

            case 2:
                stplace=temp;
                break;

            case 3:
                endplace=temp;
                break;

            case 4:
                days=stoi(temp);
                break;

            case 5:
                exp=stoi(temp);
                break;
            }
            line.erase(0,pos+1);
            count++;
        }

        lenofendplace=endplace.size();
        lenofstplace=stplace.size();
        // cout<<"TGBDFG:"<<lenofstplace<<endl;
        // cout<<"DSFvsdvf:"<<lenofendplace<<endl;
        if(readfile.eof())
        {
            break;
        }
        if(lenofstplace>=8)
        {
            cout<<pid<<"\t\t"<<ptitle<<"\t\t"<<stplace<<"\t\t";
        }
        else
        {
            cout<<pid<<"\t\t"<<ptitle<<"\t\t"<<stplace<<"\t\t\t";
        }


        if(lenofendplace>=8)
        {
            cout<<endplace<<"\t\t"<<days<<"\t\t"<<exp<<endl;
        }
        else
        {
            cout<<endplace<<"\t\t\t"<<days<<"\t\t"<<exp<<endl;
        }
    }
    readfile.close();
}

int main()
{
    start:
    system("CLS");
    system("color e");
    char ch;
    char pkg;
    packagelist p1;
    int c;
    cout<<" 1.List Package\n 2.Search Package\n 3.Login\n 4.Register\n 5.Exit\n";
    cout<<"Enter the case you wanna view:\n";
    c=getch();
    switch(c)
    {
        case '1':
            //p1.addpackage();
            system("CLS");
           // cout<<"Enter any key to display:\n";
            system("pause");
            p1.display();
            getch();
        break;
    }
    system("CLS");
    cout<<"Do you want to view the detail(Y/N):\n";
    ch=getch();
    if(ch=='Y'||ch=='y')
    {
        cout<<"Enter the package you wanna display:";
        pkg=getch();
    }
    else
    {
        goto start;
    }
    return 0;
}
