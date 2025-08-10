#include "compiler.h"


cyon::compiler::compiler(
     std::string& compiled_dir,
     std::unordered_map<std::string, std::vector<std::string>>& dependencies,
     std::unordered_map<std::string, std::string>& path_to_header,
     std::unordered_map<std::string, std::string>& path_to_source
)
    : compiled_dir(compiled_dir),
      dependencies(dependencies),
      path_to_header(path_to_header),
      path_to_source(path_to_source)
{
    create_dir();
    
}

void cyon::compiler::execute(){

    for(auto itr=dependencies.begin();itr!=dependencies.end();itr++){
        compile(itr->first,itr->second);
    }

    linker _linker(compiled_dir,object_files);
    
    
}

void cyon::compiler::create_dir(){
    if(!fs::exists(compiled_dir)){
        if(fs::create_directory(compiled_dir)){
            std::cout<<"temp folder for object files created at "<<std::endl;
        }
        else{
            std::cerr<<"Failed to create"<<std::endl;
        }
    }
    else{
         std::cout<<"Already Exists"<<std::endl;
    }
}

std::string cyon::compiler::trim_path(std::string path_to_file){
        if (path_to_file.size() > 2 && (path_to_file.compare(path_to_file.size()-2, 2, ".h") == 0 ||
                                path_to_file.compare(path_to_file.size()-4, 4, ".cpp") == 0)){
            path_to_file.erase(path_to_file.find_last_of('/'));
            path_to_file.erase(path_to_file.find_last_not_of(" \n\r\t") + 1);
            return path_to_file;
        }
        std::cout<<"Problem with the path"<<std::endl;
        return "";     
} 

std::string cyon::compiler::trim_name(std::string name){
        if (name.size() > 2 && (name.compare(name.size()-2, 2, ".h") == 0 ||
                                name.compare(name.size()-4, 4, ".cpp") == 0)){
            name.erase(name.find_last_of('.'));
            name.erase(name.find_last_not_of(" \n\r\t") + 1);
            return name;
        }
        std::cout<<"Problem with the file name"<<std::endl;
        return ""; 

}


void cyon::compiler::compile(std::string _file_name,std::vector<std::string> _dependencies){
    std::string name=trim_name(_file_name);
    
    std::string header_inc="";
    for(auto _dep:_dependencies){
        _dep.erase(_dep.find_last_not_of(" \n\r\t") + 1);
        header_inc+= "-I"+trim_path(path_to_header[_dep])+" ";
    }


    std::string _cli= base_command + path_to_source[name+".cpp"]+ " "+header_inc+" -o "+ compiled_dir+"/"+name+".o";
    object_files.push_back(name+".o");
    run_command(_cli);
}

void cyon::compiler::run_command(std::string command){
    FILE* pipe=popen(command.c_str(),"r");
}