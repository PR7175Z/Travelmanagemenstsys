#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cctype>
#include<fstream>
#include<strings.h>
#define pn "+977-" //for phone number
#define db "/"  //for dob
#define bd "BOID" //for booking list id
#define def "AARC" //default string to store the package id
#define max 50 //max value for the array of string of storing itenary
using namespace std;
void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}



class packagelist
{
protected:
    string pid;     //package id
    string ptitle; //package title
    string stplace; //start place
    string endplace; //end destination
    int days;       //days
    int exp;  //expense of the package
public:
    void listdetail();
    void addpackage();  //function to addpackage in file
    void display();     //function to display package from file to console
    void searchpkg(string);  //function to search package
    void display1(int a=0)
    {
        cout<<pid;
        moveCursor(17,5+a);
        cout<<ptitle;
        moveCursor(41,5+a);
        cout<<stplace;
        moveCursor(65,5+a);
        cout<<endplace;
        moveCursor(90,5+a);
        cout<<days;
        moveCursor(103,5+a);
        cout<<exp<<endl;
        }
};

void packagelist::searchpkg(string keyword)
{
    bool check=false;
    string ch;
    string pkg;
    int lenofstplace, lenofendplace;
    fstream readfile; //open file in read mode
    readfile.open("PackageList.txt",ios::in);
    cout<<"Package ID ";
    moveCursor(17,4);
    cout<<"Package Title";
     moveCursor(41,4);
    cout<<"Starting place";
    moveCursor(65,4);
    cout<<"End place";
    moveCursor(86,4);
    cout<<"No of days";
    moveCursor(100,4);
    cout<<"Expenses of package"<<endl;
    string line;
    int ct=0;
    while(getline(readfile,line))
    {
        if(readfile.eof())          //loop chalira bela end of file pugyo bhane break garxa
        {
            break;
        }
        size_t pos,sos;  //pos=position
        string temp;

        int count=0;
        while ((pos = line.find(';')) != string::npos)   //line string  ma ; khojera variable seperate garxa
        {
            temp=line.substr(0,pos);        //temp ma line ko suru dekhi ; bhanda agadi ko string store garxa
            switch(count)               // file bata line liyera ; bata xutaudai variable ma order ma save garxa
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
                days=stoi(temp);                //string to integer
                break;

            case 5:
                exp=stoi(temp);
                break;
            }
            line.erase(0,pos+1);                // 0 dekhi ; sama ko string erase garxa
            count++;
        }
        size_t found=ptitle.find(keyword);      //size_t is unsigned integral data type to represent size of array
        if(found!=string::npos)                 //keyword bhetena bhane yo condition fail hunxa
        {
            check=true;
            display1(ct);
            ct++;
        }


    }
    if(check==false)
    {
        cout<<"Keyword not found";
    }

    readfile.close();
}



void packagelist::addpackage()
{
    cin.ignore(100,'\n');
    fstream createfile;                                  //write in file
    createfile.open("PackageList.txt",ios::app);         //create file
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
    fstream gpid;                                       // gpid=get package id
    int id=1;
    string tid;                                          //temporary
    gpid.open("pid.txt",ios::in);                        //create file to store AARC number
    gpid>>id;
    tid=to_string(id);                                   //conversion of int id from file to string
    pid=def+tid;                                         //def=AARC   pid=AARC+id
    id++;
    gpid.close();
    fstream wpid;
    wpid.open("pid.txt",ios::out);                       //open pid in read mode
    wpid<<id;
    wpid.close();

    createfile<<pid<<";"<<ptitle<<";"<<stplace<<";"<<endplace<<";"<<days<<";"<<exp<<";"<<endl;  //store in file
    createfile.close();

}

void packagelist::display()
{
    string ch;
    string pkg;
    fstream readfile;                                   //open file in read mode
    readfile.open("PackageList.txt",ios::in);
     cout<<"Package ID ";
    moveCursor(17,2);
    cout<<"Package Title";
     moveCursor(41,2);
    cout<<"Starting place";
    moveCursor(65,2);
    cout<<"End place";
    moveCursor(86,2);
    cout<<"No of days";
    moveCursor(100,2);
    cout<<"Expenses of package"<<endl;
    string line;
    int ct=-2;
    while(getline(readfile,line))
    {
        size_t pos;                                       //pos=position
        string temp;
        int count=0;
        while ((pos = line.find(';')) != string::npos)   //line string  ma ; khojera variable seperate garxa
        {
            temp=line.substr(0,pos);                    //temp ma line ko suru dekhi ; bhanda agadi ko string store garxa
            switch(count)                                // file bata line liyera ; bata xutaudai variable ma order ma save garxa
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
                days=stoi(temp);        //string to integer
                break;

            case 5:
                exp=stoi(temp);
                break;
            }
            line.erase(0,pos+1);    // 0 dekhi ; sama ko string erase garxa
            count++;
        }

        display1(ct);
        ct++;
    }
    readfile.close();
}

