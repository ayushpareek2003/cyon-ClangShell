#include "scanner.h"

std::vector<std::string> cyon::Scanner::scan_imports(){
    
    std::vector<std::string> result;
    std::string command_temp=base_command +" "+ file_name;
    char buffer[128];
            

    FILE* pipe=popen(command_temp.c_str(),"r");
    if(!pipe) {
        std::cout<<"Error while scanning";
        return {};
    }

    while(fgets(buffer,sizeof(buffer),pipe)!=nullptr){
        if(buffer.substr(buffer.length()-3)==".cpp"){
            result.push_back(buffer.substr(0,buffer.length()-3));
        }
        else{
            result.push_back(buffer.substr(0,buffer.length()-2));

        }
    }

    pclose(pipe);
    return result;
            
}

std::string cyon::get_file_path(const std::string &file_name){
    fs::path currentDir="."; //we will make it from top level dir

    for(const auto &entry:fs::recursive_directory_iterator(currentDir)){
        if(entry.is_regular_file() && entry.path().filename()==file_name){
            return entry.path();
        }
    }

    return "";
}