#include <iostream>
#include <string>
class Stock
{
    private:
    std::string m_name;
    int m_shares;
    public:
    Stock()
    {
        std::cout << "default constructor"<< '\n';

        m_name = "reda";
        m_shares = 0;
    }
    Stock(std::string name, int shares)
    {
        std::cout << "para constructor"<< '\n';
        m_name = name;
        m_shares = shares;
    }
    ~Stock()
    {
        std::cout << "destructor is called"<< '\n';
    }
};

int main()
{



    Stock ahm = Stock ("reda", 20); 
    Stock reda;
    Stock reda1 ("mhmd", 15);

    return 0;
}