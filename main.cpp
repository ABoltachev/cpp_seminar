#include <string>
#include <iostream>

#include <testlib/utils.hpp>
#include <map>
#include <vector>
#include <testlib/patterns.hpp>
#include <memory>
#include <thread>

void test(std::string name){
    std::shared_ptr singleton = Singleton::instance();
    singleton->set_name(name);
    singleton->print();

}

int main() {
    std::map<int, int> dict = {
        std::make_pair(1, 2)
    };
    for (auto&& [key, value] : dict) {
        std::cout << "Key: " << key << ", value: " << value << std::endl;
    }

    int i = 0;
    i++; // i + 1;
    ++i; // 1 + i;

    std::vector<int> vect = {5, 6, 7};
    for (auto &&[i, item] : enumerate(vect)) {
        std::cout << "Idx: " << i << ", value: " << item << std::endl;
    }

    for (int i : range(10)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::thread t1(test, "test1");
    std::thread t2(test, "test2");

    t1.join();
    t2.join();


    // for (auto it = vect.begin(); it != vect.end(); it++) {
    //     ;
    // }
    return 0;
}
