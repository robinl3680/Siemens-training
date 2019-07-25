#include <string.h>
#include <iostream>
using namespace std;

class StringDemo
{
private:
	char *string1;
public:
	StringDemo(const char *name = "") : string1(new char[strlen(name) + 1])
	{
		strcpy(string1, name);
	}
	StringDemo(StringDemo &obj) :string1(new char[strlen(obj.string1) + 1])
	{
		if (obj.string1 != NULL)
			strcpy(string1, obj.string1);
	}
	StringDemo operator+(const StringDemo &s)
	{
		StringDemo backString;
		backString.string1 = (new char[strlen(s.string1) + strlen(string1) + 1]);
		strcpy(backString.string1, string1);
		strcat(backString.string1, s.string1);

		return backString;
	}

	void display()
	{
		cout << string1 << endl;
	}

};

int main()
{
	StringDemo s1;
	StringDemo s2("World");
	s2.display();
	StringDemo s3(s2);
	s3.display();
	/*StringDemo s4;
	s4 = s1 + s3;*/
	return 0;
}
