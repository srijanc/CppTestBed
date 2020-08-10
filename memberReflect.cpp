#include <iostream>


class Reflect{
public:
    int x = 0;
    int y = 2;

    void changeValue(int a, int b);

    void changeValueAgain(int c, int d);
};

void Reflect::changeValue(int a, int b) {
    y = y + b;
    x = x + a;

    std::cout << "First value change" << std::endl;
    std::cout << "X = " << x << std::endl;
    std::cout << "Y = " << y << std::endl;
}

void Reflect::changeValueAgain(int c, int d) {
    y = y + d;
    x = x + c;

    std::cout << "Second value change" << std::endl;
    std::cout << "X = " << x << std::endl;
    std::cout << "Y = " << y << std::endl;
}

int main(int argc, char** argv) {
    Reflect rf;

    rf.changeValue(2, 4);

    rf.changeValueAgain(6, 8);
}