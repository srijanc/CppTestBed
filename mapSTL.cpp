#include <iostream>
#include <map>
#include <unordered_map>

class HashMap {

    public:
        HashMap() {};
        ~HashMap() {};

        // Ordered HasMap:
        void orderedMap();

        // Un-Ordered HashMap:
        void unOrderedMap();
};

int main(int argc, char** argv) {
    HashMap hm;

    std::cout << "Ordered Map" << std::endl;
    hm.orderedMap();

    std::cout << "Un-Ordered Map" << std::endl;
    hm.unOrderedMap();
}

void HashMap::orderedMap() {
    std::map<std::string, int> ordMap;
    ordMap["srijan_ord"] = 24;

    // Check if key is present
    if(ordMap.find("hat") != ordMap.end())
        std::cout << "Map contains key: hat" << std::endl;

    // Retrieve
    std::cout << ordMap["srijan_ord"] << std::endl;
    std::map<std::string, int>::iterator i = ordMap.find("srijan_ord");

    // assert(i != m.end());
    std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;

}

void HashMap::unOrderedMap() {
    std::unordered_map<std::string, int> unOrdMap;

    unOrdMap["srijan_un"] = 24;

    // Check if key is present
    if(unOrdMap.find("hat") != unOrdMap.end())
        std::cout << "Map contains key: hat" << std::endl;

    // Retrieve
    std::cout << unOrdMap["srijan_un"] << std::endl;
    std::unordered_map<std::string, int>::iterator i = unOrdMap.find("srijan_un");

    // assert(i != m.end());
    std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;
}