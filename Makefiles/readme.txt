Makefiles 


Makefiles compile several programs.

The 'make' command looks for a file named 'makefile', and executes it.

If there are several makefiles, it's helpful to specify the makefile with:

make -f MyMakeFile 


Build Process 

1) The Compiler takes source files and outputs object files 

2) The Linker takes the object files and creates an executable


A Basic Makefile

all:
    g++ main.cpp hello.cpp factorial.cpp -o


Force Targets: https://www.gnu.org/software/make/manual/html_node/Force-Targets.html