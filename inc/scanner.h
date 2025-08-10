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
            std::string file_dir;
            std::string base_command = "awk '/#include \"[^\"]+\"/ { match($0, /\"([^\"]+)\"/, arr); if (arr[1] != \"\") print arr[1] }'";

        public:
        Scanner(std::string &file_name,std::string path_to_file):file_name(file_name){
            std::cout<<path_to_file<<std::endl;
            if (path_to_file.size() > 2 && (path_to_file.compare(path_to_file.size()-2, 2, ".h") == 0 ||
                                path_to_file.compare(path_to_file.size()-4, 4, ".cpp") == 0)){
    path_to_file.erase(path_to_file.find_last_of('/'));
                                }

            std::cout<<path_to_file<<std::endl;                    
            
           
            file_dir=path_to_file;
        }


        std::vector<std::string> scan_imports();
    };

    std::string get_file_path(std::string &file_name);
}

#endif 