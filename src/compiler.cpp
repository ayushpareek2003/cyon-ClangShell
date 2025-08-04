#include "compiler.h"

cyon::compiler::compiler(
    const std::string& compiled_dir,
    const std::unordered_map<std::string, std::vector<std::string>>& dependencies,
    const std::unordered_map<std::string, std::string>& path_to_header,
    const std::unordered_map<std::string, std::string>& path_to_source
)
    : compiled_dir(compiled_dir),
      dependencies(dependencies),
      path_to_header(path_to_header),
      path_to_source(path_to_source)
{}

void cyon::compiler::execute(){
    // for(auto itr=dependencies.rbegin();itr!=dependencies.rend();itr++){

    //     for(std::string _dep:itr->second){
    //         if(dependencies.count(_dep)==0 || dependencies[_dep].size()==0){
    //             compile(_dep);

    //         }
    //         else if(is_compiling.count(_dep)>0 || is_compiled.count(_dep)>0){
    //             continue;
    //         }
    //         else{
    //             is_compiling.insert(_dep);
    //         }
    //     }

    // }
}


void cyon::compiler::compile(std::string _file_name){
    std::string _cli= base_command + path_to_source[_file_name]+ " -I"+path_to_header[_file_name] +" -o "+ compiled_dir+"/"+_file_name;

    std::cout<<_cli;

    // FILE* pip
}