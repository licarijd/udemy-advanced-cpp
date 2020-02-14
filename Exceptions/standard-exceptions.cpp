#include <iostream>
using namespace std;

class CanGoWrong {

    // Inline implementation
    public:
        CanGoWrong() {

            // This causes an error since we can't allocate enough memory
            // Most compilers will throw an exception for 'new'
            // If it doesn't, read into what the behaviour should be
            char *pMemory = new char[99999999999999999];
            delete [] pMemory;
        }
};

int main () {

    try {
        CanGoWrong wrong;
    }

    // bad_alloc is the name of the class of error we get from allocating
    // too much memory
    catch(bad_alloc &e) {
        cout << "caught exception: " << e.what() << endl;
    }

    cout << "Still running";

    return 0;
}