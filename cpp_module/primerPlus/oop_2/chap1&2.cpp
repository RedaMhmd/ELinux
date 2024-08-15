#include <iostream>
#include <initializer_list>


/***
 * initilaizer list: class template used to crate light weight object with a list of values
 * used to initialize vars, arrays, fun parameters, constructors and std containers
 * properties:
 * 1- implemented as a wrapper over array
 * 2- size can not be changed 
 * 3- no random access
 * 4- immutabke elemets:
 *      once created values can nor be changed any attemped : compilation error.
 * 5- in case of you assign another list :
 *      you do not copy the elemets  but you copy  reference, But both the original and copied object of the initializer list contain the same elements.
 * 6- it has a ptivate constructors the compiler can call,
 *      the compiler convert the braced list into a const arrary and pass that array to its constructor
 * 
 * 
 * 
 * usaged (application )
 * 1- function parameters:
 *      used to pass a variable numers of argument
 * 4- as a return type to return list of values
 * 2- store data in contigous memory
 * 3- initialize std containers
 * 
*/


class Id
{
    int m_id;
    public:
    Id(int id = 0);
    Id(const Id & lhs);
    int getId();
    Id & operator=(const Id & lhs);
};
Id & Id::operator=(const Id & lhs)
{
    std::cout<<"no default\n";
    m_id = lhs.m_id;
    return *this;
}
int Id::getId()
{
    return m_id;
}
Id::Id(const Id & lhs)
{
    std::cout << "copy\n";
    m_id = lhs.m_id;
}
Id::Id(int id)
{
    m_id = id;
}

class Students
{
    std::initializer_list<std::string> m_students;
    public:
    Students(){};
    Students(std::initializer_list<std::string> students): m_students(students)
    {

    }
    void print()
    {
        for (auto i:m_students)
        {
            std::cout << i<<std::endl;
        }
    }
};
int main()
{
    Id id1 = 5;    /// in initialization will not create a temp object according o c++17 will  be optimized and object inintialized directly
    std::cout << id1.getId() <<'\n';
    id1 = 30;  // use constructor to convert 1 to object type and then use equal operator 
    std::cout << id1.getId() <<'\n';

    using std::cout;
    std::initializer_list<int> ls {1,2,3,4,5,6};
    std::initializer_list<int> l (ls);  //  here copy constructors is called, can not initializw 
    for(auto i:l)
    {

    cout << i<<std::endl;
    }
    std::initializer_list<std::string> s {"reda", "mhmf"};
    Students class1  {s};
    class1.print();
    return 0;
}