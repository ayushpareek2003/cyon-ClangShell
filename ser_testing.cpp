#include <iostream>
#include "scanner.h"
#include "utlis.h"
#include <string>
#include "compiler.h"

#include <set>
#include <unordered_map>
#include <vector>

int main(){
    std::string name="scanner.cpp";
    std::string path="./";


    // cyon::Scanner scan(name,path);
    // std::vector<std::string> tra=scan.scan_imports();
    // for(auto j:tra){
    //     std::cout<<j;
    // }
    // std::cout<<"out"<<std::endl<< scan.scan_imports();

            std::unordered_map<std::string,std::vector<std::string>> dependencies;
            std::unordered_map<std::string,std::string> path_to_header;
            std::unordered_map<std::string,std::string> path_to_source;


    cyon::compiler comp("./temp_object_files",dependencies,path_to_header,path_to_source);

    path_to_header["scanner.cpp"]="  sfafs";
    path_to_source["scanner.cpp"]=" tyy";
    comp.compile("scanner.cpp");
    return 0;
}
