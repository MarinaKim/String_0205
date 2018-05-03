#include"String.h"

String::String(const char* str) {
	this->length = strlen(str);
	this->m_stringRep = new char[length+1];
	
	for (int i = 0;i<=length;i++) {
		this->m_stringRep[i] = str[i];
	}
}

String::String(size_t len, char s) {
	length = len;
	this->m_stringRep = new char[length+1];
	for (int i = 0;i<len;i++) {
		this->m_stringRep[i] = s;
		m_stringRep[len] = '\0';
	}}

String::String(size_t len) {
	length = len;
	this->m_stringRep = new char[length+1];
	m_stringRep[len] = '\0';
}

const char* String::getStrRep() {
	return m_stringRep;
}

char& String::getAt(size_t pos) {
	return m_stringRep[pos];
}

void String:: operator()(const char *str) {
	for (int i = 0;i < strlen(str);i++) {
		this->m_stringRep[i] = str[i];
	}
}

String& String:: operator=(const String& str) {
	char *tmp;
	this->length = str.length;
	tmp = new char[this->length+1];
	for (int i = 0;i < length;i++) {
		tmp[i] = str.m_stringRep[i];
	}
	tmp[length] = '\0';
	delete[] this->m_stringRep;
	m_stringRep = tmp;
	return *this;
}

String& String:: operator+(const String&str) {
	char *tmp;

	tmp = new char[length + str.length + 1];
	for (int i = 0;i < this->length; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = this->length;i < length + str.length;i++)
	{
		for (int j = 0;j < str.length;j++)
			tmp[i] = str.m_stringRep[j];
	}
	this->length += str.length;
	tmp[length] = '\0';
	this->m_stringRep = tmp;
	return *this;
}
String& String:: operator+(const char *str) {
	ConcatStr(str);
	return *this;
}

//printf("%d is %f",10,6.5);
String String::Format(const char * specs, ...)
{
	String s(300);
	char buf[100];
	int i = 0;
	va_list arguments;
	va_start(arguments, specs);
	for (const char *p = specs;*p;p++) 					//
	{
		if (*p == '%') 									//���� ���������� ������ %
		{
			switch (*++p) 								//�� ����������� ��������� �� ���� ������� ������
			{
			case 'd': { int ival = va_arg(arguments, int); 			//���� ��� ������ d, �� ������ �������� int
				//cout << ival << " ";}break; 					//������� �������� ���� int �� �����
				_itoa_s(ival, buf, 10);
				s.ConcatStr(buf);

			}break;
			case 'f': {double dval = va_arg(arguments, double); 		//���� ��� ������ f ������ �������� double
				//cout << dval << " ";}break; //������� �������� ���� double �� �����
				sprintf(buf, "%f", dval);
				s.ConcatStr(buf);
			}break;
			
			}
		}
		else
		{
			/*cout << *p << " ";*/
			s.m_stringRep[i++] = *p;
		}
	}
	s.m_stringRep[i] = '\0';
	va_end(arguments); 	//��������� ������ � ��������������

	return s;
}


String& String:: AddCharAt(size_t pos, char c) {
	char *tmp;
	this->length += 1;
	tmp = new char[length +1];
	for (int i = 0;i < pos;i++) {
		tmp[i] =this-> m_stringRep[i];
	}
	tmp[pos] = c;
	for (int i = pos + 1;i < length + 1;i++)
		tmp[i] = this->m_stringRep[i - 1];

	this->m_stringRep = tmp;
	return *this;
}

String& String::DelCharAt(size_t pos) {
	char *tmp;
	this->length -= 1;
	tmp = new char[length+1];
	for (int i = 0;i < pos;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = pos;i < length+1;i++)
		tmp[i] = this->m_stringRep[i + 1];

	this->m_stringRep = tmp;
	return *this;
}

String& String::ConcatStr(const String& str) {
	char *tmp;
	
	tmp = new char[length+str.length+1];
	for (int i = 0;i < this->length; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = this->length;i < length + str.length;i++)
	{
		for (int j = 0;j < str.length;j++)
			tmp[i] = str.m_stringRep[j];		
	}
	this->length += str.length;
	tmp[length] = '\0';
	this->m_stringRep = tmp;
	return *this;
}

String& String:: ConcatStr(const char* str) {
	char *tmp;
	int tmp_length= this->length+strlen(str);
	tmp = new char[tmp_length + 1];
	for (int i = 0;i < this->length; i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < strlen(str);i++) {
		tmp[i + length] = str[i];
	}

	tmp[tmp_length] = '\0';
	delete[] this->m_stringRep;
	this->m_stringRep = tmp;
	this->length = tmp_length;
	return *this;
}

String& String:: AddStrAt(const String& str, size_t pos) {
	char *tmp;
	int tmp_length = this->length + str.length;
	tmp = new char[tmp_length + 1];
	tmp[tmp_length] = '\0';
	for (int i = 0;i < pos;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < str.length;i++)
		tmp[i + pos] = str.m_stringRep[i];
	for (int i = pos;i < this->length;i++)
		tmp[i + str.length] = this->m_stringRep[i];

	delete[] this->m_stringRep;
	this->m_stringRep = tmp;
	this->length = tmp_length;
	return *this;
}

String& String::AddStrAt(const char* str, size_t pos) {
	char *tmp;
	int tmp_length = this->length + strlen(str);
	tmp = new char[tmp_length + 1];
	tmp[tmp_length] = '\0';
	for (int i = 0;i < pos;i++)
		tmp[i] = this->m_stringRep[i];
	for (int i = 0;i < strlen(str);i++)
		tmp[i + pos] = str[i];
	for (int i = pos;i < this->length;i++)
		tmp[i + strlen(str)] = this->m_stringRep[i];

	delete[] this->m_stringRep;
	this->m_stringRep = tmp;
	this->length = tmp_length;
	return *this;
}
//
//String & String::DelStrAt(size_t beg, size_t end)
//{
//	char *tmp;
//	int tmp_length=
//	
//
//}
