
#ifndef service
#define service
#include <string>
#include <filesystem>
#include <iostream>
#include <queue>         
#include <unordered_map> 
#include <set>
#include "scanner.h"
#include "utlis.h"
#include "compiler.h"
namespace cyon{
class scan_deps{
    public:
        std::string file_name;
        std::string path_to_main_file;
        std::string current_path;
        std::string compiled_dir="temp";
        std::queue<std::string> _pending;

        // ToDo: better will be changing dependencies DS to tree like structure 
        std::unordered_map<std::string,std::vector<std::string>> dependencies;
        std::unordered_map<std::string,std::string> path_to_header;
        std::unordered_map<std::string,std::string> path_to_source;

        std::set<std::string> in_process;
        std::set<std::string> is_processed;
    
    
        scan_deps(std::string &file_name,std::string &path_to_main_file):file_name(file_name),
        path_to_main_file(path_to_main_file){
            _pending.push(file_name);
            // in_process.insert(file_name);
            path_to_header.insert(std::make_pair(file_name,path_to_main_file));
        }
        
        void run_service();
        void fill_paths(std::string _filename);
        void print_paths();

};
}


#endif