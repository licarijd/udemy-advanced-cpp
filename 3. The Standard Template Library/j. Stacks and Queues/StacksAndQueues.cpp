#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
    private:
        string name;
    
    public:
        Test(string name) :
            name(name) {

            }

        ~Test() {

        }

        void print() {
            cout << name << endl;
        }
};

int main() {

    // Stacks are last in first out.
    stack<Test> testStack;

    // In this case, the original objects (eg. Test("Mike") are destroyed,
    // and a copy is made for the stack)
    testStack.push(Test("Mike"));
    testStack.push(Test("Sue"));
    testStack.push(Test("Bae"));

    // A copy is made here as well - testStack.top() is copied to test1.
    // So if we pop the stack, test1 will still be available.
    Test test1 = testStack.top();
    test1.print();

    testStack.pop();
    Test test2 = testStack.top();
    test2.print();

    cout << endl;

    // To be more efficient, we can skip making a copy, and reference the original object.
    // Obviously in this case, it is unreliable to use test1Efficient after popping the stack,
    // since the data stored at the address will have been released, and we dont know what
    // &test1Efficient is pointing to.
    Test &test1Efficient = testStack.top();
    test1Efficient.print();

    cout << endl;

    // The only way to iterate a stack is to pop, and then check the top
    while (testStack.size() > 0) {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }

    cout << endl;

    // Queues are first in first out
    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("Sue"));
    testQueue.push(Test("Bae"));

    testQueue.back().print();

    while (testQueue.size() > 0) {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    return 0;
}