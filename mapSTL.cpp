#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
// #include <sys/resource.h>
#include <unistd.h>
#include <string>
#include <stdexcept>
#include <memory>

class HashMap {

    public:
        // HashMap() {};
        // ~HashMap() {};

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

        // Array
        void ArrayTrial();
};

int main(int argc, char** argv) {
    std::cout << std::abs(2-5) << std::endl;
    // int i = 0, c = 0;
    // for(;i<10;)
    //     std::cout << __DATE__ << " : " << __TIMESTAMP__ << " : " << i++ << " = " << ++c << std::endl;
    // HashMap* hm = new HashMap();

    // std::cout << "Ordered Map" << std::endl;
    // hm->orderedMap_A();
    // hm->orderedMap_C();

    // std::vector<int> key, value;

    // // hm.orderedMap_D(hm.ordMap_BD);
    // // hm.orderedMap_B(hm.ordMap_BD);

    // std::cout << "Un-Ordered Map" << std::endl;
    // hm->unOrderedMap();

    // std::cout << "Array Trials" << std::endl;
    // hm->ArrayTrial();

    // std::cout << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << std::endl;

    // std::array<char, 128> buffer;
    // std::string cmdoutput;
    // // int pid = getpid();
    // std::string cmd = "cat /proc/" + std::to_string(getpid()) + "/stat | awk '{print $22}'"; //'{print int($22/100)}'";
    // // ls -ld /proc/23920 | awk '{print $6 " " $7 " " $8}'
    // std::unique_ptr<FILE, decltype(&pclose) > pipe(popen(cmd.c_str(), "r"), pclose);

    // if(!pipe) {
    //     throw std::runtime_error("[Error]: Failed to execute popen()");
    // }

    // while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    //     cmdoutput += buffer.data();
    // }

    // std::cout << cmdoutput << std::endl;

    // try {
    //         Server::compute(A, B);
    //     }
    // catch (std::bad_alloc& error) {
    //     std::cout << "Not enough memory" << std::endl;
    // }
    // catch (std::exception& error) {
    //     std::cout << "Exception" << error.what() << std::endl;
    // }
    // catch(...) {
    //     std::cout << "Other Exception" << std::endl;
    // }
}

void HashMap::ArrayTrial() {
    std::vector<void*> ak;
    std::vector<void*> av;
    std::vector<void*>::iterator it;
    std::map<int, std::string> testMap = {{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}};
    std::map<int, std::map<int, std::string>> nested = {{10, testMap}}; 

    std::map<int, std::map<int, std::string>>::iterator outIt = nested.find(10);
    std::map<int, std::string>::iterator inIt = outIt->second.begin();

    size_t size = 5;
    float a[size] = {2,5,3,4,1};

    nested[5] = nested[10];

    std::cout << "Current Size:" << nested.size() << std::endl;
    for(auto& v : nested)
        std::cout << "Old values: " << v.first << std::endl;

    for(auto& v : nested[5])
        std::cout << v.first <<" = " << v.second << std::endl;
    
    for(inIt; inIt != outIt->second.end(); inIt++)
        outIt->second.erase(inIt);

    if(outIt->second.size() == 0)
        nested.erase(outIt);

    std::cout << "New Size:" << nested.size() << std::endl;

    for(auto& v : nested)
        std::cout << "New values: " << v.first << std::endl;

    // std::sort(std::begin(a), std::end(a), std::greater<int>());
    // std::sort(a, a + size, std::greater<int>());
    // std::cout << a[0] << ", "<< a[4] << std::endl;

    // for(auto it = testMap.begin(); it != testMap.end(); it++) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    //     std::cout << "Key: " << (intptr_t)(void*)(intptr_t)it->first << ", Value: "
    //                             << static_cast<void*>(&it->second) << std::endl;

    //     ak.push_back((void*)(intptr_t)it->first);
    //     av.push_back(static_cast<void*>(&it->second));
    // }

    // std::cout << "Vector Key: " << ak[0] << std::endl;
    // for(it = ak.begin(); it != ak.end(); it++) {
    //     std::cout << it-> << std::endl;
    // }

    // std::cout << "Vector Value: " << &av[0] << std::endl;
    // for(it = av.begin(); it != av.end(); it++) {
    //     std::cout << it
    // }

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