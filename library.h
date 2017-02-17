#include <string>
using namespace std;

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

};

