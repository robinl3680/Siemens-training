#pragma once
#include <string>
#include <string.h>
#include<iostream>
using namespace std;
class BookStore
{
	class Book
	{
	private:
		char* bookName;
		int stock;
		float price;
	public:

		Book(char* name, int st, float pri) : bookName(new char[strlen(name) + 1]), stock(st), price(pri)
		{
			strcpy(bookName, name);
		}

		char* GetBookName()
		{
			return bookName;
		}
		void UpdateStock(int count)
		{
			stock += count;
		}
		int GetStock()
		{
			return stock;
		}
		void UpdatePurchase(int st)
		{
			stock -= st;
		}
		float GetPrice()
		{
			return price;
		}
		~Book()
		{
			delete[] bookName;
		}
	};

	Book* book[3];
	int bookCount;
	char* name;

public:

	BookStore(char* storename) : name(new char[strlen(storename) + 1])
	{
		bookCount = 0;
		strcpy(name, storename);
		for (int i = 0; i < 3; i++)
			book[i] = NULL;
	}
	void AddBook(char* name)
	{

		int flag = 0;
		int stock;
		float price;
		for (int i = 0; i < 3; i++)
		{
			if (book[i] != NULL)
			{
				if (strcmp(book[i]->GetBookName(), name) == 0)
				{
					int newStock;
					cout << "Book already exists update the count " << endl;
					cin >> newStock;
					flag = 1;
					book[i]->UpdateStock(newStock);
					break;
				}

			}
			else
			{


				if (bookCount <= 2)
				{
					cout << "New book please provide stock and price" << endl;
					cin >> stock >> price;
					book[bookCount++] = new Book(name, stock, price);
					cout << "Book added" << endl;
					break;

				}
				else
				{
					cout << "Limit is reached" << endl;
					break;
				}
			}

		}


	}
	void DisplayBook()
	{
		int flag = 0;
		if (bookCount == 0)
		{
			cout << "No books are added" << endl;
			return;
		}

		else
		{
			cout << "Book Details" << endl;
			cout << "--------------" << endl;
			for (int i = 0; i < bookCount; i++)
			{

				cout << "Book name : " << book[i]->GetBookName() << endl;
				cout << "Book stock : " << book[i]->GetStock() << endl;
				cout << "Book price : " << book[i]->GetPrice() << endl;
			}
		}

	}
	int searchSingle(char* name)
	{
		for (int i = 0; i < bookCount; i++)
		{
			if (strcmp(book[i]->GetBookName(), name) == 0)
				return 1;
		}
		return 0;
	}
	void SearchBook(char* name)
	{
		int choice;
		int flag = 0;
		int quantity;
		if (bookCount == 0)
		{
			cout << "No books are added" << endl;
		}
		else
		{
			for (int i = 0; i < bookCount; i++)
			{

				if (strcmp(book[i]->GetBookName(), name) == 0)
				{
					flag = 1;
					cout << " Book exist please enter required quantity" << endl;
					cin >> quantity;
					if (quantity <= book[i]->GetStock())
					{
						cout << "Total purchase amount " << book[i]->GetPrice() * quantity << endl;
						cout << "You can purchase now do you want to purchase ? 1/0 " << endl;
						cin >> choice;
						if (choice == 1)
						{
							book[i]->UpdatePurchase(quantity);
							cout << "Purchase successfull" << endl;

							if (book[i]->GetStock() == 0)
							{
								book[i] = book[bookCount - 1];
								//delete book[bookCount - 1];
								book[bookCount - 1] = NULL;
								bookCount--;
							}
						}
						else
							break;


					}
					else
					{
						cout << "Not that much stock is available" << endl;
						break;
					}
				}
			}
			if (flag == 0)
			{
				cout << "No match found" << endl;

			}
		}
	}

	~BookStore()
	{
		for (int i = 0; i < bookCount; i++)
		{

			delete book[i];
			book[i] = NULL;
		}
		delete[] name;

	}

};

int main()
{
	char name[15];
	char ch;
	char bookname[15];
	int stock;
	float price;
	int choice;
	cout << "Enter the store name" << endl;
	cin >> name;

	BookStore store(name);
	do
	{
		cout << "Enter the choice 1 : Add book 2 : Display Book 3 : Search and purchase book" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter book name" << endl;
			cin >> bookname;
			store.AddBook(bookname);
			break;
		case 2: store.DisplayBook();
			break;
		case 3: cout << "Enter name of the book " << endl;
			cin >> bookname;
			store.SearchBook(bookname);
			break;
		default: cout << "Invalid choice" << endl;
			break;

		}
		cout << "Do you want to continue? y/n" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;

}
