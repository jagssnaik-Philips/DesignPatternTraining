// DoubleDispatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	A *obj = new B();
	obj->MethodM();

	C *newObj = new D();
	newObj->MethodN(&obj);

    return 0;
}

class A
{
public:

	void MethodM()
	{
		cout << "A objects method M called";
	}
};

class B : public A
{
public:

	void MethodM()
	{
		cout << "B objects method M called";
	}
};

class C {


public:
	void MethodN(A obj)
	{
		cout << "methodN of object C called";
	}
	void MethodN(B obj)
	{
		cout << "methodN of object C called";
	}
};

class D : public C {


public:
	void MethodN(A obj)
	{
		cout << "methodN of object D called";
	}
	void MethodN(B obj)
	{
		cout << "methodN of object D called";
	}
};
