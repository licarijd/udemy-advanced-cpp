Note about Template classes - it's not so easy to seperate the implementation from the
actual class.

What we'd usually do with a class is define it in a header file, then
put the actual implementation in a .cpp file.

Then, a compiler would only have to look at the header in order to see if we've used the class correctly.

It can seperatley compile the .cpp file into a .o file.

So intially, the compiler creates a .o file for each .cpp file, .h file, etc,
and then at the end it links them all together.

That's not the case with Template classes. With templates, C++ has to see both the definition and
implementation together before it can compile the code.

This is because behind the scenes, C++ creates the particular classes invloving particular types.

So, if you have a vector of strings, C++ is going to create a vector that works with strings behind
the scenes. And to do that, it needs definition and implementation in one place.

So normally, it's best to keep entire template classes in a header file.

But, in these tutorials, we'll keep them in cpp files.

