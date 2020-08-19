#include <iostream>
#include <map>
#include <unordered_map>

class HashMap {

    public:
        HashMap() {};
        ~HashMap() {};

        std::map<std::string, int> ordMap;
        std::map<std::string, int>* ordMap_BD;
        std::unordered_map<std::string, int> unOrdMap;

        // Ordered HasMap:
        void orderedMap_A();    // Update map
        void orderedMap_B(std::map<std::string, int>* ordMap_B);    // Update map
        void orderedMap_C();    // Update or Print map values
        void orderedMap_D(std::map<std::string, int>* ordMap_D);

        // Un-Ordered HashMap:
        void unOrderedMap();
};

int main(int argc, char** argv) {
    HashMap hm;

    std::cout << "Ordered Map" << std::endl;
    hm.orderedMap_A();
    hm.orderedMap_C();

    // hm.orderedMap_D(hm.ordMap_BD);
    // hm.orderedMap_B(hm.ordMap_BD);

    std::cout << "Un-Ordered Map" << std::endl;
    hm.unOrderedMap();
}

void HashMap::orderedMap_A() {
    ordMap.insert(std::pair<std::string, int> ("srijan_A", 24));

    // Check if key is present
    // if(ordMap_A.find("hat") != ordMap_A.end())
    //     std::cout << "Map contains key: hat" << std::endl;

    // Retrieve
    // std::cout << ordMap_A["srijan_ord"] << std::endl;
    // std::map<std::string, int>::iterator i = ordMap_A.find("srijan_ord");
    // assert(i != m.end());
    // std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;
}

void HashMap::orderedMap_C() {
    ordMap.insert(std::pair<std::string, int> ("srijan_C1", 26));
    ordMap["winner_winner_chicken_dinner"] = 10000;

    for(auto it = ordMap.begin(); it != ordMap.end(); it++) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

// Wrong Function:
void HashMap::orderedMap_B(std::map<std::string, int>* ordMap_B) {
    ordMap_B->insert(std::pair<std::string, int> ("srijan_B", 25));

    for(auto it = ordMap_B->begin(); it != ordMap_B->end(); it++) {
        std::cout << "Key_B: " << it->first << ", Value_B: " << it->second << std::endl;
    }
}

// Wrong Function:
void HashMap::orderedMap_D(std::map<std::string, int>* ordMap_D) {
    ordMap_D->insert(std::pair<std::string, int> ("srijan_D", 27));
}

void HashMap::unOrderedMap() {
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