#include "scanner.h"

std::string cyon::Scanner::scan_imports(){
    
    std::string result;
    std::string command_temp=base_command +" "+ file_name;
    char buffer[128];
            

    FILE* pipe=popen(command_temp.c_str(),"r");
    if(!pipe) {
        return "error aagya h";
    }

    while(fgets(buffer,sizeof(buffer),pipe)!=nullptr){
        result+=buffer;
    }

    pclose(pipe);
    return result;
            
}