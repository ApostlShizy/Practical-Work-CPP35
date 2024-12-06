#include <iostream>
#include <vector>

template<typename T>
struct File {
    std::vector<T> data;
    File(std::initializer_list<T> inData) : data(inData) {}
};

int main() {
    File <int> someData{ 1,2,3,4,5 };
    for (auto& currentData : someData.data) {
        std::cout << currentData << std::endl;
    }
}