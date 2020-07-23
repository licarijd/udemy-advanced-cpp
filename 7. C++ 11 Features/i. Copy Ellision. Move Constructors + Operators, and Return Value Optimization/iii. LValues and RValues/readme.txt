Since C++ was created, we've had this distinction between L-Values and
R-Values. If we type something like:

int value1 = 7;

we say that the "value1" is an L-Value, and 7 is an R-Value.

In C++ 11, and L-Value is anything we can take the address of. So, in

int *pValue1 = &value1;

it's clear that value1 is an L-Value. We can't do

int *pValue2 = &7;

because 7 is an R-Value, and we can't take the address of R-Values.

The same applies with objects. With the expression

Test test1 = getTest();

we have test1 as the L-Value because we can take the address of it. getTest()
is an R-Value, we can't take the address of it. It's a temporary value.
We can't do

Test *pTest2 = &getTest();

Sometimes, the distinction can be tricky:

int *pValue3 = &++value1; 

Note - &++value1 will increment value1, so we get 8.

cout << *pValue3 << endl;

But, this doesn't work with the postfix operator!

int *pValue3 = &value1++; 

The reason is because there's a temporary value in there - the '++'
operator needs to use the value, then increment it. So, it has to create a 
temporary copy of the value, and then that copy is incremented. And
C++ thinks we're trying to take the address of a temporary value, hence
the error.

Therefore, 

++value1 is an L-Value

and value1++ is an R-Value.

We can't take the address of an R-Value.

So, the ++value incrememts the value and then uses it. The value++
uses the value, then increments it. It would be like saying "&8".

Also, in 

int s = 7 + value1;

value is obviously an L-Value, but the whole of (7 + value1) is an R-Value.
We can't just take the address of it with &(7 + value1).

One of the most imoprtant places we see R-Values is in the temporary return values
of functions. We can't take the address of R-Values, but we can take the address of
L-Values.