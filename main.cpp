#include <iostream>
#include <conio.h>
#include <graphics.h>

class travel{
    int package_id;
    std::string package_title;
    std::string starting_place;
    std::string destination;
    int days;
    int Expenses;

    public:
    void add_package();
    void edit_package();
    void del_package();
    void user_mng();
    void check_booking();
};

int main(){
    int choice;
    std::cout<<"Admin Dashboard\n\n";
    std::cout<<"1. Add Package\n";
    std::cout<<"2. Edit Package\n";
    std::cout<<"3. Delete Package\n";
    std::cout<<"4. User Management\n";
    std::cout<<"5. Check Bookings\n";
    std::cout<<"6. Logout\n\n\n";
    std::cout<<"Enter Your Choice: ";
    std::cin>>choice;
    switch(choice){
        case 1:
        std::cout<<"Add Package";
        break;
        case 2:
        std::cout<<"Edit Package";
        break;
        case 3:
        std::cout<<"Delete Package";
        break;
        case 4:
        std::cout<<"User Management";
        break;
        case 5:
        std::cout<<"Check Booking";
        break;
        case 6:
        std::cout<<"Login";
        break;
    }

    return 0;
}

void travel::add_package(){
    std::cout<<"Add Package";
}