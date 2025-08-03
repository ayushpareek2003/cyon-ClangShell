
#ifndef service.h
#define service.h
#include <string>
#include <filesystem>
#include <iostream>

namespace cyon{
class scan_deps{
    private:
    std::string file_name;
    std::string path_to_main_file;
    std::string current_path;
    std::string compiled_dir="./temp_object_files";
    
    std::queue<string> _pending;

    std::unordered_map<string,string> path_to_header;
    std::unordered_map<string,string> path_to_source;

    std::set<string> in_process;
    std::set<string> is_processed;
    std::set<string> is_compiled;
    public:
        scan_deps(std::string &file_name,std::string &path_to_main_file):main_file(file_name),path_to_main_file(path_to_main_file){
            _pending.push(file_name);
            in_process.insert(file_name);
            path_to_file.insert(std::make_pair(file_name,path_to_main_file));
        }

        void create_temp_dir();
        void clear_temp_dir();

        void run_service();
        void fill_paths(std::string &_filename);

};
}


#endif