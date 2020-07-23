// ** You are very unlikely to ever need a Reinterpret Cast. This builds on
// the lesson on dynamic casts.

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
    Sister sister;

    // In the heirarchy, Sister is a subclass of Parent, on the same level as Brother.
    // So, it doesn't make much sense to cast Sister to Brother or vice versa
    // for the vast majority of situations.

    Parent *ppb = &brother;

    // So if we try this, we get an "Invalid cast" error if we use dynamic casts.
    // Sister *pbb = dynamic_cast<Sister *>(pbb);

    // It will work with static casts, but it's still a silly thing to do.

    // We can use reinterpret casts for this:
    Sister *pbb = reinterpret_cast<Sister *>(pbb);

    // Reinterpreet casts have even less checking than static casts (it literally just
    // does a binary cast at one pointer type to another). So it can pretty much cast
    // anything to anything.

    // So if there's ever a reason why you'd need to cast a pointer type to a completely 
    // different pointer type, and static casts won't do it for some reason, you can
    // use reinterpret casts. But, generally it's best avoided.

    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    } else {
        cout << pbb << endl;
    }

    return 0;
}