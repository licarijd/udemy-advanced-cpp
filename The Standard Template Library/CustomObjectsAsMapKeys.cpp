#include <iostream>
#include <map>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:

        Person(): name(""), age(0) {

        }

        Person(const Person &other) {
            name = other.name;
            age = other.age;
        }

        Person(string name, int age) :
            name(name), age(age) {
        }

        // Using 'const' means that print cannot change instance variables.
        // If we try, we'd get a compiler error.
        void print() const {
            cout << name << ": " << age << flush;
        }

        // In order to iterate through keys of a map,
        // where each key is a custom object, the iterator doesn't
        // know how to order keys unless we overload comparative
        // operators, eg. '<'

        // We use a reference here (&other) because we don't want to create another copy
        // of the object, we want to refer to the original.
        // We use 'const Person &other' because we don't want the method to change the object at &other.
        // The const at the end prevents the method from changing the original Person instance.
        bool operator<(const Person &other) const {
            return name < other.name;
        }
};

int main() {
    map<Person, int> people;

    
    people[Person("Mike", 40)] = 40;
    // By definition of our overloaded operator, the following two keys would
    // be considered equal to the one above.
    // In both cases, the value would be updated, but the key would remain the same.
    // In the second case, the reason is because name did not change, and to our
    // overloaded operator, the same name is considered the same object (same key).
    // people[Person("Mike", 40)] = 30;
    // people[Person("Mike", 444)] = 0;
    people[Person("Vicky", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->second << ": " << flush;

        // Map keys are constants, and shouldn't be changed by methods like print,
        // so we need to mark print() as 'const'
        it->first.print();
        cout << endl;
    }
}