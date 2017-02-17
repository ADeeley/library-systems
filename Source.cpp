#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "library.h"


using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

// ------------ Class Functions -------------


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

bool operator==(Book& b, Book& c) {
	return b.get_isbn() == c.get_isbn();
}

bool operator!=(Book& b, Book& c) {
	return b.get_isbn() != c.get_isbn();
}

ostream& operator<<(ostream& os, Book& bk) {
	return os << bk.get_title() << '\n' << bk.get_author() << '\n' << bk.get_isbn() << endl;
}

int main() {
	try {

	//Book b = Book("233-555-466x", "1984", "George Orwell", "21/06/1980");
	//cout << "isbn: " << b.get_isbn() << " Title: " << b.get_title() << " Author: "
	//	<< b.get_author() << " Copyright: " << b.get_copyright() << endl;

	//Book r = Book("109-005-7434", "Animal Farm", "George Orwell", "01/01/1980");
	//cout << "isbn: " << r.get_isbn() << " Title: " << r.get_title() << " Author: "
	//	<< r.get_author() << " Copyright: " << r.get_copyright() << endl;
	//
	//Book t = Book("109-005-7434", "Discources", "George Orwell", "12/01/1980");
	//cout << "isbn: " << t.get_isbn() << " Title: " << t.get_title() << " Author: "
	//	<< t.get_author() << " Copyright: " << t.get_copyright() << endl;

	//Book q = Book("109-005-7434", "The Republic", "Plato", "39/02/2017");
	//cout << "isbn: " << q.get_isbn() << " Title: " << q.get_title() << " Author: "
	//	<< q.get_author() << " Copyright: " << q.get_copyright() << endl;

	//Book u = Book("109-005-7434", "Blank", "Blank", "01/01/0000");
	//cout << "isbn: " << u.get_isbn() << " Title: " << u.get_title() << " Author: "
	//	<< u.get_author() << " Copyright: " << u.get_copyright() << endl;
	//
	//cout << b.is_checked_out() << endl;
	//b.checkout();
	////b.checkout();
	//cout << b.is_checked_out() << endl;
	//b.checkin();
	//cout << b.is_checked_out() << endl;
	////b.checkin();


	Book b = Book("233-555-466x", "1984", "George Orwell", genre::fiction, "21/06/1980");
	Book c = Book("233-555-466x", "Ubik", "PK Dick", genre::fiction,  "12/03/1970");
	// ---------- operator tests -----------

	bool d = b == c;
	bool e = b != c;
	if (d &! e)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	cout << b << c;



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