#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

namespace justinlicari {

// We implement everything in the header file since it's a template class.

// ** Note - when defining a template, we can use
// template<typename T>
// instead of
// template<class T>
template<class T>
class Ring {
private:
    int _pos;
    int _size;
    T *_values;
public:

    // This gives us a slightly cleaner way of nesting classes.
    // It means that "Iterator" is a subclass of Ring.
    class Iterator;
public:
    Ring(int size): _size(size), _values(NULL) {
        _values = new T[size];
    }
    ~Ring() {
        delete [] _values;
    }

    int size() {
        return _size;
    }

    void add (T value) {
        _values[_pos++] = value;

        if(_pos == _size) {
            _pos = 0;
        }
    }

    // The return type is a pointer of the same type as the template
    T &get(int pos) {
        return _values[pos];
    }
};

// By specifying template<class T>, we can now use the template in the iterator,
// and we're not forced to specify the same template to our iterator.
template<class T>
class Ring<T>::Iterator {
public:

    // We can continue nesting, and do Ring::Iterator::print
    void print() {
        cout << "Hello from iterator" << T() << endl;
    }
};

}

#endif /* RING_H_ */