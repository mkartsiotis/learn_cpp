#include <iostream>

int main() {
    int a = 100;
    int b = 50;
    int temp = a;
    a = b;
    b = temp;
    std::cout << a  << "\n" << b << "\n"; //Statement return 0; 
}
