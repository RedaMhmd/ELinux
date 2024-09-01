#include <iostream>
#include <list>
#include <memory>

using namespace std;
template <typename T>
class mylist
{
    private:
    std::list<T> m_l;
    static int m_objnum;
    public:
    mylist(std::initializer_list<T> il = {}): m_l{il}
    {
        m_objnum++;
        std :: cout << m_objnum <<" il para const\n";
    }
    mylist(const mylist<T> & list ) : m_l{list.b}
    {
        cout <<"copy\n";
    }
    operator std::unique_ptr<T> () 
    {
        if (!m_l.empty())
        {
            return std::make_unique<T> (m_l.front());
        }
        else
        {
            return nullptr;
        }
    }
};
template <typename T>
int mylist<T>::m_objnum = 0;
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
    
    mylist<int> lll = mylist<int>({11,21,31});

    mylist<int> lll2({1,2,3});
    // for (auto i : lll2 )
    // {
    //     std::cout<<i<<std::endl;
    // }
    // lll2 = mylist<int>({1,2,3});
    unique_ptr<int> ptr {lll};

    std :: cout << "\n\n\n";
    std::cout<<*ptr<< "\n\n\n" ;
    return 0;
}