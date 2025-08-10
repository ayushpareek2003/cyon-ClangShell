
#include "service.h"


void cyon::scan_deps::create_temp_dir(){
    if(!fs::exists(compiled_dir)){
        if(fs::create_directory(compiled_dir)){
            std::cout<<"temp folder for object files created at "<<std::endl;
        }
        else{
            std::cerr<<"Failed to create"<<std::endl;
        }
    }
    else{
         std::cout<<"Already Exists";
    }
}

void cyon::scan_deps::fill_paths(std::string _filename){
    _filename.erase(_filename.find_last_not_of(" \n\r\t") + 1);
    // std::cout<<"searching for "<<_filename<<" "<<_filename.substr(_filename.length()-3)<<std::endl;
    if(_filename.substr(_filename.length()-4)==".cpp"){
        path_to_source.insert(std::make_pair(_filename,get_file_path(_filename)));
    }
    // std::cout<<"file name insdie "<<_filename<<" "<<_filename.ends_with(".h")<<std::endl;
    if(_filename.ends_with(".h")){
        // std::cout<<"searching  xxxx for "<<_filename<<std::endl;
        std::string path=get_file_path(_filename);
        // std::cout<<path<<std::endl;
        path_to_header.insert(std::make_pair(_filename,path));
        _filename.erase(_filename.length()-2,2);
        _filename+=".cpp";
        std::string _sourcefile=get_file_path(_filename);
        if(_sourcefile==""){
            std::cout<<"No Source file found for "<<_filename<<std::endl;
        }
        else{
            path_to_source.insert(std::make_pair(_filename,_sourcefile));
        }
    }
    
}

void cyon::scan_deps::run_service(){

    while(!_pending.empty()){
        auto _file_name =_pending.front();
        _file_name.erase(_file_name.find_last_not_of(" \n\r\t") + 1);
        _pending.pop();
        if(is_processed.count(_file_name)>0 || in_process.count(_file_name)>0){
            continue;
        }
        in_process.insert(_file_name);
        // std::cout<<"processing : "<<_file_name;
        std::string _file_path=path_to_header[_file_name];

        cyon::Scanner _scan(_file_name,_file_path);
        std::vector<std::string> _includes=_scan.scan_imports();

        for(std::string _new_dep:_includes){
            if(is_processed.count(_new_dep)>0 || in_process.count(_new_dep)>0){
                continue;
            }
            std::cout<<"going for scan"<<std::endl;
            fill_paths(_new_dep);
            _pending.push(_new_dep);
            dependencies[_file_name].push_back(_new_dep);
        }
        is_processed.insert(_file_name);
        in_process.erase(_file_name);
    }
}

void cyon::scan_deps::print_paths(){
    std::cout<<std::endl;
    std::cout<<"Printing Header Paths"<<std::endl;

    for(auto itr=path_to_header.begin();itr!=path_to_header.end();itr++){
        std::cout<<itr->first<<": "<<itr->second<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Printing Source Paths"<<std::endl;

    for(auto itr=path_to_source.begin();itr!=path_to_source.end();itr++){
        std::cout<<itr->first<<": "<<itr->second<<std::endl;
    }
}