class itenary:public packagelist
{
    string things[max];
    int noft; //no of things (this value is use for the retrival of number of things stored in file)
public:
    void adddetail();    //add whole detail
    void viewdetail(string pkg);

};

void itenary::adddetail()
{
    string temp;
    int count=0;
    int no=1;
    fstream detail;
    detail.open("Detail.txt",ios::app);
    addpackage();                   //call addpackage function
    cin.ignore(100,'\n');       //clear the previous input buffer
    string dd[days];
    detail<<pid<<";"<<ptitle<<";"<<stplace<<";"<<endplace<<";"<<days<<";"<<exp<<";"<<endl;
    cout<<"Itinenary\n";
    for(int i=1; i<=days; i++)      //loop to take days detail as line and store in the dd[] string array
    {
        cout<<"Day "<<i<<":";
        getline(cin,dd[i-1]);
        detail<<dd[i-1]<<";";
    }
    detail<<endl;
    getch();

    cout<<"Things\t\t\tEnter ... after finished writing things to end\n";
    do                                 // loop to get things line by line ans store in the things[] string array until ... is hit or the max value is reached
    {
        cout<<no<<".";
        getline(cin,temp);
        if (temp=="...")
        {
            break;

        }
        things[count]=temp;  // store the line in things count element of the string array
        count++;
        no++;
    }
    while(count<max);

    system("pause");                        // pause the screen ans the process of the program until any key is hit from the keyboard
    for(int i=0; i<=count; i++)             // loop to store the contain of the array things[] in the file
    {
        detail<<things[i]<<";";
    }
    detail<<endl;
    detail.close();
}

void itenary::viewdetail(string pkg)
{
    bool check=false;
    string dd[max];  //array for days
    string tt[max];  //array for things
    fstream vdetail;
    vdetail.open("Detail.txt",ios::in);
    string vd1,vd2,vd3;
    while(getline(vdetail,vd1))//takes first line from file
    {
        size_t pos1,pos2,pos3;
        string temp1,temp2,temp3;
        int count=0;
        while((pos1=vd1.find(';')) != string::npos)
        {
            temp1=vd1.substr(0,pos1);
            switch(count)
            {
            case 0:
                pid=temp1;
                break;

            case 1:
                ptitle=temp1;
                break;

            case 2:
                stplace=temp1;
                break;

            case 3:
                endplace=temp1;
                break;

            case 4:
                days=stoi(temp1);
                break;

            case 5:
                exp=stoi(temp1);
                break;
            }
            vd1.erase(0,pos1+1);
            count++;
        }

        int count1=0;
        getline(vdetail,vd2);       //take second line from file(days)
        while((pos2=vd2.find(';')) != string::npos)
        {
            temp2=vd2.substr(0,pos2);
            dd[count1]=temp2;
            vd2.erase(0,pos2+1);
            count1++;
        }

        int count2=0;
        getline(vdetail,vd3);           //take third line from file(things)
        while((pos3=vd3.find(';')) != string::npos)
        {
            temp3=vd3.substr(0,pos3);
            tt[count2]=temp3;
            vd3.erase(0,pos3+1);
            count2++;
        }
        if(pkg==pid)
        {
            check=true;
            break;
        }


    }
    if(check==true)
    {
        cout<<"ID:"<<pid<<endl<<"Package title:"<<ptitle<<endl<<"Starting Place:"<<stplace<<endl<<"Destination:"<<endplace<<endl<<"Days:"<<days<<endl<<"Expenses:"<<exp<<endl<<"Itenenary\n";
        for(int i=0; i<days; i++) //to display days in console
        {
            cout<<"Day "<<i+1<<":"<<dd[i]<<endl;
        }
        cout<<"Important Things\n";
        int s=0;  //dummy value for things
        do    //to display things in console
        {
            cout<<s+1<<"."<<tt[s]<<endl;
            s++;
        }
        while(tt[s] !="\0");
    }
    else
    {
        cout<<"Invalid package id!!!!!!!!!!!!!!!!!!!";
    }

}

class customerDetail
{
    string boid; // booking id
    string name;
    string nationality;
    string address;
    string number;
    string pnumber;
    int lengthofnumber;
    string email;
    string dob;
    int mm,dd,yyyy;
    string payment;
public:
    void wbooking();
    void dbooking();

};

