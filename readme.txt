To compile a single cpp file:

g++ -std=c++11 -o <sample-binary-executable-name> <file-path>

Then just run the binary executable.

To compile multiple C++ files:

g++ -std=c++11 <file-path>/*.cpp -o <sample-binary-executable-name>