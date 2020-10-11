#include <string>
#include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::string &S) {
    // write your code in C++14 (g++ 6.2.0)

    const char* S_char = S.c_str();
    long long int num = std::strtoll(S_char, nullptr, 2);
    // return num;
    int counter = 0;

    while(num != 0) {
        if(num % 2 == 0) {
            num /= 2;
            counter++;
        }
        else {
            num--;
            counter++;
        }
    }

    return counter;

}

int main(int argc, char** argv) {
    // std::string str_num = "000000000000011100";
    std::string str_num = "1111010101111";
    std::cout << solution(str_num) << std::endl;
}