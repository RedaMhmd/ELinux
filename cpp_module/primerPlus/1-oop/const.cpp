#include <iostream>

class ll
{
    int m_x;
    public:
    ll()
    {
        std::cout <<"ll default\n";
    }
    ll(int x) : m_x{x}
    {
        // m_x = x;
        std::cout << "ll 2 con\n";
    }
};
class mm
{
    int x;
    ll m;
    public:
    mm() : m{5} // here direct list initialization call para constrct directly
    {
        std::cout << "mm def cons\n";
        // m = 5;  // will call default consructor then para constructor 
    }
};

int main()
{
    mm x;
    return 0;
}