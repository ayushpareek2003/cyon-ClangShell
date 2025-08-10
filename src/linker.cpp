#include "linker.h"


void cyon::linker::execute(){
    for(auto _ob:ob_files){
        base_command+=" "+compiled_dir+"/"+_ob;
    }

    base_command+= " -o final_cyon.exe";
    FILE* pipe=popen(base_command.c_str(),"r");
}