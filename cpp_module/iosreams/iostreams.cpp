#include <iostream>

// Simple custom manipulator
std::ostream& customSeparator(std::ostream& os) {
    std::cout << "rda";
    return os ;
}

int main() {
    std::cout  << std::cout. precision(2)<<1.23 <<std::endl;
    std::cout.width(10);
    std::cout << 10 << std::endl;
    std::cout << 10 << std::endl<<std::cout.width();
    return 0;
}
