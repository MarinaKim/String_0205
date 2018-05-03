#include "String.h"
int main() {
	String s("hello");
	String s1(5,'a');
	String s3(5, 'v');

	s1.getAt(0) = 'z';
	cout << s.getStrRep() << endl;
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	String s2(5);
	cout << "s2" << endl;
	cout << s2.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	s1.AddCharAt(2, 'X');
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	s1.DelCharAt(2);
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	s1.ConcatStr(s3);
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	
	s1.ConcatStr("world");
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;
	
	s1 + s3;
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;

	s1 + "sjdghfjsh";
	cout << s1.getStrRep() << endl;
	cout << "---------------------------------------------------" << endl;


	
	system("pause");
	return 0;
}