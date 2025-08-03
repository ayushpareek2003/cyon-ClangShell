#include <iostream>
#include "scanner.h"
#include "utlis.h"
#include <string>



int main(){
    std::string name="scanner.cpp";
    std::string path="./";


    // cyon::Scanner scan(name,path);
    // std::vector<std::string> tra=scan.scan_imports();
    // for(auto j:tra){
    //     std::cout<<j;
    // }
    // std::cout<<"out"<<std::endl<< scan.scan_imports();


    
    std::cout<<cyon::get_file_path(name)<<std::endl;
    return 0;
}
