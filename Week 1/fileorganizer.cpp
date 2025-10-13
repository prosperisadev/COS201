// file organizer with C++

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void organizeFiles(const std::string& folderPath) {
    // Check if the folder exists
    if (!fs::exists(folderPath)) {
        std::cout << "The folder does not exist.\n";
        return;
    }

    // Iterate through all files in the folder
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            // Get the file path and extension
            std::string filePath = entry.path().string();
            std::string extension = entry.path().extension().string();

            // Skip files without an extension
            if (extension.empty()) continue;

            // Create a subfolder for the file type
            std::string subfolder = folderPath + "/" + extension.substr(1); // Remove the dot from the extension
            if (!fs::exists(subfolder)) {
                fs::create_directory(subfolder);
            }

            // Move the file to the subfolder
            std::string newFilePath = subfolder + "/" + entry.path().filename().string();
            fs::rename(filePath, newFilePath);
        }
    }

    std::cout << "Files organized successfully.\n";
}

int main() {
    std::string folderPath;
    std::cout << "Enter the folder path: ";
    std::cin >> folderPath;

    organizeFiles(folderPath);

    return 0;
}