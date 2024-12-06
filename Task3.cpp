#include <iostream>
#include <filesystem>
#include <vector>

int main() {
    std::filesystem::path path("C:\\DevelopRepeat");
    std::string extension = ".cpp";

    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path,const std::string extension) {
        std::vector<std::string> allFiles;
        for (auto& current : std::filesystem::recursive_directory_iterator(path)) {            
            if (current.is_regular_file() && !current.path().extension().compare(extension)) {
                allFiles.push_back(current.path().filename().string());
            }            
        }
        return allFiles;
    };

    auto allFiles = recursiveGetFileNamesByExtension(path, extension);
    for (auto& current : allFiles) {
        std::cout << current << std::endl;
    }
}

