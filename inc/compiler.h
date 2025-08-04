#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
namespace cyon{
    class compiler{
        private:
            std::string compiled_dir;
            std::string base_command="clang++ -c ";
            std::unordered_map<std::string,std::vector<std::string>> dependencies;
            std::unordered_map<std::string,std::string> path_to_header;
            std::unordered_map<std::string,std::string> path_to_source;
            std::set<std::string> is_compiling;
            std::set<std::string> is_compiled;

        public:
            compiler(
                const std::string& compiled_dir,
                const std::unordered_map<std::string, std::vector<std::string>>& dependencies,
                const std::unordered_map<std::string, std::string>& path_to_header,
                const std::unordered_map<std::string, std::string>& path_to_source
            );

            void execute();

            void compile(std::string _file_name);


        
    };
}

