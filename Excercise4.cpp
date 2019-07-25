#pragma once
#include <string>
#include <string.h>
#include<iostream>
using namespace std;
class Book
{
protected:
	char *bookName;
	int stock;
	float price;
public:
	Book()
	{

	}
	Book(char *name, int st, float pri) : bookName(new char[strlen(name) + 1]), stock(st), price(pri)
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
		if (strcmp(book, bookName) == 0)
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
class TechnicalBook : public Book
{
	const int rateOfDiscount;
public :
	
	TechnicalBook(char *name, int st, float pri) : Book(name,st,pri) ,rateOfDiscount(5)
	{
	}
	float CalculateDiscount(int quantity)
	{
		return ((this->getPrice()*quantity)-((rateOfDiscount/100) * this->getPrice() * quantity));
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
		return ((this->getPrice()*quantity) - ((rateOfDiscount / 100) * this->getPrice() * quantity));
	}
};


int main()
{
	int choice;
	int userPurchaseChoice;
	char name[50];
	int flag, limit = 0;
	flag = 0;
	int newStock, quantity;
	int bookCount1 = 0;
	int bookCount2 = 0;
	float price;
	int bookChoice;

	TechnicalBook *btr[3];
	ManagementBook *btr2[3];
	char repeat;
	for (int i = 0; i < 3; i++)
	{
		btr[i] = NULL;
		btr2[i] = NULL;
	}
	do
	{
		cout << "Make a choice 1 : add book, 2 : display book, 3 : search book " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			flag = 0;
			cout << " Technical or management ? 1 : technical 2 : management" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
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

						if (bookCount1 <= 2)
						{
							cout << "New book please provide stock and price " << endl;
							cin >> newStock >> price;
							btr[bookCount1++] = new TechnicalBook(name, newStock, price);
							break;
						}
						else
						{
							cout << "limit was reached" << endl;
							break;
						}
					}
				}
			}
			else if (bookChoice == 2)
			{
				cout << " Enter name of the book" << endl;
				cin >> name;
				for (int i = 0; i < 3; i++)
				{
					if (btr2[i] != NULL)
					{

						if (btr2[i]->SearchForBook(name) == 1)
						{
							cout << "Book already exists update the count " << endl;
							cin >> newStock;
							flag = 1;
							btr2[i]->UpdateStock(newStock);
							break;
						}
					}

					else
					{

						if (bookCount2 <= 2)
						{
							cout << "New book please provide stock and price " << endl;
							cin >> newStock >> price;
							btr2[bookCount2++] = new ManagementBook(name, newStock, price);
							break;
						}
						else
						{
							cout << "limit was reached" << endl;
							break;
						}
					}
				}
			}
			else
				cout << "Invalid choice" << endl;


			break;
		case 2:
			if (bookCount1 == 0 && bookCount1 == 0)
			{
				cout << "No book added" << endl;
				break;
			}
			cout << "Which book 1 : technical 2 : management 3 : both" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
				if (bookCount1 == 0)
				{
					cout << "No book added" << endl;
					break;
				}
				for (int i = 0; i < bookCount1; i++)
				{

					btr[i]->DisplayBookDetails();


				}
			}
			else if (bookChoice == 2)
			{
				if (bookCount2 == 0)
				{
					cout << "No book added" << endl;
					break;
				}
				for (int i = 0; i < bookCount2; i++)
				{

					btr2[i]->DisplayBookDetails();


				}
			}
			else if (bookChoice == 3)
			{
				for (int i = 0; i < bookCount1; i++)
				{

					btr[i]->DisplayBookDetails();


				}
				for (int i = 0; i < bookCount2; i++)
				{

					btr2[i]->DisplayBookDetails();

				}
			}
			else
			{
				cout << "Invalid choice " << endl;
				break;
			}
			break;
		case 3:
			if (bookCount1 == 0 && bookCount1 == 0)
			{
				cout << "No book added" << endl;
				break;
			}
			cout << "Technical or Management ? 1 : Technical 5% off, 2 : Management 10%" << endl;
			cin >> bookChoice;
			if (bookChoice == 1)
			{
				if (bookCount1 == 0)
				{
					cout << "No book added" << endl;
					break;
				}
				else
				{
					cout << "Enter book name " << endl;
					cin >> name;
					flag = 0;
					for (int i = 0; i < bookCount1; i++)
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
									cout << "You can purchase now do you want ? 1/0 " << endl;
									cout << "Total purchase amount " << btr[i]->getPrice()*quantity << endl;
									cout << "Price after offer " << btr[i]->CalculateDiscount(quantity) << endl;
									
									cin >> userPurchaseChoice;
									if (userPurchaseChoice == 1)
									{
										btr[i]->updatePurchase(quantity);
										if (btr[i]->getStock() == 0)
										{
											btr[i] = btr[bookCount1 - 1];
											//delete book[bookCount - 1];
											btr[bookCount1 - 1] = NULL;
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
					}
					if (flag == 0)
					{
						cout << "No match found" << endl;

					}
				}
			}
			else if (bookChoice == 2)
			{
				if (bookCount2 == 0)
				{
					cout << "No book added" << endl;
					break;
				}
				cout << "Enter book name " << endl;
				cin >> name;
				flag = 0;
				if (bookCount2 == 0)
				{
					cout << "No books are added" << endl;
				}
				else
				{
					for (int i = 0; i < bookCount2; i++)
					{
						if (btr2[i] != NULL)
						{
							if (btr2[i]->SearchForBook(name) == 1)
							{
								flag = 1;
								cout << " Book exist please enter required quantity" << endl;
								cin >> quantity;
								if (quantity <= btr2[i]->getStock())
								{
									cout << "You can purchase now do you want ? 1/0 " << endl;
									cout << "Total purchase amount " << btr2[i]->getPrice()*quantity << endl;
									cout << "Price after offer " << btr2[i]->CalculateDiscount(quantity) << endl;

									cin >> userPurchaseChoice;
									if (userPurchaseChoice == 1)
									{
										btr2[i]->updatePurchase(quantity);
										if (btr2[i]->getStock() == 0)
										{
											btr2[i] = btr2[bookCount1 - 1];
											//delete book[bookCount - 1];
											btr2[bookCount2 - 1] = NULL;
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
					}
					if (flag == 0)
					{
						cout << "No match found" << endl;

					}
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
	return 0;

}
