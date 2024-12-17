#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

int main() {
    std::filesystem::path path("C:\\Develop");
    std::string extension = ".cpp";

    auto recursiveGetFileNamesByExtension = [](fs::path path,const std::string extension) {
        std::vector<std::string> allFiles;
        if (fs::exists(path)) {
            std::cout << "\nPath exist\n\n";
            int maxFileCount = 1000;
            int count = 0;
            for (fs::recursive_directory_iterator current = fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied); 
                current != fs::recursive_directory_iterator();
                ++current) 
            {
                if (current.depth() > 3) {
                    std::cout << "\nTo Deep directories\n";
                    continue;
                }
                if (count > maxFileCount) {
                    std::cout << "\nRithch max files count\n";
                    break;
                }
                if (current->is_regular_file() && !current->path().extension().compare(extension)) {
                    allFiles.push_back(current->path().filename().string());
                    ++maxFileCount;
                }
            }
            return allFiles;
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