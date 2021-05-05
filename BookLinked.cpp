#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct techBook
{
	string name;
	int price;
	int stock;
	struct techBook* techNext;
};
struct manageBook
{
	string name;
	int price;
	int stock;
	struct manageBook* manageNext;
};



struct techBook* searchTech(struct techBook* book, string name)
{
	if (book == NULL)
	{
		return NULL;
	}
	struct techBook* tempBook = book;
	while (tempBook != NULL)
	{
		if (tempBook->name == name)
		{
			return tempBook;
		}
		tempBook = tempBook->techNext;
	}
	return NULL;
}
struct manageBook* searchManage(struct manageBook* book, string name)
{
	if (book == NULL)
	{
		return NULL;
	}
	struct manageBook* temp = book;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			return temp;
		}
		temp = temp->manageNext;
	}
	return NULL;
}
struct techBook* deleteTechBook(struct techBook* book, string name)
{
	struct techBook* prev = NULL;
	struct techBook* temp = book;

	if (book == NULL)
	{
		cout << "No book exist" << endl;
		return NULL;
	}
	if (temp->name == name)
	{
		
		book = book->techNext;
		delete(temp);
		return book;
	}
	
	while (temp != NULL && temp->name != name)
	{
		prev = temp;
		temp = temp->techNext;

	}
	if (temp == NULL)
	{
		cout << "No match found" << endl;
	}
	prev->techNext = temp->techNext;
	delete(temp);
	return book;
}
struct manageBook* deleteManageBook(struct manageBook* book, string name)
{
	struct manageBook* prev = NULL;
	struct manageBook* temp = book;

	if (book == NULL)
	{
		cout << "No book exist" << endl;
		return NULL;
	}
	if (temp->name == name)
	{

		book = book->manageNext;
		delete(temp);
		return book;
	}

	while (temp != NULL && temp->name != name)
	{
		prev = temp;
		temp = temp->manageNext;

	}
	if (temp == NULL)
	{
		cout << "No match found" << endl;
	}
	prev->manageNext = temp->manageNext;
	delete(temp);
	return book;
}
struct techBook* purChaseTechBook(struct techBook* book, string name)
{
	int quantity;
	int flag = 0;
	struct techBook* temp = book;
	if (book == NULL)
	{
		cout << "No book added" << endl;
		return NULL;
	}
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			flag = 1;
			cout << "Book exist please provide count" << endl;
			cin >> quantity;
			if (quantity <= temp->stock)
			{
				cout << "Purchase amount " << temp->price * quantity << endl;
				temp->stock -= quantity;
				if (temp->stock == 0)
				{
					cout << "deleting" << endl;
					book = deleteTechBook(book, name);
					return book;
				}
				break;
			}
			else
			{
				cout << "Not that much stock available, available stock is " << book->stock << endl;
				break;
			}
		}
		temp = temp->techNext;
	}
	if (flag == 0)
	{
		cout << "No match found" << endl;
	}
	return book;
}



struct manageBook* purChaseManageBook(struct manageBook* book, string name)
{
	int quantity;
	int flag = 0;
	struct manageBook* temp = book;
	if (book == NULL)
	{
		cout << "No book added" << endl;
		return NULL;
	}
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			flag = 1;
			cout << "Book exist please provide count" << endl;
			cin >> quantity;
			if (quantity <= temp->stock)
			{
				cout << "Purchase amount " << temp->price * quantity << endl;
				temp->stock -= quantity;
				if (temp->stock == 0)
				{
					cout << "deleting" << endl;
					book = deleteManageBook(book, name);
					return book;
				}
				break;
			}
			else
			{
				cout << "Not that much stock available, available stock is " << book->stock << endl;
				break;
			}
		}
		temp = temp->manageNext;
	}
	if (flag == 0)
	{
		cout << "No match found" << endl;
	}
	return book;
}

struct techBook* addTechBook(string name, int price, int stock)
{

