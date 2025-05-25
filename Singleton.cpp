#include <iostream>

class Singleton {
private:
    float IFloat() {
        return m_random;
    }
    Singleton();

    float m_random = 0.5f;

    static Singleton s_Instance;

public:
    Singleton(const Singleton&) = delete;

    static Singleton& Get() {
        return s_Instance;
    }

    static float Float() {
        return Get().IFloat();
    }
};

Singleton Singleton::s_Instance;
Singleton::Singleton() {}

int main() {
    // Singleton s = Singleton::Get();     // Cant do it as copy constructor is deleted
    Singleton& s = Singleton::Get();    // We need to explicitly use reference
    float number = Singleton::Float();

    std::cout << number << std::endl;
}
