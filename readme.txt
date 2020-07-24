To compile a single cpp file:

g++ -std=c++11 -o <sample-binary-executable-name> <file-path>

Then just run the binary executable.

To compile multiple C++ files:

g++ -std=c++11 <file-path>/*.cpp -o <sample-binary-executable-name>


** A prototype is a function declaration before the function's definition.
All prototypes can be placed in a file called a header.

** constructors are run whe an object is instantiated ("new" allocates memory)

** destructors run when an object is destroyed (memory is deallocated). 
Destructors are indicated by a '~'.

** A constructor initialization list is when we initialize private fields 
like this: Person::Person(string name, int age): name(name), age(age) {}
It reduces code, and the initialization list can simply be moved to a 
header file.