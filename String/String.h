#pragma once
#include "Library.h"

class String {
private:
	char* m_stringRep;
	size_t length; // drugoe nazvanie int, only for size
public:
	String(const char* str);
	String(size_t len, char s);
	String(size_t len);

	const char* getStrRep();
	char& getAt(size_t pos);
	String& AddCharAt(size_t pos, char c);
	String& DelCharAt(size_t pos);
	String& ConcatStr(const String& str);
	void operator()(const char *str);
	~String() { delete[]m_stringRep; }
};