#ifndef LINKER_H
#define LINKER_H

#include <string>
#include <utility> // for std::move
#include <vector>

namespace cyon {
class linker {
private:
    std::string compiled_dir;
    std::vector<std::string> ob_files;
    std::string base_command = "clang++";

public:
    // TODO: will be adding lib linking in future
    linker(std::string compiled_dir, std::vector<std::string> ob_files)
        : compiled_dir(std::move(compiled_dir)),
          ob_files(std::move(ob_files)) {
        execute();
    }

    void execute();
};

} // namespace cyon

#endif
