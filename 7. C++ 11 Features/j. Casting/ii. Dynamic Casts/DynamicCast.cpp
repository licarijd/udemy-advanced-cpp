// This is an example of the ReInterpret class in C++, and builds on StaticCast.cpp

#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "parent!" << endl;
    }
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

    Parent parent;
    Brother brother;

    // In the previous tutorial on static casts, we saw that if we have a pointer of a superclass type
    // to a subclass type, you might later on want to have a pointer to the subclass type, and cast the 
    // pointer of the superclass type back to the subclass (since in this case, refer to a subclass).

    // We can do this with static casts, but it's very unsafe because the parent superclass pointer might point to 
    // a superclass object. Static casts will still allow us to cast the pointer of the superclass to the subclass.
    // The superclass might lack methods that the subclass has, and you might try to call them using the pbb pointer.

    // So, it would be nice if we had some kind of cast, which at runtime, would detect whether or not the following code
    // makes sense. We can do that with dynamic casts. It will only work if we have runtime type information (RTTI) turned on in
    // our compiler.

    // This code, unlike static casts, which is just a compile time thing, dynamic casts check types at runtime to make sure
    // what we're doing makes sense.

    // So if you can use dynamic casts, it's better to use than static casts, because static casts don't do this runtime checking.

    Parent *ppb = &brother;

    Brother *pbb = dynamic_cast<Brother *>(pbb);

    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    } else {
        cout << pbb << endl;
    }

    return 0;
}