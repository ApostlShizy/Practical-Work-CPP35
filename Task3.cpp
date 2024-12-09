#include <iostream>
#include <filesystem>
#include <vector>
#include <exception>

namespace fs = std::filesystem;

int main() {
    std::filesystem::path path("C:\\Develop");
    std::string extension = ".cpp";

    auto recursiveGetFileNamesByExtension = [](fs::path path,const std::string extension) {
        std::vector<std::string> allFiles;
        if (fs::exists(path)) {            
            std::cout << "\nPath exist\n\n";
            try {
                int maxFileCount = 1000;
                int count = 0;
                for (auto& current : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied)) {
                    if (count > maxFileCount) {
                        break;
                    }
                    if (current.is_regular_file() && !current.path().extension().compare(extension)) {
                        allFiles.push_back(current.path().filename().string());
                        ++maxFileCount;
                    }
                }
                return allFiles;
            }
            catch(const std::exception& X){
                std::cerr << "\nException cause " << X.what() << std::endl;
                return allFiles;
            }
        }
        else {
            std::cout << "\nPath not exist\n\n";
            return allFiles;
        }
    };

    auto allFiles = recursiveGetFileNamesByExtension(path, extension);
    for (auto& current : allFiles) {
        std::cout << current << std::endl;
    }
}