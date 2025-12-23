// C++ implementation to show
// Visibility modes

#include <bits/stdc++.h>
using namespace std;

// Base class
// Class A will be inherited
class A {
public:
	int x;

protected:
	int y;

private:
	int z;
};

// Derived class
// Class B will inherit Class A
class B : public A {
};

// main function
int main()
{
	B b;

	// x is public
	// so its value will be printed
	cout << b.x << endl;

	// y is protected
	// so it will give visibility error
	cout << b.y << endl;

	// z is not accessible from B
	// so it will give visibility error
	cout << b.z << endl;
};
