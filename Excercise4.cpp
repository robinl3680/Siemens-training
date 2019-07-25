#pragma once
#include <string>
#include <string.h>
#include<iostream>
using namespace std;
class BookStore
{
	class Book
	{
	protected:
		char *bookName;
		int stock;
		float price;
	public:
	
		Book(char *name, int st, float pri) : bookName(new char[strlen(name) + 1]), stock(st), price(pri)
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
	class TechnicalBook : public Book
	{
		const int rateOfDiscount;
	public:

		TechnicalBook(char *name, int st, float pri) : Book(name, st, pri), rateOfDiscount(5)
		{
		}
		float CalculateDiscount(int quantity)
		{
			return ((BookStore::Book::GetPrice()*quantity) - ((rateOfDiscount / 100) * BookStore::Book::GetPrice() * quantity));
		}
	};

	class ManagementBook : public Book
	{
		const int rateOfDiscount;
	public:
		ManagementBook(char *name, int st, float pri) : Book(name, st, pri), rateOfDiscount(5)
		{
		}
		float CalculateDiscount(int quantity)
		{
			return ((BookStore::Book::GetPrice()*quantity) - ((rateOfDiscount / 100) * BookStore::Book::GetPrice() * quantity));
		}
	};

	TechnicalBook *techBook[3];
	ManagementBook *manageBook[3];
	int bookCount1;
	int bookCount2;
	char *name;

public:

