#include <iostream>
#include <string>
using namespace std;

// Structure to represent a book in the library
struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

// Structure to represent the stack of issued books
struct IssuedBook {
    int id;
    string title;
    IssuedBook* next;
};

// Class to manage the linked list of books
class Library {
private:
    Book* head;

public:
    Library() : head(nullptr) {}

    // Function to add a new book to the library
    void addBook(int id, string title, string author) {
        Book* newBook = new Book();
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->next = head;
        head = newBook;
        cout << "Book added successfully!\n";
    }

    // Function to display all the books in the library
    void displayBooks() {
        if (head == nullptr) {
            cout << "No books in the library!\n";
            return;
        }
        Book* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
            temp = temp->next;
        }
    }

    // Function to search for a book by its ID
    void searchBook(int id) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Book found! Title: " << temp->title << ", Author: " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

    // Function to delete a book by its ID
    void deleteBook(int id) {
        if (head == nullptr) {
            cout << "Library is empty!\n";
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book deleted successfully!\n";
            return;
        }

        Book* temp = head;
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Book not found!\n";
            return;
        }

        Book* bookToDelete = temp->next;
        temp->next = temp->next->next;
        delete bookToDelete;
        cout << "Book deleted successfully!\n";
    }
};

// Class to manage the stack of issued books
class IssuedBooks {
private:
    IssuedBook* top;

public:
    IssuedBooks() : top(nullptr) {}

    // Function to issue a book (push onto stack)
    void issueBook(int id, string title) {
        IssuedBook* newBook = new IssuedBook();
        newBook->id = id;
        newBook->title = title;
        newBook->next = top;
        top = newBook;
        cout << "Book issued successfully!\n";
    }

    // Function to return a book (pop from stack)
    void returnBook() {
        if (top == nullptr) {
            cout << "No books are issued!\n";
            return;
        }

        IssuedBook* temp = top;
        top = top->next;
        cout << "Book returned! Title: " << temp->title << endl;
        delete temp;
    }

    // Function to display all issued books
    void displayIssuedBooks() {
        if (top == nullptr) {
            cout << "No books are issued!\n";
            return;
        }

        IssuedBook* temp = top;
        while (temp != nullptr) {
            cout << "Issued Book ID: " << temp->id << ", Title: " << temp->title << endl;
            temp = temp->next;
        }
    }
};

// Main function to drive the library management system
int main() {
    Library lib;
    IssuedBooks issued;

    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System Menu\n";
        cout << "1. Add a Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Issue a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Display Issued Books\n";
        cout << "7. Delete a Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID to Search: ";
            cin >> id;
            lib.searchBook(id);
            break;

        case 4:
            cout << "Enter Book ID to Issue: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            issued.issueBook(id, title);
            break;

        case 5:
            issued.returnBook();
            break;

        case 6:
            issued.displayIssuedBooks();
            break;

        case 7:
            cout << "Enter Book ID to Delete: ";
            cin >> id;
            lib.deleteBook(id);
            break;

        case 0:
            cout << "Exiting the system...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}