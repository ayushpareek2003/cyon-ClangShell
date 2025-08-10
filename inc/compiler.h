#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
#include <filesystem>
#include "linker.h"
namespace fs = std::filesystem;
namespace cyon{
    class compiler{
        private:
            std::string compiled_dir;
            std::string base_command="clang++ -std=c++20 -c ";
            std::unordered_map<std::string,std::vector<std::string>> dependencies;
            std::unordered_map<std::string,std::string> path_to_header;
            std::unordered_map<std::string,std::string> path_to_source;
            std::set<std::string> is_compiling;
            std::set<std::string> is_compiled;
            std::vector<std::string> object_files;

        public:
            compiler(
                 std::string& compiled_dir,
                 std::unordered_map<std::string, std::vector<std::string>>& dependencies,
                 std::unordered_map<std::string, std::string>& path_to_header,
                 std::unordered_map<std::string, std::string>& path_to_source
            );

            void execute();
            void create_dir();
            void remove_dir();
            void compile(std::string _file_name,std::vector<std::string> _dependencies);
            void run_command(std::string command);
            // void run_compilation();
            
            std::string trim_path(std::string path_to_file);
            std::string trim_name(std::string name);
        };
}

