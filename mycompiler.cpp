#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include "service.h"
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: mycompiler <file-name> [directory]\n";
        return 1;
    }

    std::string fileName = argv[1];
    fs::path dirPath;

    if (argc >= 3) {
        // If directory is provided
        dirPath = argv[2];
    } else {
        // If no directory provided, use current dir
        dirPath = fs::current_path();
    }


    cyon::scan_deps sdep(fileName,dirPath);
    sdep.run_service();

    std::cout << "Compilation successful. Run: final_cyon.exe" << "\n";
    return 0;
}
