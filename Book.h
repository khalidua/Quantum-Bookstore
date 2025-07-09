#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "DeliveryMethod.h"
using namespace std; 

class Book {
    protected:
        string title;
        string author;
        string isbn;
        string type;
        int year;
        int stock;
        float price;
        DeliveryMethod* delivery;
    public:
        Book() {
            title="";
            author="";
            isbn="";
            type="demo";
            year=0;
            price=0;
            stock=0;
            delivery=new NoDelivery;
        }
        Book(string title, string author, string isbn, int year, float price, int stock, string type)
        :title(title), author(author), isbn(isbn), year(year), price(price),stock(stock),type(type) {}

        virtual ~Book() {}

        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getISBN(){
            return isbn;
        }
        int getYear(){
            return year;
        }
        float getPrice(){
            return price;
        }

        float buy(int quantity,string email,string address){
            if (type=="demo")
            {
                throw runtime_error("Demo books are not for sale");
            }
            if (quantity > stock)
            {
                throw runtime_error("No enough stock Avalaible right now");
            }
            stock=stock-quantity;
            float amount=quantity*this->price;
            if (delivery!=nullptr)
            {
                if (type=="paper")
                {
                    delivery->deliver(address);
                }
                else if(type=="ebook"){
                    delivery->deliver(email);
                }
                else{
                    delivery->deliver("");
                }  
            }
            return amount;                 
        }
};
class PaperBook: public Book{
    public:
        PaperBook(string title, string author, string isbn, int year, float price,int stock)
            : Book(title, author, isbn,year,price,stock,"paper")
        {
            delivery = new ShippingService();
        }
};
class EBook: public Book{
    public:
        EBook(string title, string author, string isbn, int year, float price,int stock)
            : Book(title, author, isbn,year,price,stock,"ebook")
        {
            delivery = new MailService();
        }
};
class DemoBook: public Book{
    public:
        DemoBook(string title, string author, string isbn, int year)
            : Book(title, author, isbn,year,0,0,"demo")
        {
            delivery = new NoDelivery();
        }
};

//easily extensible factory
class BookFactory{
    public:
        Book* CreateBook(string type,string title, string author, string isbn, int year, float price, int stock){
            if (type == "paper") {
                return new PaperBook(title, author, isbn,year, price, stock);
            } else if (type == "ebook") {
                return new EBook(title, author, isbn,year, price, stock);
            } else if (type == "demo") {
                return new DemoBook(title, author, isbn,year);
            } else {
                throw invalid_argument("Unknown book type");
            }
        }
};

#endif
