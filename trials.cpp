#include <iostream>
#include "scanner.h"
#include <string>



int main(){
    std::string name="trials.cpp";
    std::string path="./";
    cyon::Scanner scan(name,path);
    std::cout<<"out"<<std::endl<< scan.scan_imports();
    return 0;
}
