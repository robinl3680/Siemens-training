#pragma once
#include <string>
#include <string.h>
#include<iostream>
using namespace std;
class Book
{
private:
	char *bookName;
	int stock;
	float price;
public:
	Book()
	{

	}
	Book(char *name, int st,float pri) : bookName(new char[strlen(name) + 1]), stock(st), price(pri)
	{
		strcpy(bookName, name);
	}

/*	void SetBookDetails(char *name,int st, float pri)

	{
		strcpy(bookName, name);
		stock = st;
		price = pri;
	}
*/
	void DisplayBookDetails()
	{
		cout << "Book details" << endl;
		cout << "---------------------" << endl;
		cout << "name : " << bookName << endl;
		cout << "stock : " << stock << endl;
		cout << "price : " << price << endl;
	}
	int SearchForBook(char *book)
	{
		if (strcmp(book,bookName) == 0 )
			return 1;
		return 0;
	}
	void UpdateStock(int count)
	{
		stock += count;
	}
	int getStock()
	{
		return stock;
	}
	void updatePurchase(int st)
	{
		stock -= st;
	}
	float getPrice()
	{
		return price;
	}
	~Book()
	{
		delete[] bookName;
	}
};

int main()
{
	int choice;
	int userPurchaseChoice;
	char name[50];
	int flag,limit=0;
	flag = 0;
	int newStock,quantity;
	int bookCount = 0;
	float price;
	
	Book *btr[3];
	char repeat;
	for (int i = 0; i < 3; i++)
		btr[i] = NULL;
	do
	{
		cout << "Make a choice 1 : add book, 2 : display book, 3 : search book " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			flag = 0;
			cout << " Enter name of the book" << endl;
			cin >> name;
			for (int i = 0; i < 3; i++)
			{
				if (btr[i] != NULL)
				{

					if (btr[i]->SearchForBook(name) == 1)
					{
						cout << "Book already exists update the count " << endl;
						cin >> newStock;
						flag = 1;
						btr[i]->UpdateStock(newStock);
						break;
					}
				}

				else
				{

					if (bookCount <= 2)
					{
						cout << "New book please provide stock and price " << endl;
						cin >> newStock >> price;
						btr[bookCount++] = new Book(name, newStock, price);
						break;
					}
					else
					{
						cout << "limit was reached" << endl;
						break;
					}
				}
			}
				
			
			break;
		case 2:
			if (bookCount == 0)
			{
				cout << "No book added" << endl;
				break;
			}
			for (int i = 0; i < bookCount; i++)
			{
			
					btr[i]->DisplayBookDetails();
			
			
			}
				break;
		case 3: cout << "Enter book name " << endl;
			cin >> name;
			flag = 0;
			if (bookCount == 0)
			{
				cout << "No books are added" << endl;
			}
			else
			{
				for (int i = 0; i < bookCount; i++)
				{
					if (btr[i] != NULL)
					{
						if (btr[i]->SearchForBook(name) == 1)
						{
							flag = 1;
							cout << " Book exist please enter required quantity" << endl;
							cin >> quantity;
							if (quantity <= btr[i]->getStock())
							{
								cout << "You can purchase now do you want ? 1/0" << endl;
								cin >> userPurchaseChoice;
								if (userPurchaseChoice == 1)
								{
									btr[i]->updatePurchase(quantity);

									cout << "Total purchase amount " << btr[i]->getPrice()*quantity << endl;

									if (btr[i]->getStock() == 0)
									{
										btr[i] = btr[bookCount - 1];
										//delete book[bookCount - 1];
										btr[bookCount - 1] = NULL;
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
				}
				if (flag == 0)
				{
					cout << "No match found" << endl;

				}
			}
			break;
		default: cout << "Invalid choice" << endl;
			break;

		}
		cout << "Do you want to continue ? y/n" << endl;
		cin >> repeat;
	} while (repeat == 'y');


	for (int i = 0; i < 3; i++)
	{
		delete btr[i];
		btr[i] = NULL;
	}
	return 0;

}
