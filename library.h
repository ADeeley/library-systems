#include <string>
using namespace std;

enum class genre { fiction = 1, nonfiction, periodical, biography, children };

// ------------ helper functions -------------

int error(string s) {
	throw runtime_error(s);
}

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


class Book {

public:

	Book(string is, string ti, string au, genre ge, string cp)
		:isbn{ is }, title{ ti }, author{ au }, copyrightDate{ cp }, gen{ ge }
	{
		if (!is_isbn(is)) { throw error(is + " is invalid ISBN."); }
		if (!is_date(cp)) { throw error(cp + " is an invalid year. Please ensure the date is correct and is in the format dd/mm/yyyy."); }
	}

	string get_isbn() { return isbn; };
	string get_title() { return title; };
	string get_author() { return author; };
	string get_copyright() { return copyrightDate; };
	bool is_checked_out() { return isCheckedOut; };
	void checkin();
	void checkout();

private:

	string isbn{};
	string title{};
	string author{};
	genre gen;
	string copyrightDate{};
	bool isCheckedOut{ false }; // date?
	string checkoutDate{};
};

ostream& operator<<(ostream& os, Book& bk) {
	char checkedOut = (bk.is_checked_out()) ? checkedOut = 'Y' : checkedOut = 'N';		
	return os << bk.get_title() << '\n' << bk.get_author() << '\n' << bk.get_isbn() << "\nChecked out: " << checkedOut <<  endl;
}

bool operator==(Book& b, Book& c) {
	return b.get_isbn() == c.get_isbn();
}

bool operator!=(Book& b, Book& c) {
	return b.get_isbn() != c.get_isbn();
}


class Patron {

public:

	Patron(string usr, int cnum)
		:user_name{ usr }, card_number{ cnum } {}

	string get_user_name() { return user_name; };
	int get_card_number() { return card_number; };
	double get_fee() { return fee; };
	void set_fee(double f);
	bool owes_fee();

private:

	string user_name{};
	int card_number{};
	double fee{0.0};
};

ostream& operator<<(ostream& os, Patron& p) {

	return os << p.get_user_name() << p.get_card_number() << endl;
}


class Library {

public:

	struct transaction {
		Book b;
		Patron p;
		string Date;
	};
	void add_book(Book b) { books.push_back(b); };
	void add_patron(Patron p) { patrons.push_back(p); };
	int checkout_book(string title);
	int checkin_book(string title);
	void get_books();
	void get_patrons();

private:

	vector<Book>books{};
	vector<Patron>patrons{};
};

void Library::get_books() {

	for (Book b : books)
		cout << b;
}

void Library::get_patrons() {

	for (Patron p : patrons)
		cout << p;
}

int Library::checkout_book(string title) {

	for (int b =0; b < books.size(); b++)
		if (books[b].get_title() == title) {
			books[b].checkout();
			return 1;
		}
	error("Book not in library.");
	return 0;
}

int Library::checkin_book(string title) {

	for (int b = 0; b < books.size(); b++)
		if (books[b].get_title() == title) {
			books[b].checkin();
			return 1;
		}
	error("Book not in library.");
	return 0;
}