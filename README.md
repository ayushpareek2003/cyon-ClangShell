🚧 Work in Progress — A lightweight abstraction layer over Clang to simplify compilation.
Users can compile scattered source files without worrying about complex flags or command syntax

just point to your main file and say "pello muhjey", and it builds the binary for you


**Plan:**
The user provides the main file name. Our scanner service recursively collects all user-level headers and source files, then stores them in a temporary folder. We compile them there and generate the final executable.