	BookStore(char *storename) : name(new char[strlen(storename)+1])
	{
		bookCount1 = 0;
		bookCount2 = 0;
		strcpy(name, storename);
		for (int i = 0; i < 3; i++)
		{
			techBook[i] = NULL;
			manageBook[i] = NULL;
		}
	}
	void AddBook(char *name,int choice)
	{

		if (choice == 1)
		{
			int flag = 0;
			int stock;
			float price;
			for (int i = 0; i < 3; i++)
			{
				if (techBook[i] != NULL)
				{
					if (strcmp(techBook[i]->GetBookName(), name) == 0)
					{
						int newStock;
						cout << "Book already exists update the count " << endl;
						cin >> newStock;
						flag = 1;
						techBook[i]->UpdateStock(newStock);
						break;
					}

				}
				else
				{


					if (bookCount1 <= 2)
					{
						cout << "New book please provide stock and price" << endl;
						cin >> stock >> price;
						techBook[bookCount1++] = new TechnicalBook(name, stock, price);
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
		else if (choice == 2)
		{
			int flag = 0;
			int stock;
			float price;
			for (int i = 0; i < 3; i++)
			{
				if (manageBook[i] != NULL)
				{
					if (strcmp(techBook[i]->GetBookName(), name) == 0)
					{
						int newStock;
						cout << "Book already exists update the count " << endl;
						cin >> newStock;
						flag = 1;
						manageBook[i]->UpdateStock(newStock);
						break;
					}

				}
				else
				{


					if (bookCount2 <= 2)
					{
						cout << "New book please provide stock and price" << endl;
						cin >> stock >> price;
						techBook[bookCount1++] = new TechnicalBook(name, stock, price);
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
		else
		{
			cout << "Invalid choice" << endl;
			return;
		}
		
	}
	void DisplayBook(int choice)
	{
		int flag = 0;
		if (bookCount1 == 0 && bookCount2 == 0)
		{
			cout << "No books are added" << endl;
			return;
		}
		
		if(choice == 1)
		{
			if (bookCount1 == 0)
			{
				cout << "No technical books" << endl;
				return;
			}
			cout << "Book Details" << endl;
			cout << "--------------" << endl;
			for (int i = 0; i < bookCount1; i++)
			{
				
					cout << "Book name : " << techBook[i]->GetBookName() << endl;
					cout << "Book stock : " << techBook[i]->GetStock() << endl;
					cout << "Book price : " << techBook[i]->GetPrice() << endl;
			}
		}
		else if (choice == 2)
		{
			if (bookCount2 == 0)
			{
				cout << "No management books" << endl;
				return;
			}
				cout << "Book Details" << endl;
				cout << "--------------" << endl;
				for (int i = 0; i < bookCount2; i++)
				{

					cout << "Book name : " << manageBook[i]->GetBookName() << endl;
					cout << "Book stock : " << manageBook[i]->GetStock() << endl;
					cout << "Book price : " << manageBook[i]->GetPrice() << endl;
				}
			
		}
		else if (choice == 3)
		{
			cout << "Technical books" << endl;
			cout << "-----------------------" << endl;
			for (int i = 0; i < bookCount1; i++)
			{

				cout << "Book name : " << manageBook[i]->GetBookName() << endl;
				cout << "Book stock : " << manageBook[i]->GetStock() << endl;
				cout << "Book price : " << manageBook[i]->GetPrice() << endl;
			}
			cout << "Management books" << endl;
			cout << "-----------------------" << endl;
			for (int i = 0; i < bookCount2; i++)
			{

				cout << "Book name : " << manageBook[i]->GetBookName() << endl;
				cout << "Book stock : " << manageBook[i]->GetStock() << endl;
				cout << "Book price : " << manageBook[i]->GetPrice() << endl;
			}
		}

	}
	int searchSingle(char *name,int choice)
	{
		if (choice == 1)
		{
			for (int i = 0; i < bookCount1; i++)
			{
				if (strcmp(techBook[i]->GetBookName(), name) == 0)
					return 1;
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < bookCount2; i++)
			{
				if (strcmp(manageBook[i]->GetBookName(), name) == 0)
					return 1;
			}
		}
		
		return 0;
	}
	void SearchBook(char *name,int choice)
	{
		if (choice == 1)
		{
			int flag = 0;
			int quantity;
			if (bookCount1 == 0)
			{
				cout << "No books are added" << endl;
				return;
			}
			else
			{
				for (int i = 0; i < bookCount1; i++)
				{

					if (strcmp(techBook[i]->GetBookName(), name) == 0)
					{
						flag = 1;
						cout << " Book exist please enter required quantity" << endl;
						cin >> quantity;
						if (quantity <= techBook[i]->GetStock())
						{
							cout << "You can purchase now do you want to purchase ? 1/0 " << endl;
							cin >> choice;
							if (choice == 1)
							{
								techBook[i]->UpdatePurchase(quantity);
								cout << "Total purchase amount " << techBook[i]->GetPrice()*quantity << endl;

								if (techBook[i]->GetStock() == 0)
								{
									techBook[i] = techBook[bookCount1 - 1];
									//delete book[bookCount - 1];
									techBook[bookCount1 - 1] = NULL;
									bookCount1--;
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
		else if (choice == 2)
		{

			int flag = 0;
			int quantity;
			if (bookCount2 == 0)
			{
				cout << "No books are added" << endl;
				return;
			}
			else
			{
				for (int i = 0; i < bookCount2; i++)
				{

					if (strcmp(manageBook[i]->GetBookName(), name) == 0)
					{
						flag = 1;
						cout << " Book exist please enter required quantity" << endl;
						cin >> quantity;
						if (quantity <= manageBook[i]->GetStock())
						{
							cout << "You can purchase now do you want to purchase ? 1/0 " << endl;
							cin >> choice;
							if (choice == 1)
							{
								manageBook[i]->UpdatePurchase(quantity);
								cout << "Total purchase amount " << manageBook[i]->GetPrice()*quantity << endl;

								if (manageBook[i]->GetStock() == 0)
								{
									manageBook[i] = manageBook[bookCount2 - 1];
									//delete book[bookCount - 1];
									techBook[bookCount2 - 1] = NULL;
									bookCount2--;
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
		
	}

	~BookStore()
	{
		for (int i = 0; i < bookCount1; i++)
		{
			
				delete techBook[i];
				techBook[i] = NULL;
		}
		for (int i = 0; i < bookCount2; i++)
		{

			delete manageBook[i];
			manageBook[i] = NULL;
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
	int bookChoice;
	cout << "Enter the store name" << endl;
	cin >> name;
	
	BookStore store(name);
	do
	{
		cout << "Enter the choice 1 : Add book 2 : Display Book 3 : Search and purchase book" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << " 1 : Technical 2 : Management" << endl;
			cin >> bookChoice;
			cout << "Enter book name" << endl;
			cin >> bookname;
			store.AddBook(bookname,bookChoice);
			break;
		case 2: 
			cout << "1 : technical 2 : management 3 : both" << endl;
			cin >> bookChoice;
			store.DisplayBook(bookChoice);
			break;
		case 3:
			cout << " 1 : Technical 2 : Management" << endl;
			cin >> bookChoice; 
			cout << "Enter name of the book " << endl;
			cin >> bookname;
			store.SearchBook(bookname,bookChoice);
			break;
		default: cout << "Invalid choice" << endl;
			break;

		}
		cout << "Do you want to continue? y/n" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;

}
