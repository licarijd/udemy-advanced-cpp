#include <iostream>
using namespace std;

class Parent {
public:
    void speak() {
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

    // Revisit casting in C:
    float value = 3.23;

    cout << (int)value << endl;

    // We can also do:
    cout << int(value) << endl;

    // C++ gives us some more precisely defined types of casting that can help
    // reduce errors in programs. The simplest is the Static Cast.

    cout << static_cast<int>(value) << endl;

    // Previously, we'd use a C-style cast

    
    // Suppose we have a Parent pointer. We can set that to a pointer to one
    // of the child classes (one of it's descedants).

    Parent *pp = &brother;

    // This makes sense because the concept of Polymorphism is that we can use
    // a pointer or reference to a subclass in any situation where we expect a 
    // pointer or reference to a superclass.

    // The other way around, it doesn't work:
    // Brother *pb = &parent;

    // It will work if we use a static cast:
    Brother *pb = static_cast<Brother *>(&parent);

    cout << pb << endl;

    // This works, but it's dangerous because things can go wrong with virtual 
    // functions. Or we could have methods in Brother that don't exist in Parent.
    // We could try calling them using this pointer, and the program would just crash.

    // So usually, we'll want to avoid this sort of thing. But sometimes, we may actually
    // want to do this.

    Parent *ppb = &brother;

    // This is a typical case where we use a child where a parent is expected; Polymorphism 
    // garuntees us that this will work.

    // Brother *pbb = &brother;

    // Obviously, this will work as well.

    // And, it does make sense in this situation to point it at the same address as *ppb.
    
    // The line declaring pbb doesn't compile. We can use a static cast to get it to work.

    Brother *pbb = static_cast<Brother *>(pbb);

    // This can potentially be very error prone. static_cast is purely a compile time thing.
    // There's no runtime checking. So, the ppb pointer could point at a Parent object and
    // not at a Brother object. It cuold turn out to be invalid later in the code, calling
    // Brother methods which don't exist in Parent. 

    // We'll look at a better way to do this with dynamic casts in the next tutorial.

    // Static casts can be used to get your code working, but it's up to you to decide if 
    // what the code is doing actually makes sense.

    // One other case where you might use static casts (which has a bearing on perfect forwarding)
    // is:

    Parent &&p = Parent();

    // We're setting an r-value reference to an r-value. This will work with C++ 11.

    // But, what if we wanted to set this r-value reference to an l-value?

    // Parent &&p = parent;

    // This could work, since the objects are of the right type. But it doesn't. We need to use
    // a static cast to make this work.

    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();

    // This can be useful if for example you have a function with a parameter type that's an r-value reference,
    // and for some reason, you need to pass an l-value to that function.

    cout << pbb << endl;

    return 0;
}