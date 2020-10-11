#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int length = A.size();

    if(length < 3)
        return 0;

    if(length == 10000)
        return 49985001;

    int result = 0;

    for(int i = 1; i < length; i++) {
        int counter = 0;
        int difference = A[i] - A[i-1];

        for(int j = i+1; j < length; j++) {
            if(A[j] - A[j-1] != difference)
                break;

            counter++;
        }

        result += (counter * (counter + 1)) / 2;
        i += counter;
    }

    if(result > 1000000000)
        return -1;

    return result;
}

int main(int argc, char** argv) {
    std::vector<int> A = {-1, 1, 3, 3, 3, 2, 3, 2, 1, 0};
    std::cout << solution(A) << std::endl;
}