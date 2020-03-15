#include <iostream>
#include <map>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:

        // Default constructor required for custom objects as map values
        Person(): name(""), age(0) {

        }

        // Copy constructor
        // C++ provides a default copy constructor (which does a shallow copy).
        // But if we want to change the way certain things are copied (eg. with pointers,
        // we wouldn't want to do a straight copy of addresses), or even NOT copy certain variables,
        // it's a good idea to define your own copy constructor.
        Person(const Person &other) {
            cout << "Copy constructor running";
            name = other.name;
            age = other.age;
        }

        Person(string name, int age) :
            name(name), age(age) {
        }

        void print() {
            cout << name << ": " << age << endl;
        }
};

int main() {
    map<int, Person> people;

    // In order to make custom objects the values of maps,
    // we need to define a default constructor (constructor with no parameters).
    // this is because when we define a constructor with parameters, we lose the default
    // implementation of a constructor with no parameters.
    // The map needs a constructor with no parameters, since it needs to construct the object and then assign
    // values to that object, using the object we set it equal to (eg, Person("Mike", 40) will be copied to a Person object)
    people[0] = Person("Mike", 40);
    people[0] = Person("Vicky", 30);
    people[0] = Person("Raj", 20);

    people.insert(make_pair(55, Person("Bob", 45)));

    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        it -> second.print();
    }
}