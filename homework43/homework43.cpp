#include <iostream>

using namespace std;

class MyString
{
	int size;
	char* str;

public:
	static int count;
	MyString()
	{
		Clear();
		this->str = new char[80];
		this->size = 80;
		count++;
	}
	MyString(const MyString &r)
	{
		SetStr(r.str);
		count++;
	}
	MyString(int size)
	{
		Clear();
		this->str = new char[size + 1];
		this->size = size;
		count++;
	}
	MyString(const char* str)
	{
		SetStr(str);
		count++;
	}
	~MyString()
	{
		Clear();
		count--;
	}
	void SetStr(const char* str)
	{
		Clear();
		int length = strlen(str);
		this->str = new char[length + 1];
		this->size = length;
		for (int i = 0; i <= length; i++)
		{
			this->str[i] = str[i];
		}
	}
	void Clear()
	{
		if (str != nullptr)
		{
			delete[] str;
		}
	}
	void Print()
	{
		cout << str << endl;
	}
	static int GetCount()
	{
		return count;
	}
	void Read(const char* mesagge)
	{
		char mas[250];
		cout << mesagge << ": ";
		cin.getline(mas, 250);
		SetStr(mas);
	}
	MyString operator +(int delta)
	{
		if (delta < 0) return *this - (- delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		return MyString(mas);
	}
	MyString operator -(int delta)
	{
		if (delta < 0) return *this + (-delta);
		char mas[1000];
		int newsize = size  - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		return MyString(mas);
	}
	void Plus(int delta)
	{
		if (delta < 0) return Minus(-delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		SetStr(mas);
	}
	void Minus(int delta)
	{
		if (delta < 0) return Plus(-delta);
		char mas[1000];
		int newsize = size - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		SetStr(mas);
	}

	MyString operator ++()
	{
		Plus(1);
		return MyString(*this);
	}

	MyString operator --()
	{
		Minus(1);
		return MyString(*this);
	}
};

int MyString::count = 0;

int main()
{
	MyString str1;
	str1.Read("Введите 1 строку");
	str1.Print();
	MyString str2 = str1 + (-3);
	str2.Print();
	MyString str3 = str1 - (-4);
	str3.Print();
	MyString str4 = ++str3;
	str3.Print();
	str4.Print();
	MyString str5 = --str4;
	str4.Print();
	str5.Print();
}
