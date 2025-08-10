#include <iostream>
#include "scanner.h"
#include <string>
#include "compiler.h"
#include "service.h"
#include <set>
#include <unordered_map>
#include <vector>

int main(){
    std::string name="hed.cpp";
    std::string path="./test/src";
    // std::string inc="compiler.h";
    // std::string path2="./inc/compiler.h";
    // std::unordered_map<std::string,std::vector<std::string>> dependencies;
    // std::unordered_map<std::string,std::string> path_to_header;
    // std::unordered_map<std::string,std::string> path_to_source;

    // Scanning Testing

    // cyon::Scanner scan(inc,path2);
    // std::vector<std::string> tra=scan.scan_imports();
    // for(auto j:tra){
    //     std::cout<<j;
    // }
    // std::cout<<"donme"<<std::endl;

    // std::cout<<"intial test  "<<cyon::get_file_path(inc)<<std::endl;


    ////Compiler Testing

   
    // path_to_header["scanner.cpp"]="sfafs";
    // path_to_source["scanner.cpp"]=" tyy";

    // cyon::compiler comp("./temp_object_files",dependencies,path_to_header,path_to_source);
    // comp.compile("scanner.cpp");


    //service testing

    cyon::scan_deps sdep(name,path);

    sdep.run_service();
    // sdep.print_paths();



    return 0;
}
