#include <iostream>
using namespace std;

// Sometimes we want to create a class heirarchy and you want to have a 
// superclass, but it doesn't make sense to instantiate it.

// For example, we have child classes Dog, Cat, and Pup which can be derived from
// a basic class, Animal.

// But, there's no sense in just instantiating an Animal, since an Animal must be a 
// specific species.

// For this purpose, we have abstract classes. Abstract classes contain methods
// which have no implementation. We say that they are 'pure virtual functions'.

// For example, we could say that all Animals should have a function called speak.
// We declare a speak function in Animal, and then each subclass provides it's own
// implementation of the funtion.

// Animal is an abstract class because it contains a pure virtual function
// (even if a class contains one pure virtual function, it's considered abstract).
class Animal {
public:

    // This syntax creates a pure virtual method (no implementation).
    virtual void speak() = 0;
};

// In this case, since Dog implements every pure virtual function of Animal,
// it is no longer considered to be abstract (and we can instantiate it).
// If it doesn't implement all of it's superclass' abstract functions,
// then it's still considered to be abstract (and we can't instantiate it).
// This is because it's children may implement these
// unimplemented pure virtual functions.

// If Dog had a subclass, it only needs to implement Dog's pure virtual functions,
// not every pure virtual function of Animal. So for example, it wouldn't have
// to implement speak(), since it's already implemented in Dog.
class Dog: public Animal {
public: 
    // Using the 'virtual' keyword here is optional but not necessary,
    // since it's already specified in the parent class.
    void speak() {
        cout << "Woof!";
    }
};

void test(Animal &a) {
    a.speak();
}

int main() {

    // We can't do this because Animal is abstract.
    // Animal animal;

    Dog dog;
    dog.speak();

    // This works because we call the constructor of a non-abstract class (Dog),
    // even though it's an array of pointers to animals.
    // We wouldn't be able to create an array of Animals, since it would
    // require a constructor, and Animals is abstract.

    // Another benefit of this is that if we create an array of superclass pointers,
    // and populate it with all kinds of subclass types. So pointers help
    // us achieve polymorphism.
    Animal *animals[5];
    animals[0] = &dog;

    // We can also pass subclass objects into functions which call the
    // implementations of their parent's pure virtual methods.
    test(dog);

    return 0;
}