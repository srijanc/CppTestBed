#include <algorithm>
#include <vector>
#include <iostream>

class Mako {
    public:

        int solution(std::vector<int> &A) {
            std::sort(A.begin(), A.end());
            A.erase(std::unique(A.begin(), A.end()), A.end());

            A.erase(std::remove_if(A.begin(), A.end(), []( int i ){ return i < 1; }), A.end());

            std::cout << "First Element: " << A[0] << std::endl;
            int counter = A[0];
            bool flag = false;
            std::uint64_t length = A.size();
            std::cout << "Last Element: " << A[length-1] << std::endl;

            if(counter != 1 || length == 0)
                return 1;

            for(std::uint64_t i = 0; i < length; i++) {

                if(A[i] != counter) {
                    flag = true;
                    return counter;
                }
                std::cout << "Vector: " << counter << std::endl;
                counter++;
            }

            if(flag == false) {
                if(counter > 0) {
                    return counter;
                }

                else {
                    while(counter++ <= 0) {}

                    if(--counter > 0)
                        return counter;
                }
            }
            else {
                return (-1);
            }
        }
};

int main(int argc, char** argv) {
    Mako* m = new Mako();
    // std::vector<int> A = {1, 2, 3};
    // std::vector<int> A = {-1, -3};
    // std::vector<int> A = {1, 3, 6, 4, 1, 2};
    // std::vector<int> A = {1, 3, -6, 4, -1, 2};
    std::vector<int> A = {0};
    // std::vector<int> A = {99, 77, 88};
    // std::vector<int> A = {-10000000, 10000000};
    std::cout << m->solution(A) << std::endl;
}