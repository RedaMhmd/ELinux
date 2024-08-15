#include <iostream>
#include <list>
#include <memory>

template <typename T>
class mylist
{
    private:
    std::list<T> m_l;
    public:
    mylist(std::list<T> l = {}): m_l{l}
    {

    }
};
    operator std::unique_ptr<T> () (return m_l.begin();)


int main()
{
    using std::list;
    list<int> l {1,2,3,4,5};
    for (list<int>::iterator i = l.begin(); i != l.end(); i++)
    {
        std::cout<<*i<<std::endl;
    }
    std :: cout << "\n\n\n";

    for (auto i: l)
    {
        std::cout<<i<<std::endl;
    }

    std::cout<<*l;
    return 0;
}