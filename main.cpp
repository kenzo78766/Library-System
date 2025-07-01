
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::sort
#include <map>       // For std::map

// Structure to represent a Book
struct Book {
    std::string title;
    std::string author;
    int pages;
    double price;
    std::string isbn; // Unique identifier for a book

    // Constructor
    Book(std::string title, std::string author, int pages, double price, std::string isbn)
        : title(title), author(author), pages(pages), price(price), isbn(isbn) {}

    // Function to display book information
    void display() const {
        std::cout << "Title: " << title
                  << ", Author: " << author
                  << ", Pages: " << pages
                  << ", Price: $" << price
                  << ", ISBN: " << isbn << std::endl;
    }
};

// Class to manage the Library System
class Library {
private:
    std::vector<Book> books; // Using a vector to store books
    // Using a map for efficient lookup of books by ISBN
    std::map<std::string, int> isbnIndex; // Maps ISBN to index in the vector

public:
    // Function to add a new book
    void addBook(const Book& book) {
        // Check if book with same ISBN already exists
        if (isbnIndex.count(book.isbn) > 0) {
            std::cout << "Error: Book with ISBN " << book.isbn << " already exists." << std::endl;
            return;
        }
        books.push_back(book);
        isbnIndex[book.isbn] = books.size() - 1; // Store index of the new book
        std::cout << "Book added successfully!" << std::endl;
    }

    // Function to display all books
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "No books in the library." << std::endl;
            return;
        }
        std::cout << "\n--- All Books in Library ---" << std::endl;
        for (const auto& book : books) {
            book.display();
        }
        std::cout << "----------------------------" << std::endl;
    }

    // Function to list all books by a given author
    void findBooksByAuthor(const std::string& authorName) const {
        bool found = false;
        std::cout << "\n--- Books by " << authorName << " ---" << std::endl;
        for (const auto& book : books) {
            if (book.author == authorName) {
                book.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No books found by " << authorName << "." << std::endl;
        }
        std::cout << "----------------------------" << std::endl;
    }

    // Function to count total books in the library
    int countBooks() const {
        return books.size();
    }

    // Function to search for a book by title (linear search for simplicity, can be improved)
    Book* searchBookByTitle(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                return &book;
            }
        }
        return nullptr; // Book not found
    }

    // Function to delete a book by ISBN
    void deleteBookByIsbn(const std::string& isbn) {
        auto it = isbnIndex.find(isbn);
        if (it == isbnIndex.end()) {
            std::cout << "Error: Book with ISBN " << isbn << " not found." << std::endl;
            return;
        }

        int indexToDelete = it->second;

        // Remove from vector and update indices in map
        // This is an O(N) operation for vector. For very large libraries,
        // a different data structure (e.g., std::list or custom linked list)
        // would be more efficient for deletions by value/iterator.
        books.erase(books.begin() + indexToDelete);

        // Update indices in map for elements after the deleted one
        for (auto& pair : isbnIndex) {
            if (pair.second > indexToDelete) {
                pair.second--;
            }
        }
        isbnIndex.erase(it);
        std::cout << "Book with ISBN " << isbn << " deleted successfully." << std::endl;
    }

    // Function to sort books by title using std::sort (Merge Sort or IntroSort typically)
    void sortBooksByTitle() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.title < b.title;
        });
        std::cout << "Books sorted by title." << std::endl;
    }

    // Function to sort books by author using std::sort
    void sortBooksByAuthor() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.author < b.author;
        });
        std::cout << "Books sorted by author." << std::endl;
    }
};

void displayMenu() {
    std::cout << "\n--- Library Management System Menu ---" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Display All Books" << std::endl;
    std::cout << "3. Find Books by Author" << std::endl;
    std::cout << "4. Count Total Books" << std::endl;
    std::cout << "5. Search Book by Title" << std::endl;
    std::cout << "6. Delete Book by ISBN" << std::endl;
    std::cout << "7. Sort Books by Title" << std::endl;
    std::cout << "8. Sort Books by Author" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Library myLibrary;
    int choice;

    // Adding some initial books for demonstration
    myLibrary.addBook(Book("The Lord of the Rings", "J.R.R. Tolkien", 1178, 25.50, "978-0618053267"));
    myLibrary.addBook(Book("The Hobbit", "J.R.R. Tolkien", 310, 15.00, "978-0345339683"));
    myLibrary.addBook(Book("Pride and Prejudice", "Jane Austen", 279, 12.75, "978-0141439518"));
    myLibrary.addBook(Book("1984", "George Orwell", 328, 10.20, "978-0451524935"));

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character after reading choice

        switch (choice) {
            case 1: {
                std::string title, author, isbn;
                int pages;
                double price;
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Pages: ";
                std::cin >> pages;
                std::cout << "Enter Price: ";
                std::cin >> price;
                std::cin.ignore(); // Consume newline
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, isbn);
                myLibrary.addBook(Book(title, author, pages, price, isbn));
                break;
            }
            case 2:
                myLibrary.displayAllBooks();
                break;
            case 3: {
                std::string authorName;
                std::cout << "Enter Author Name: ";
                std::getline(std::cin, authorName);
                myLibrary.findBooksByAuthor(authorName);
                break;
            }
            case 4:
                std::cout << "Total books in library: " << myLibrary.countBooks() << std::endl;
                break;
            case 5: {
                std::string searchTitle;
                std::cout << "Enter Title to search: ";
                std::getline(std::cin, searchTitle);
                Book* foundBook = myLibrary.searchBookByTitle(searchTitle);
                if (foundBook) {
                    std::cout << "Book found: ";
                    foundBook->display();
                } else {
                    std::cout << "Book with title '" << searchTitle << "' not found." << std::endl;
                }
                break;
            }
            case 6: {
                std::string deleteIsbn;
                std::cout << "Enter ISBN of book to delete: ";
                std::getline(std::cin, deleteIsbn);
                myLibrary.deleteBookByIsbn(deleteIsbn);
                break;
            }
            case 7:
                myLibrary.sortBooksByTitle();
                myLibrary.displayAllBooks();
                break;
            case 8:
                myLibrary.sortBooksByAuthor();
                myLibrary.displayAllBooks();
                break;
            case 9:
                std::cout << "Exiting Library Management System. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 9);

    return 0;
}


