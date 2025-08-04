
#include "./inc/service.h"
#include "./inc/scanner.h"

void cyon::scan_deps::create_temp_dir(){
    if(!fs::exists(compiled_dir)){
        if(fs::create_directory(compiled_dir)){
            std::cout<<"temp folder for object files created at "<<compiled_dir<<std::endl;
        }
        else{
            std::cerr<<"Failed to create"<<std::endl;
        }
    }
    else{
         std::cout<<"Already Exists";
    }
}

void cyon::scan_deps::fill_paths(std::string &_filename){
    if(_filename.substr(_filename.length()-3)==".cpp"){
        path_to_source.insert(std::make_pair(_filename,get_file_path(_filename)));
    }
    if(_filename.substr(_filename.length()-3)==".h"){
        path_to_header.insert(std::make_pair(_filename,get_file_path(_filename)));
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
        _pending.pop();
        if(is_compiled.count(_file_name)>0){
            continue;
        }
        in_process.insert(file);

        std::_file_path=path_to_file[_file_name];

        cyon::Scanner _scan(_file_name,_file_path);
        std::vector<std::string> _includes=_scan.scan_imports();

        for(std::string _new_dep:_includes){
            if(is_processed.count(_new_dep)>0 || in_process.count(_new_dep)>0){
                continue;
            }
            fill_paths(_new_dep);
            _pending.push(_new_dep);
            in_process.insert(_new_dep); 
            dependencies[_file_name].push_back(_new_dep);
        }
        is_processed.insert(_file_name);
        in_process.erase(_file_name);
    }
}