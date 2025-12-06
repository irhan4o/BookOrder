#include <iostream>;
#include <string>;

using namespace std;
class Stock {
private:
	int number;
	double price;
public:
	Stock(int num, double pr)
	{	
		number = num;
		price = pr;
	}
	int getNumber()  { return number; }
	double getPrice()  { return price; }
	~Stock() 
	{
		cout << "Stock Destructor Called" << endl;
	}
	void display();
};
void Stock::display()
{
	cout << "Number of Stocks: " << number << endl;
	cout << "Price per Stock: " << price << endl;
}
class Book : public Stock {
private:
	string title;
	string author;
	int year;
public:
	Book(string t, string a, int y, int num, double pr) :Stock(num, pr) 
	{
	  title = t;
	  author = a;
	  year = y;
    }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	int getYear() { return year; }
	~Book() 
	{
		cout << "Book Destructor Called" << endl;
	}
	void display();
};
void Book::display()
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Year: " << year << endl;
	Stock::display();
}
int main()
{
	int n = 0;
	cout << "Enter cout of books: ";
	cin >> n;

	Book* books[50];
	// Validate n
	if (n <= 0 || n > 50)
	{
		cout << "Invalid count of books." << endl;
		return 1;
	}
	
	// Input book details
	for (int i = 0; i < n; i++)
	{
		cout << "Book " << (i + 1) << ":" << endl;
		string t, a;
		int y, num;
		double pr;
		cout << "Enter title: ";
		cin >> t;
		cout << "Enter author: ";
		cin >> a;
		cout << "Enter year: ";
		cin >> y;
		cout << "Enter number of stocks: ";
		cin >> num;
		cout << "Enter price per stock: ";
		cin >> pr;

		Book* book = new Book(t, a, y, num, pr);
		books[i] = book;
	}
	
	// Display all books
	for (int i = 0; i < n; i++)
	{
		books[i]->display();
	}

	// Calculate total price including 9% tax
	int totalStocks = 0;
	for(int i = 0; i < n; i++)
	{
		totalStocks += books[i]->getPrice();
	}
	totalStocks = totalStocks+totalStocks*0.09;
	cout << "Total price including 9% tax: " << totalStocks << endl;

	// Display books published in 2020
	for(int i = 0; i < n; i++)
	{
		if(books[i]->getYear() == 2020)
		{
			cout << "Books published in 2020: " << books[i]->getTitle() << endl;
		}
	}
	

}