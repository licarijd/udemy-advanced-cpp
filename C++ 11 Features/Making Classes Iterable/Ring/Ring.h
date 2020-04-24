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

    Iterator begin() {
        return Iterator(0, *this);
    }

    Iterator end() {
        return Iterator(_size, *this);
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
private:
    int _pos;
    Ring &_ring;
public:
    Iterator(int pos, Ring &ringObject): _pos(pos), _ring(ringObject) {

    }

    // There's obviously 2 forms of the prefix operator: prefix and postfix:
    // i++ and ++i.
    // This is the prefix version.
    Iterator & operator++(){
        ++_pos;
        return *this;
    }

    // The postfix version takes a useless 'int' parameter.
    // It's only used to distinguish the postfix version from the prefix version.
    // We don't even need to provide an integer variable name.
    Iterator & operator++(int){
        _pos++;
        return *this;
    }

    // Overloading the dereference operator.
    T &operator*() {
        return _ring.get(_pos);
    }

    bool operator!=(const Iterator &other) const {
        return _pos != other._pos;
    }
};

}

#endif /* RING_H_ */