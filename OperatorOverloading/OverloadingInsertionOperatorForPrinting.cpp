#include <iostream>
#include <fstream>
using namespace std;

class Test {

    private:
        int id;
        string name;

    public:
        Test(): id(0), name("") {}

        Test(int id, string name): id(id), name(name) {}

        void print() {}

        const Test &operator=(const Test &other) {
            id = other.id;
            name = other.name;

            // Return a reference to the object we're in.
            return *this;
        }

        Test(const Test &other) {
            cout << "Copy constructor running..." << endl;
            id = other.id;
            name = other.name;
        }

        // We need to return an ofstream object, so our object is
        // of type ofstream.
        // Friend functions can access a class' private members
        friend ostream &operator<<(ostream &out, const Test &test) {
            out << test.id << ": " << test.name;
            return out;
        }
};

int main() {

    Test test1(10, "Mike");
    Test test2(5, "Derike");

    // The bitshift operator '<<' has left associativity.
    // So, this is equivalent to:
    // (cout << test1) << endl;
    // (cout << test1) returns a reference to an ofstream.
    // The 'cout' object is of type ofstream (output stream).
    // test1 is the second argument.
    // So in both cases, the left is an object of type ofstream, and the right is something else.
    // So, since test1 isn't the first argument, we can't implement it as a method (a method is a class function) using 'this'
    // as a reference.
    // We have to implement the statement as a function which overloads '<<'.
    // So, we'll need a friend function.
    // A friend function isn't a method of the class, but it's allowed to access
    // a class' private members.
    cout << test1 << test2 << endl;

    return 0;
}