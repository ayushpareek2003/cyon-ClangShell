#ifndef scanner
#define scanner
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

namespace cyon{
    class Scanner{
        private:
            std::string file_name;
            std::string path_to_file;
            std::string base_command = "awk '/#include \"[^\"]+\"/ { match($0, /\"([^\"]+)\"/, arr); if (arr[1] != \"\") print arr[1] }'";

        public:
        Scanner(std::string &file_name,std::string path_to_file):file_name(file_name),path_to_file(path_to_file){
        }

        std::vector<std::string> scan_imports();
    };

    std::string get_file_path(const std::string &file_name);
}

#endif 