#include"String.h"

int main()
{
	String line1;
	line1.Input();
	line1.Print();
	String line("hid");
	line.Print();
	String line2(20);
	std::cout<<String::Counter();
	return 0;
}