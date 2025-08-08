#include <iostream>
#include "scanner.h"
#include "utlis.h"
#include <string>
#include "compiler.h"
#include "service.h"
#include <set>
#include <unordered_map>
#include <vector>

int main(){
    std::string name="ser_testing.cpp";
    std::string path="./";

    std::unordered_map<std::string,std::vector<std::string>> dependencies;
    std::unordered_map<std::string,std::string> path_to_header;
    std::unordered_map<std::string,std::string> path_to_source;

    // Scanning Testing

    // cyon::Scanner scan(name,path);
    // std::vector<std::string> tra=scan.scan_imports();
    // for(auto j:tra){
    //     std::cout<<j;
    // }


    ////Compiler Testing

   
    // path_to_header["scanner.cpp"]="sfafs";
    // path_to_source["scanner.cpp"]=" tyy";

    // cyon::compiler comp("./temp_object_files",dependencies,path_to_header,path_to_source);
    // comp.compile("scanner.cpp");


    //service testing

    cyon::scan_deps sdep(name,path);
    sdep.run_service();
    sdep.print_paths();



    return 0;
}
