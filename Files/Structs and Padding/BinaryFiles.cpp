#include <iostream>
#include <fstream>;
using namespace std;

// This is useful for saving and opening files in some application.

// Only difference between a struct and a class is that the members of a
// struct are public by default.
// Structs are often used for writing to files.
// Example - each byte in a binary file can be mapped to one or more structs (members of structs)

// C++ pads structs to make them efficient to transfer to and from memory.

#pragma pack(push, 1) // Align data on single byte boundaries
// This turns padding off effectively

struct Person {

    // When we declare a string, the text isn't stored in this variable.
    // It has a pointer - it uses 'new' with this pointer to allocate memory on the heap
    // The heap is a large area of memory , with most of the RAM available to a program.
    // So, the following won't write this directly to a binary file, it wouldn't store the text.
    // Instead, it'd write the pointer to that text.
    // If we read that with a different copy of this program, the pointer wouldn't point anywhere.
    // So, we can't use 'string'.
    // string name;

    char name[50];
    int age;
    double weight;
};

// Turn off single byte boundaries
#pragma pack(pop)

int main() {

    // Initializes the struct
    Person someone = { "Frodo", 220, 0.8};

    string filename = "test";


    ////// WRITE BINARY FILE ///////

    ofstream outputFile;

    // Need ios::binary so c++ knows it's dealing with a binary file
    outputFile.open(filename, ios::binary);

    if (outputFile.is_open()) {


        // (char *)&someone casts the data stored at the struct instance a a char pointer
        // Old way of casting to a char pointer:
        // outputFile.write((char *)&someone, sizeof(Person));

        // New way of casting between pointers:
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        outputFile.close();
    } else {
        cout << "couldn't create file " + filename;
    }


    ////// READ BINARY FILE //////

    Person someoneElse = {};

    ifstream inputFile;
    
    inputFile.open(filename, ios::binary);

    if (inputFile.is_open()) {

        // Read the newly generated binary file into
        // the empty struct instance 'someoneElse'
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

        inputFile.close();
    } else {
        cout << "couldn't read file " + filename;
    }

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;

    // sizeof() will give you the size in bytes of the object
    // we can see that regardless of the variables we declare in the struct,
    // the size is 64 bytes because it is padded.
    cout << sizeof(Person) << endl;
    return 0;
}