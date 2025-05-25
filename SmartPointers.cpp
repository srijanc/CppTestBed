#include <iostream>
#include <memory>

class SmartPointers {
private:
    int test;

public:
    SmartPointers();
    ~SmartPointers();
};

SmartPointers::SmartPointers() {
    std::cout << "Constructed" << std::endl;
}

SmartPointers::~SmartPointers() {
    std::cout << "Destructed" << std::endl;
}

int main() {
    std::shared_ptr<SmartPointers> shared_ptr1;
    {
        {
            std::unique_ptr<SmartPointers> unique_ptr = std::make_unique<SmartPointers>();
        }
        std::shared_ptr<SmartPointers> shared_ptr = std::make_shared<SmartPointers>();
        // shared_ptr1 = shared_ptr;
        std::weak_ptr<SmartPointers> weak_ptr = shared_ptr;
        std::cout << weak_ptr.expired() << std::endl;
        std::cout << shared_ptr.use_count() << std::endl;
        std::cout << shared_ptr.unique() << std::endl;
    }

    std::cin.get();
}
