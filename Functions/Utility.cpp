#include <iostream>
using std::cout;
using std::endl;

#include "Utility.h"

bool IsPrime(int x)
{
	bool prime = true;
	for (int i = 2; i <= x / i; i++)
	{
		int factor = x / i;
		if (factor*i == x)
		{
			cout << "factor found: " << factor << endl;
			prime = false;
			break;
		}
	}
	return prime;
}

// potentially a large object for performance reasons take it by const& to prevent copying large object
bool Is2MorePrime(int const& x)
{
	//x = x + 2;
	return IsPrime(x+2);
}

// dangling reference: a is in scope but goes out of scope on the return
//int& BadFunction()
//{
//	int a = 3;
//	return a;
//}