void customerDetail::wbooking()
{
    int id=1;
    string tid;
    fstream blist;
    blist.open("CDetail.txt",ios::app);
    cout<<"Fill the following information....\n";
    cout<<"Name:";
    getline(cin,name);
    cout<<"Nationality:";
    getline(cin,nationality);
    cout<<"Address:";
    getline(cin,address);
p:
    cout<<"Phone Number:";
    getline(cin,number);
    lengthofnumber=number.size();
    if(lengthofnumber==10)
    {
        pnumber=pn+number;
        cout<<pnumber<<endl;
    }
    else
    {
        cout<<"Enter 10 digit phone number:\n";
        goto p;
    }
    cout<<"Email:";
    getline(cin,email);
dob:
    cout<<"Date of Birth(MM/DD/YYYY):";
    cin>>mm>>dd>>yyyy;

    if((mm>12 || dd>32) ||(yyyy<1923 || yyyy>2023))
    {
        cout<<"Invalid date of birth\n";
        goto dob;
    }

    else
    {
        dob=to_string(mm)+db+to_string(dd)+db+to_string(yyyy);
        cout<<"DOB:"<<dob<<endl;
    }
    fstream rbid;
    rbid.open("boid.txt",ios::in);
    rbid>>id;
    rbid.close();
    tid=to_string(id);
    id++;
    fstream wbid;
    wbid.open("boid.txt",ios::out);
    wbid<<id;
    wbid.close();
    boid=bd+tid;
    blist<<boid<<";"<<name<<";"<<nationality<<";"<<address<<";"<<pnumber<<";"<<email<<";"<<dob<<";"<<endl;
    blist.close();
    system("CLS");
    moveCursor(30,12);
    cout<<"\t\t\tTHANK YOU FOR BOOKING\n";
    moveCursor(24,13);
    cout<<"\t\tNOTE:You will receive a call to confirm booking\n";
    getch();

}

void customerDetail::dbooking()  //ko ko le book garyo herne
{
    string dtl;  //detail
    fstream dlist;
    dlist.open("CDetail.txt",ios::in);
    while(getline(dlist,dtl))
    {
        size_t pos;
        string temp;
        int count=0;
        while((pos=dtl.find(';')) != string::npos)
        {
            temp=dtl.substr(0,pos);
            switch(count)
            {
            case 0:
                boid=temp;
                break;

            case 1:
                name=temp;
                break;

            case 2:
                nationality=temp;
                break;

            case 3:
                address=temp;
                break;

            case 4:
                pnumber=temp;
                break;

            case 5:
                email=temp;
                break;

            case 6:
                dob=temp;
            }
            dtl.erase(0,pos+1);
            count++;
        }
        cout<<boid<<endl;
        cout<<"\tFilled Information\n";
        cout<<"\tName:"<<name<<endl;
        cout<<"\tNationality:"<<nationality<<endl;
        cout<<"\tAddress:"<<address<<endl;
        cout<<"\tPhone number:"<<pnumber<<endl;
        cout<<"\tEmail:"<<email<<endl;
        cout<<"\tDate of birth:"<<dob<<endl;
    }
}
int main()
{
start:
    system("CLS");
    system("color e"); //give yellow color to letter
    char ch,ch1;
    string pkg;
    string keyword;
    packagelist p1;
    customerDetail c1;
    itenary i1;
    char c;
    cout<<" 1.List Package\n 2.Search Package\n 3.Login\n 4.Register\n 5.Exit\n";
    cout<<"Enter the case you wanna view:\n";
    c=getch();
    cout<<c<<endl;
    switch(c)
    {
    case '1':           //view the package
        // i1.adddetail();
        system("CLS");
        cout<<"Enter any key to list the itinenary\n";
        getch();
        p1.display();

        cout<<"Do you want to view the detail(Y/N):\n";
        ch=getch();
        cout<<ch<<endl;
        if(ch=='Y'||ch=='y')
        {
            cout<<"Enter the id of package you wanna display:";
            getline(cin,pkg);
            system("CLS");
            i1.viewdetail(pkg);
            cout<<"Do you want to book this package(Y/N):";
            ch1=getch();
            cout<<ch1<<endl;
            system("CLS");
            if(ch=='Y'||ch=='y')
            {
                c1.wbooking();
                system("CLS");
                c1.dbooking();
            }
        }
        else
        {
            goto start;
        }

        getch();
        break;

    case '2':
        system("CLS");
        moveCursor(50,0);
        cout<<"SEARCH ITINENARY\n\n";
        cout<<"Enter Keyword:";
        getline(cin,keyword);
        p1.searchpkg(keyword);
        system("pause");
        goto start;
    }

    return 0;
}
