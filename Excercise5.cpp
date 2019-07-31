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

		virtual char* GetBookName()
		{
			return bookName;
		}
		virtual void UpdateStock(int count)
		{
			stock += count;
		}
		virtual int GetStock()
		{
			return stock;
		}
		virtual void UpdatePurchase(int st)
		{
			stock -= st;
		}
		virtual float GetPrice()
		{
			return price;
		}

		virtual ~Book()
		{
			delete[] bookName;
		}
		float CalculateDiscount(int quantity);
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
			return ((BookStore::Book::GetPrice()*quantity) - ((0.05) * BookStore::Book::GetPrice() * quantity));
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
			return ((BookStore::Book::GetPrice()*quantity) - ((0.1) * BookStore::Book::GetPrice() * quantity));
		}
	};

	Book *book[5];
	int bookCount;
	int techCount;
	int manageCount;
	char *name;

public:

	BookStore(char *storename) : name(new char[strlen(storename) + 1])
	{
		bookCount = 0;
		techCount = 0;
		manageCount = 0;
		strcpy(name, storename);
		for (int i = 0; i < 5; i++)
		{
			book[i] = NULL;
		}
	}
	void AddBook(char *name, int choice)
	{

		if (choice == 1)
		{
			int flag = 0;
			int stock;
			float price;
			for (int i = 0; i < 5; i++)
			{
				if (book[i] != NULL)
				{
					
					if (typeid(TechnicalBook) == typeid(*(book[i])))
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

				}
				else
				{
					if (bookCount <= 4)
					{
						cout << "New book please provide stock and price" << endl;
						cin >> stock >> price;
						book[bookCount++] = new TechnicalBook(name, stock, price);
					
						cout << "Technical book added" << endl;
						techCount++;
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
			for (int i = 0; i < 5; i++)
			{
				if (book[i] != NULL)
				{
					if (typeid(ManagementBook) == typeid(*(book[i])))
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

				}
				else
				{


					if (bookCount <= 4)
					{
						cout << "New book please provide stock and price" << endl;
						cin >> stock >> price;
						book[bookCount++] = new ManagementBook(name, stock, price);
						cout << "Book added" << endl;
						manageCount++;
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
		if (bookCount==0)
		{
			cout << "No books are added" << endl;
			return;
		}

		if (choice == 1)
		{
			if (techCount == 0)
			{
				cout << "No technical books" << endl;
				return;
			}
			cout << "Book Details" << endl;
			cout << "--------------" << endl;
			for (int i = 0; i < 5; i++)
			{
				if (book[i] != NULL && typeid(*(book[i])) == typeid(TechnicalBook))
				{
					cout << "Book name : " << book[i]->GetBookName() << endl;
					cout << "Book stock : " << book[i]->GetStock() << endl;
					cout << "Book price : " << book[i]->GetPrice() << endl;
				}
				
			}
		}
		else if (choice == 2)
		{
			if (manageCount == 0)
			{
				cout << "No management books" << endl;
				return;
			}
			cout << "Book Details" << endl;
			cout << "--------------" << endl;
			for (int i = 0; i < 5; i++)
			{
				if (book[i] != NULL && typeid(*(book[i])) == typeid(ManagementBook))
				{
					cout << "Book name : " << book[i]->GetBookName() << endl;
					cout << "Book stock : " << book[i]->GetStock() << endl;
					cout << "Book price : " << book[i]->GetPrice() << endl;
				}

			}

		}
		else if (choice == 3)
		{
			cout << "Books are" << endl;
			cout << "-----------------------" << endl;
			for (int i = 0; i < 5; i++)
			{
				if (book[i] != NULL)
				{
					cout << "Book name : " << book[i]->GetBookName() << endl;
					cout << "Book stock : " << book[i]->GetStock() << endl;
					cout << "Book price : " << book[i]->GetPrice() << endl;
				}
			}
		}

	}

	void SearchBook(char *name, int choice)
	{
		int userPurchasechoice;
		if (choice == 1)
		{
			int flag = 0;
			int quantity;
			if (techCount == 0 || bookCount == 0)
			{
				cout << "No books are added" << endl;
				return;
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					if (book[i] != NULL && typeid(*(book[i])) == typeid(TechnicalBook))
					{
						if (strcmp(book[i]->GetBookName(), name) == 0)
						{
							flag = 1;
							cout << " Book exist please enter required quantity" << endl;
							cin >> quantity;
							if (quantity <= book[i]->GetStock())
							{

								cout << "You can purchase now do you want ? 1/0 " << endl;
								cout << "Total purchase amount " << book[i]->GetPrice()*quantity << endl;
								cout << "Price after offer " << ((TechnicalBook*)book[i])->CalculateDiscount(quantity) << endl;
								cin >> userPurchasechoice;
								if (userPurchasechoice == 1)
								{
									book[i]->UpdatePurchase(quantity);
									cout << "Purchase success" << endl;

									if (book[i]->GetStock() == 0)
									{
										book[i] = book[bookCount - 1];
										//delete book[bookCount - 1];
										book[bookCount - 1] = NULL;
										bookCount--;
										techCount--;
									}
								}
								else
									break;

							break;
							}
							else
							{
								cout << "Not that much stock is available" << endl;
								break;
							}
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
			if (manageCount == 0 || bookCount == 0)
			{
				cout << "No books are added" << endl;
				return;
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					if (book[i] != NULL && typeid(*(book[i])) == typeid(ManagementBook))
					{
						if (strcmp(book[i]->GetBookName(), name) == 0)
						{
							flag = 1;
							cout << " Book exist please enter required quantity" << endl;
							cin >> quantity;
							if (quantity <= book[i]->GetStock())
							{
								cout << "You can purchase now do you want ? 1/0 " << endl;
								cout << "Total purchase amount " << book[i]->GetPrice()*quantity << endl;
								cout << "Price after offer " << ((ManagementBook*)book[i])->CalculateDiscount(quantity) << endl;
								cin >> userPurchasechoice;
									if (userPurchasechoice == 1)
									{
										book[i]->UpdatePurchase(quantity);
										cout << "Purchase success" << endl;
										if (book[i]->GetStock() == 0)
										{
											book[i] = book[bookCount - 1];
											//delete book[bookCount - 1];
											book[bookCount - 1] = NULL;
											bookCount--;
											manageCount--;
										}
									}
									else
										break;
									break;

							}
							else
							{
								cout << "Not that much stock is available" << endl;
								break;
							}
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

	int countReturn()
	{
		return bookCount;
	}
	int manageCountReturn()
	{
		return manageCount;
	}
	int techCountReturn()
	{
		return techCount;
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
			store.AddBook(bookname, bookChoice);
			break;
		case 2:
			cout << "1 : technical 2 : management 3 : both" << endl;
			cin >> bookChoice;
			store.DisplayBook(bookChoice);
			break;
		case 3:
			cout << " 1 : Technical 2 : Management" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
				if (store.countReturn() == 0 || store.manageCountReturn() == 0)
				{
					cout << "No books added" << endl;
					break;
				}
			}
			else if (bookChoice == 2)
			{
				if (store.countReturn() == 0 || store.techCountReturn() == 0)
				{
					cout << "No books added" << endl;
					break;
				}
			}
			cout << "Enter name of the book " << endl;
			cin >> bookname;
			store.SearchBook(bookname, bookChoice);
			break;
		default: cout << "Invalid choice" << endl;
			break;

		}
		cout << "Do you want to continue? y/n" << endl;
		cin >> ch;
	} while (ch == 'y');
	return 0;

}
