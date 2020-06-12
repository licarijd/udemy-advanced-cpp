// We've seen some examples of inefficiences when compiler optimization
// doesn't fit in.

// One of them involves return values, which are temporary values, and the other 
// involves passing temporary values like this:

vec.push_back(Test(1));

// In both cases, if we could identify temporary values somehow, we could
// handle them differently than non-temporary values. This could 
// potentially introduce optimizations into our code. That's what 
// r-value references are for.

Test &lTest1 = test1;

// This is pointing an l-value reference at an l-value.

// An r-value reference looks like this:

Test &&test1

// ** It is NOT a reference to a reference

// We can't bind it to an l-value:

Test &&rTest1 = test1;

// We can bind r-value references to r-values:

Test &&rTest1 = getTest();

// R-Value references provide a way to distinguish between temporary and
// non-temporary variables (l-values and r-values).

// Sample function that takes an r-value reference as a parameter
void check(Test &&value) {
    cout << "R-Value: " << endl;
}

// Sample function that takes an l-value reference as a parameter
void check(Test &&value) {
    cout << "rValue function!" << endl;
}

// So we have an overloaded chack function. If we pass in r-values like so:

check(getTest())

// It'll choose the first.

// If we pass in an l-value:

Test test1 = getTest()

check(test1)

// It'll choose the second

// We can use this to construct move constructors and move assignment operators,
// which are more efficient than copy constructors.






