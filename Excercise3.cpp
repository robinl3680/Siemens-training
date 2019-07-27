#include <string.h>
#include<string>
#include <iostream>
using namespace std;

class StringDemo
{
private:
	char* string1;
public:
	StringDemo(const char* name = "") : string1(new char[strlen(name) + 1])
	{
		strcpy(string1, name);
	}
	StringDemo(StringDemo& obj) :string1(new char[strlen(obj.string1) + 1])
	{
		if (obj.string1 != NULL)
			strcpy(string1, obj.string1);
	}
	StringDemo operator+(const StringDemo& s)
	{
		StringDemo backString;
		backString.string1 = (new char[strlen(s.string1) + strlen(string1) + 1]);
		strcpy(backString.string1, string1);
		strcat(backString.string1, s.string1);

		return backString;
	}
	bool operator==(const StringDemo& s1)
	{
		if (strcmp(string1, s1.string1) == 0)
			return true;
		else
			return false;
	}
	void operator+=(const char* name)
	{
		StringDemo backString;
		backString.string1 = new char[strlen(name) + strlen(string1) + 1];
		strcpy(backString.string1, string1);
		strcat(backString.string1, name);
		string1 = new char[strlen(backString.string1) + 1];
		strcpy(string1, backString.string1);
		
	}
	char operator[](int index)
	{
		return string1[index-1];
	}
	char* operator()(int start, int end)
	{
		int k = 0;
		char* name = new char[end - start + 1];
		for (int i = start-1; i < end; i++)
		{
			name[k++] = string1[i];
		}
		name[k] = '\0';
		return name;
	}
	void display()
	{
		cout << string1 << endl;
	}
	

	friend StringDemo operator+(const char* name, const StringDemo& s);
	friend ostream& operator<<(ostream& cout, const StringDemo& d3);
};

StringDemo operator+(const char* name, const StringDemo& s)
{
	StringDemo backString;
	backString.string1 = new(char[strlen(name) + strlen(s.string1) + 1]);
	strcpy(backString.string1, name);
	strcat(backString.string1, s.string1);
	return backString;
}

ostream& operator<<(ostream& cout, const StringDemo& d3)
{
	cout << d3.string1;
	return cout;

}

int main()
{
	StringDemo s1;
	StringDemo s2("World");
	StringDemo s3(s2);
	StringDemo s4;
	s4 = s1 + s3;
	s4 += "Program";
	cout << "s1 = " << s1;
	cout << " s2 = " << s2;
	cout << " s4 = " << s4 << endl;
	if (s1 == s2)
		cout << "Strings are same" << endl;
	else
		cout << "Strings are different" << endl;
	StringDemo s5("Oriented");
	char ch[50];
	strcpy(ch, "Object");
	s5 = ch + s5;
	cout << s5 << endl;
	cout << s5[5] << endl;
	cout << s5(2, 5) << endl;
	return 0;
}
