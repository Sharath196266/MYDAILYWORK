//library management
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

struct Borrower {
    string name;
    string borrowerId;
};

struct Transaction {
    string isbn;
    string borrowerId;
    time_t checkoutDate;
    time_t returnDate;
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

    // Function to calculate the difference in days between two dates
    int calculateDaysDifference(time_t start, time_t end) {
        return difftime(end, start) / (60 * 60 * 24);
    }

public:
    // Add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Search for a book by title, author, or ISBN
    void searchBook(const string& query) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title== query || book.author == query || book.isbn == query) {
                cout<<"Book found"<<endl;
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
                cout << ", Status: " << (book.available ? "Available" : "Checked Out") << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the query." << endl;
        }
    }

    // Check out a book to a borrower
    void checkoutBook(const string& isbn, const string& borrowerId) {
        for (auto& book : books) {
            if (book.isbn == isbn && book.available) {
                book.available = false;
                transactions.push_back({isbn, borrowerId, time(nullptr), 0});
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not available or does not exist." << endl;
    }

    // Return a book and calculate fine if overdue
    void returnBook(const string& isbn, const string& borrowerId) {
        for (auto& transaction : transactions) {
            if (transaction.isbn == isbn && transaction.borrowerId == borrowerId && transaction.returnDate == 0) {
                transaction.returnDate = time(nullptr);
                for (auto& book : books) {
                    if (book.isbn == isbn) {
                        book.available = true;
                        break;
                    }
                }
                int daysOverdue = calculateDaysDifference(transaction.checkoutDate, transaction.returnDate) - 14; // assuming a 2-week loan period
                if (daysOverdue > 0) {
                    cout << "Book returned late. Fine: $" << daysOverdue * 0.5 << endl; // assuming $0.5 per day overdue
                } else {
                    cout << "Book returned on time." << endl;
                }
                return;
            }
        }
        cout << "No matching checkout record found." << endl;
    }

    // Add a borrower
    void addBorrower(const Borrower& borrower) {
        borrowers.push_back(borrower);
    }

    // Print all books
    void printAllBooks() {
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
            cout << ", Status: " << (book.available ? "Available" : "Checked Out") << endl;
        }
    }

    // Print all borrowers
    void printAllBorrowers() {
        for (const auto& borrower : borrowers) {
            cout << "Name: " << borrower.name << ", ID: " << borrower.borrowerId << endl;
        }
    }
};

int main() {
    Library library;

    int choice;
    while (true) {
        cout << "\n1. Add a book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Checkout a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Print all books" << endl;
        cout << "6. Print all borrowers" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number." << endl;
            continue; 
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        switch (choice) {
            case 1: {
                Book book;
                cout << "Enter book title: ";
                getline(cin, book.title);
                cout << "Enter book author: ";
                getline(cin, book.author);
                cout << "Enter book ISBN: ";
                getline(cin, book.isbn);
                book.available = true;
                library.addBook(book);
                cout << "Book added successfully." << endl;
                break;
            }
            case 2: {
                string query;
                cout << "Enter search query (title/author/ISBN): ";
                getline(cin, query);
                library.searchBook(query);
                break;
            }
            case 3: {
                string isbn, borrowerId;
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                cout << "Enter borrower ID: ";
                getline(cin, borrowerId);
                library.checkoutBook(isbn, borrowerId);
                break;
            }
            case 4: {
                string isbn, borrowerId;
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                cout << "Enter borrower ID: ";
                getline(cin, borrowerId);
                library.returnBook(isbn, borrowerId);
                break;
            }
            case 5:
                library.printAllBooks();
                break;
            case 6:
                library.printAllBorrowers();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
