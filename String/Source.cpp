#include "String.h"
int main() {
	String s("hello");
	String s1(5,'a');

	s1.getAt(0) = 'z';
	cout << s.getStrRep() << endl;
	cout << s1.getStrRep() << endl;

	String s2(5);
	cout << "s2" << endl;
	cout << s2.getStrRep() << endl;

	s1.AddCharAt(2, 'X');
	cout << s1.getStrRep() << endl;

	s1.DelCharAt(2);
	cout << s1.getStrRep() << endl;

	s1.ConcatStr(s2);
	cout << s1.getStrRep() << endl;

	system("pause");
	return 0;
}