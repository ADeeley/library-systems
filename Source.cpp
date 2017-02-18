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

void Patron::set_fee(double f) {
	if (fee >= 0)
		fee = f;
	else
		throw error("Fee must be greater than 0"); // error not throwing - maybe not recognising minus numbers in doubles?
}

bool Patron::owes_fee() {
	if (fee > 0)
		return true;
	else if (fee == 0)
		return false;
	else
		throw error("Fee is less than $0");
}



void library_class_test() {
	Library l = Library();
	l.add_book(Book("273-597-123x", "1984", "George Orwell", genre::fiction, "21/06/1980"));
	l.add_book(Book("235-555-466x", "Ubik", "PK Dick", genre::children, "12/03/1970"));
	l.add_book(Book("098-655-234x", "Valis", "PK Dick", genre::periodical, "12/03/1970"));
	l.add_book(Book("291-394-497x", "Slaugherhouse 5", "Kurt Vonnegut", genre::nonfiction, "12/03/1970"));
	l.add_book(Book("456-501-447x", "Eye In The Sky", "PK Dick", genre::biography, "12/03/1970"));

	l.add_patron(Patron("Adam D", 89348349));
	l.add_patron(Patron("Charlie P", 63516381));
	l.add_patron(Patron("Mable B", 38516381));
	l.add_patron(Patron("Shelly B", 38138418));
	cout << '\n' << "Books in library:"   << endl;
	l.get_books();
	cout << '\n' << "Library patrons: " << endl;
	l.get_patrons();

	//-------- checkout tests ------------
	l.checkout_book("1984");
	l.get_books();
	//l.checkout_book("1984");
	//l.checkout_book("1347");

	//-------- checkin tests ------------
	l.checkin_book("1984");
	l.get_books();
	//l.checkin_book("1984");
	l.checkin_book("1457");

}

void book_class_tests() {
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
}

void patron_class_tests() {
	// ----------  Patron tests -----------
	/*Patron p = Patron("Adam D", 89348349);
	cout << p.get_fee() << endl;
	cout << p.owes_fee() << endl;
	p.set_fee(15.33);
	cout << p.get_fee() << endl;
	p.set_fee(-1);
	cout << p.get_fee() << endl;
	cout << p.owes_fee() << endl;*/
}

void genre_enum_tests() {

	// ---------- Genre tests -----------

	//Book b = Book("273-597-123x", "1984", "George Orwell", genre::fiction, "21/06/1980");
	//Book c = Book("235-555-466x", "Ubik", "PK Dick", genre::children,  "12/03/1970");
	//Book d = Book("098-655-234x", "Valis", "PK Dick", genre::periodical, "12/03/1970");
	//Book e = Book("291-394-497x", "Slaugherhouse 5", "Kurt Vonnegut", genre::nonfiction, "12/03/1970");
	//Book f = Book("456-501-447x", "Ubik", "PK Dick", genre::biography, "12/03/1970");
	//// ---------- operator tests -----------

	//bool d = b == c;
	//bool e = b != c;
	//if (d &! e)
	//	cout << "True" << endl;
	//else
	//	cout << "False" << endl;

	//cout << b << c;
}

int main() {
	try {
	/*
	genre_enum_tests();
	patron_class_tests();
	book_class_tests();
	library_class_test();
	*/
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