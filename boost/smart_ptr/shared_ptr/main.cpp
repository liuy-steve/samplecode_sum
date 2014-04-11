#include <boost/smart_ptr/shared_ptr.hpp>

using boost::shared_ptr;
int main()
{
	shared_ptr<int> p(new int(42));

	//--- Example 1 ---
	// thread A
	shared_ptr<int> p2(p); // reads p
	// thread B
	shared_ptr<int> p3(p); // OK, multiple reads are safe

	//--- Example 2 ---
	// thread A
	p.reset(new int(1912)); // writes p
	// thread B
	p2.reset(); // OK, writes p2

	//--- Example 3 ---
	// thread A
	p = p3; // reads p3, writes p
	// thread B
	p3.reset(); // writes p3; undefined, simultaneous read/write

	//--- Example 4 ---
	// thread A
	p3 = p2; // reads p2, writes p3
	// thread B
	// p2 goes out of scope: undefined, the destructor is considered a "write access"
	
	//--- Example 5 ---
	// thread A
	p3.reset(new int(1));
	// thread B
	p3.reset(new int(2)); // undefined, multiple writes
}