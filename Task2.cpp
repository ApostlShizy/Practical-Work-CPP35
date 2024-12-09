#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::vector<int> numbers{ 1,16,3,2,2,3,4,4,5,6,7,8,8,9,10,22,11,12,13,14,17,15,16,1 };

    auto makeUniqueNumber =  [] (std::vector<int> & numbers) {
        std::unordered_set<int> setNumbers;
        for (auto& current : numbers) {
            setNumbers.insert(current);
        }   
        std::vector<int> uniqueNumbers(setNumbers.begin(),setNumbers.end());
        return std::make_unique<std::vector<int>>(uniqueNumbers);
    };

    auto uniqueNumbers = makeUniqueNumber(numbers);
    
    for (auto& current : *uniqueNumbers) {
        std::cout << current << " ";
    }
    std::cout << std::endl;
}