	struct techBook* newBook = NULL;
	newBook = new techBook;

	newBook->name = name;
	newBook->price = price;
	newBook->stock = stock;
	newBook->techNext = NULL;
	return newBook;
}
struct manageBook* addManageBook(string name, int price, int stock)
{

	struct manageBook* newBook = NULL;
	newBook = new manageBook;

	newBook->name = name;
	newBook->price = price;
	newBook->stock = stock;
	newBook->manageNext = NULL;
	return newBook;
}
struct techBook* TechBookAdd(techBook *tech)
{
	string name;
	int stock, price;
	cout << "Enter name of the book" << endl;
	cin >> name;
	struct techBook* temp = searchTech(tech, name);
	if (temp != NULL)
	{
		cout << "Already exist please update count" << endl;
		cin >> stock;
		temp->stock += stock;
	}
	else
	{
		cout << "New book please provide stock and price" << endl;
		cin >> stock >> price;
		if (tech == NULL)
		{
			tech = addTechBook(name, price, stock);
			return tech;
		}
		else
		{
			struct techBook* temp = tech;
			while (temp->techNext != NULL)
				temp = temp->techNext;
			temp->techNext = addTechBook(name, price, stock);
		}
	}
	return tech;
}
struct manageBook* ManageBookAdd(manageBook* tech)
{
	string name;
	int stock, price;
	cout << "Enter name of the book" << endl;
	cin >> name;
	struct manageBook* temp = searchManage(tech, name);
	if (temp != NULL)
	{
		cout << "Already exist please update count" << endl;
		cin >> stock;
		temp->stock += stock;
	}
	else
	{
		cout << "New book please provide price and stock" << endl;
		cin >> price >> stock;
		if (tech == NULL)
		{
			tech = addManageBook(name, price, stock);
			return tech;
		}
		else
		{

			while (tech->manageNext != NULL)
				tech = tech->manageNext;
			tech->manageNext = addManageBook(name, price, stock);
		}
	}
	return tech;
}
void displayTech(techBook *book)
{

	if (book == NULL)
	{
		cout << "No technical book added" << endl;
		return;
	}
	cout << "Technical books are" << endl;
	cout << "---------------" << endl;
	while (book != NULL)
	{
		cout << "name : " << book->name << endl;
		cout << "price : " << book->price << endl;
		cout << "stock : " << book->stock << endl;
		book = book->techNext;
	}

}
void displayManage(manageBook* book)
{

	if (book == NULL)
	{
		cout << "No management book added" << endl;
		return;
	}
	cout << "Management books are" << endl;
	cout << "---------------" << endl;
	while (book != NULL)
	{
		cout << "name : " << book->name << endl;
		cout << "price : " << book->price << endl;
		cout << "stock : " << book->stock << endl;
		book = book->manageNext;
	}

}

int main()
{
	int choice, bookChoice;
	char c;
	struct techBook* tech = NULL;
	struct manageBook* manage = NULL;
	do
	{
		cout << "1 : add book 2 : display book 3 : Purchase" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "1 : technical 2 : management" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
				tech = TechBookAdd(tech);
			}
			else if (bookChoice == 2)
			{
				manage = ManageBookAdd(manage);
			}
		}
		else if (choice == 2)
		{
			cout << "1 : technical 2 : management" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
				displayTech(tech);
			}
			else if (bookChoice == 2)
			{
				displayManage(manage);
			}
		}
		else if (choice == 3)
		{
			string name;
			cout << "1 : technical 2 : management" << endl;
			cin >> bookChoice;
			cout << "enter the name" << endl;
			cin >> name;
			if (bookChoice == 1)
			{
				
				tech = purChaseTechBook(tech,name);
			}
			else if (bookChoice == 2)
			{
				manage = purChaseManageBook(manage,name);
			}
		}
		else
		{
			cout << "invalid" << endl;
		}
		cout << "Continue ? y/n" << endl;
		cin >> c;
	} while (c == 'y');
	return 0;
}
