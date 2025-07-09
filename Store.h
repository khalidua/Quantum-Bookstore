#ifndef STORE_H
#define STORE_H

#include "Book.h"
#include <map>
#include <vector>
using namespace std; 

class Store {
    protected:
        map<string,Book*> inventory;
        BookFactory factory;
    public:
        void addBook(string title, string author, string isbn, int year, float price,int stock,string type){
            Book* newBook = factory.CreateBook(type, title, author, isbn, year, price, stock);
            inventory[isbn]=newBook;
        }
        vector<string> removeOutdatedBooks(int year){
            vector<string> removed;
            for(auto&[isbn,book] : inventory){
                if (2025 - book->getYear()> year)
                {
                    removed.push_back(isbn);
                }
            }
            for(auto& isbn : removed){
                inventory.erase(isbn);
            }
            return removed;
        }
        void buyBook(string isbn, int quantity, string email,string address){
            bool found=false;
            for(auto&[id,book] : inventory){
                if (id==isbn)
                {
                    found=true;
                }
            }
            if (found)
            {
                inventory[isbn]->buy(quantity,email ,address);
            }
            else{
                throw runtime_error("Book is not found");
            }
        }

};

#endif