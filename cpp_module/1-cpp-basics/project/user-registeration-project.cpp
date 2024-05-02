

/**
 * dependencies
*/
#include <iostream>
#include <array>
#include <string>


/**
 * definitions
*/

//1- variables
constexpr int MAX_USER_NUM = 100;
constexpr int START_INDEX = 0;

int newUserIndex = START_INDEX;
int currentUserNUM = 0;


enum class option
{
    ADD_RECORD = 1,
    FETCH_RECORD = 2,
    EXIT = 3
};

//2- functions

//operator+ overloading (sting + integer)
std::string operator +(std::string str1, int str2);


//
void print_msg(std::string msg);
void print_msg(int msg);

void add_record();
void fetch_record();




//3- User defind classes

class User
{
    public:
    //attributes (variables)
    int id;
    std::string name;
    int age;

    //functions
    void set_data(int c_id, std::string c_name, int c_age)
    {
        id = c_id;
        name = c_name;
        age = c_age;
    }

    void show_record()
    {
        print_msg("/////////////////////////////////////////\n");
        print_msg("/////////////////////////////////////////\n");
        print_msg ( std::string ("user information: \n") );
        print_msg ( std::string ("1- User ID: " ) + id );
        print_msg("\n");
        print_msg ( std::string ("2- User Name: " ) + name );
        print_msg("\n");
        print_msg ( std::string ("3- User Age: ") + age );
        print_msg("\n");
        print_msg("/////////////////////////////////////////\n");
        print_msg("/////////////////////////////////////////\n");
    }

};


class Application
{
    public:
    void show_options(void)
    {
        print_msg("/////////////////////////////////////////\n");
        print_msg("/////////////////////////////////////////\n");
        print_msg("User SignUp Application\n");
        print_msg( "1- Add Record\n"   );
        print_msg( "2- Fetch Record\n" );
        print_msg( "3- Exit\n"  ); 
        print_msg("/////////////////////////////////////////\n");
        print_msg("/////////////////////////////////////////\n");

    }
};

// operator overloading
std::istream&  operator >> (std::istream& is, option& output);

std::array<User,100> users;
option DEFAULT_OPTION = option::ADD_RECORD;


int main()
{
    Application myapp;
    option userOption = DEFAULT_OPTION ; 
    bool isRunning = true;
    while (isRunning)
    {
        myapp.show_options();
        print_msg("please Select an Option: ");
        
        std::cin >> userOption;
        switch (userOption)
        {
            case option::ADD_RECORD:
                {
                    add_record();                    
                }break;
            case option::FETCH_RECORD:
                {
                    fetch_record();
                }break;
            case option::EXIT:
                {
                    isRunning = false;
                }break;
        
            default:
                break;
        }
    }
    
    

    return 0;
}

void add_record()
{
    int id; std::string name; int age;
    print_msg("please enter user iformation: \n");
    print_msg("1- User name: ");
    std::cin >> name;
    print_msg("2- User age: ");
    std::cin >> age;
    print_msg("3- Select your ID: ");
    std::cin >> id;
    users[newUserIndex++].set_data(id, name, age);
    currentUserNUM++;
}


void fetch_record()
{
    int id = 0;
    print_msg("enter your ID: ");
    std::cin >> id;
    for (int i = 0; i < currentUserNUM; ++i)
    {
        if (users[i].id == id)
        {
            users[i].show_record();
            return;
        }
    }
    print_msg("User not found.\n");
}



void print_msg(std::string msg)
{
    std::cout << msg ;
}
void print_msg(int msg)
{
    std::cout << msg ;
}

//operator overloading
std::string operator+(std::string str1, int str2)
{
    return str1.append(std::to_string(str2));
}

std::istream&  operator >>(std::istream& is, option& output)
{
    int temp;
    is >> temp;
    output = static_cast<option> (temp);
    return is;
}