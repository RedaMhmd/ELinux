// #include <iostream>

// class def_init
// {
//     public:
//     // either define default consteuctor or not default init will happen leaving data member un initialized
//     // def_init() 
//     // {

//     // }
//     constexpr def_init(int par1, int par2)
//     {
//         x = par1;
//         y = par2;
//     }
//     void get()
//     {
//         std::cout<<x<<"    "<<y<<"\n";
//     }
//     private:
//     int x;
//     int y;
// };

// int main()
// {
//     int x;  //default init leaving it uninitialized
//     std::cout<< x << '\n';

//     // def_init ob1;
//     def_init ob2(10,20);

//     ob2.get();
// }


// #include <iostream>

// class MyClass {
//     int x;
//   // MyClass(int y) : x(y) {} // Default constructor
//   public:
//   MyClass()
//   {
//   }
//   int get(){return x;}
// };


// int main()
// {
//     MyClass obj {}; 
//   std::cout<<obj.get()<<"\n";
 	 
// }

#include <iostream>

class MyClass {
    int x;
  public:
  MyClass(int y) : x(y) {} // Default constructor
//   MyClass(){}
  int get(){return x;}
};


int main()
{
    MyClass obj {}; 
  std::cout<<obj.get()<<"\n";
 	 
}