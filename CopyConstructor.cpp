#include <iostream>

class MyClass {
public:
    MyClass() {
        data_ = new char[24 * 1024 * 1024];
    }

    ~MyClass() {
        delete[] data_;
    }

    MyClass(const MyClass& mc) {
        data_ = mc.data_;
    }

private:
    char* data_;
};