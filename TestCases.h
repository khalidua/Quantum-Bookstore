#ifndef TESTCASES_H
#define TESTCASES_H

#include "Store.h"
#include <iostream>
using namespace std;

class TestCases {
private:
    Store store;
    
public:
    void testAddBooks() {
        cout << "Testing Add Books..." << endl;
        
        store.addBook("Book 1", "Author 1", "ISBN001", 1999, 200.0, 10, "paper");
        store.addBook("Book 2", "Author 2", "ISBN002", 1949, 250.0, 5, "paper");
        store.addBook("Book 3", "Author 3", "ISBN003", 2020, 350.0, 20, "ebook");
        store.addBook("Sample Book", "Demo Author", "ISBN004", 2023, 0.00, 0, "demo");
        
        cout << "Books added successfully!" << endl;
    }
    
    void testRemoveOutdatedBooks() {
        cout << "Testing Remove Outdated Books..." << endl;
        // Remove books older than 50 years
        vector<string> removed = store.removeOutdatedBooks(50);
        cout << "Removed " << removed.size() <<" outdated books" << endl;
        for(string& isbn : removed) {
            cout << "Removed book with ISBN: " << isbn << endl;
        }
    }
    
    void testBuyBooks() {
        cout << "Testing Buy Books..." << endl;
        try {
            // Buy a paper book
            cout << "Attempting to buy 2 copies of ISBN001..." << endl;
            store.buyBook("ISBN001", 2, "customer@email.com", "Cairo");
            cout << "Purchase successful!" << endl;
        } catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        
        try {
            // Buy an ebook
            cout << "Attempting to buy 1 copy of ISBN003..." << endl;
            store.buyBook("ISBN003", 1, "customer@email.com", "Giza");
            cout << "Purchase successful!" << endl;
        } catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        
        try {
            // Try to buy a demo book (fail)
            cout << "Attempting to buy 1 copy of ISBN004..." << endl;
            store.buyBook("ISBN004", 1, "test@email.com", "Alexandria");
        } catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        
        try {
            // Try to buy non-existent book
            cout << "Attempting to buy non-existent book..." << endl;
            store.buyBook("non-existent", 1, "test@email.com", "october city");
        } catch(const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    void runAllTests() {
        cout << "===== Starting all test cases =====" << endl;
        testAddBooks();
        cout << endl;
        testRemoveOutdatedBooks();
        cout << endl;
        testBuyBooks();
        cout << endl;
        cout << "===== Test cases Completed =====" << endl;
    }
};

#endif 