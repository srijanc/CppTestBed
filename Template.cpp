#include <iostream>

template <class T>
class AddValue {
private:
    T a;
    T b;

public:
    AddValue(const T& v1, const T& v2) : a(v1), b(v2) {}
    void sum() {
        std::cout << "Sum: " << a + b << std::endl;
    }
    void concat() {
        std::cout << "Concat: " << a + b << std::endl;
    }
};

template <typename T>
void print(const T& t) {
    std::cout << "Printing any type: " << t << std::endl;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    AddValue<int> sum_int(a, b);
    sum_int.sum();

    std::string c, d;
    std::cin >> c >> d;
    AddValue<std::string> concat_string(c, d);
    concat_string.concat();

    print("TypeMe");
    print(2);
}