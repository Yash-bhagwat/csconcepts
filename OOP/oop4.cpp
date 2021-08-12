#include <iostream>
using namespace std;

class MyClass
{
	// Declare a friend class
	friend class SecondClass;

	public:
		MyClass() : Secret(0){}
		void printMember()
		{
			cout << Secret << endl;
		}
	private:
		int Secret;
};

class SecondClass
{
	public:
		void change( MyClass& yourclass, int x )
		{
			yourclass.Secret = x;
		}
};

int main()
{
	MyClass my_class;
	SecondClass sec_class;
	my_class.printMember();
	sec_class.change( my_class, 5 );
	my_class.printMember();
	
	return 0;
}
