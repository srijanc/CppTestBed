#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    if(N > 100000000)
        return -1;
        
    if(N < 11)
        return N;

    std::vector<int> N_vect;
    int counter = 0;
    while (N != 0) {
        N_vect.push_back(N % 10);
        N = N/10;
        counter ++;
    }

    std::sort(N_vect.begin(), N_vect.end(), std::greater <>());

    int largest = 0;
    for(std::size_t i = 0; i < N_vect.size(); i++) {
        largest = largest * 10 + N_vect[i];
    }

    return largest;
}

int main(int argc, char** argv) {
    std::cout << solution(255) << std::endl;
}