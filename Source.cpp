#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <chrono>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

int error(string s) {
	throw runtime_error(s);
}

// ------------ helper functions -------------

bool is_isbn(string isbn) {
	if (regex_match(isbn, regex("[0-9]*-[0-9]+-[0-9]+x?")))
		return true;
	else
		return false;
}

bool is_date(string isbn) {
	if (regex_match(isbn, regex("[0-3][1-9]/[0-1][1-9]/[0-9]{4}")))
		return true;
	else
		return false;
}

string date_today() {
	chrono::system_clock::time_point today = chrono::system_clock::now();
	
}

// ------------ Class Functions -------------

class Book {

private:
	string isbn{};
	string title{};
	string author{};
	string copyrightDate{};
	bool isCheckedOut{ false }; // date?
	string checkoutDate{};

public:
	// -----------------constructor --------------------
	Book(string is, string ti, string au, string cp)
		:isbn{ is }, title{ ti }, author{ au }, copyrightDate{ cp } {
		if (!is_isbn(is)) { throw error(is + " is invalid ISBN.");	}
		if (!is_date(cp)) { throw error(cp + " is an invalid year. Please ensure the date is correct and is in the format dd/mm/yyyy."); }
	}

	string get_isbn() { return isbn; };
	string get_title() { return title; };
	string get_author() { return author; };
	string get_copyright() { return copyrightDate; };
	bool is_checked_out() { return isCheckedOut; };
	void checkin();
	void checkout();

};

void Book::checkout() {
	if (!isCheckedOut)
		isCheckedOut = true;
	else
		throw error("Book already checked out.");
}

void Book::checkin() {
	if (isCheckedOut)
		isCheckedOut = false;
	else
		throw error("Book already checked in.");
}

int main() {
	try {

	Book b = Book("233-555-466x", "1984", "George Orwell", "21/06/1980");
	cout << "isbn: " << b.get_isbn() << " Title: " << b.get_title() << " Author: "
		<< b.get_author() << " Copyright: " << b.get_copyright() << endl;

	Book r = Book("109-005-7434", "Animal Farm", "George Orwell", "01/01/1980");
	cout << "isbn: " << r.get_isbn() << " Title: " << r.get_title() << " Author: "
		<< r.get_author() << " Copyright: " << r.get_copyright() << endl;
	
	Book t = Book("109-005-7434", "Discources", "George Orwell", "12/01/1980");
	cout << "isbn: " << t.get_isbn() << " Title: " << t.get_title() << " Author: "
		<< t.get_author() << " Copyright: " << t.get_copyright() << endl;

	Book q = Book("109-005-7434", "The Republic", "Plato", "39/02/2017");
	cout << "isbn: " << q.get_isbn() << " Title: " << q.get_title() << " Author: "
		<< q.get_author() << " Copyright: " << q.get_copyright() << endl;

	Book u = Book("109-005-7434", "Blank", "Blank", "01/01/0000");
	cout << "isbn: " << u.get_isbn() << " Title: " << u.get_title() << " Author: "
		<< u.get_author() << " Copyright: " << u.get_copyright() << endl;
	
	cout << b.is_checked_out() << endl;
	b.checkout();
	//b.checkout();
	cout << b.is_checked_out() << endl;
	b.checkin();
	cout << b.is_checked_out() << endl;
	//b.checkin();

	}



	catch (runtime_error&e) {
		cout << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cout << "Unknown Error" << endl;
		keep_window_open();
		return 1;
	}

	return 0;
}