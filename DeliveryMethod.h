#ifndef DELIVERYMETHOD_H
#define DELIVERYMETHOD_H

#include <iostream>
#include <string>
using namespace std; 

class DeliveryMethod {
    public:
        virtual void deliver(string info) = 0;
        virtual ~DeliveryMethod(){}
};

class ShippingService : public DeliveryMethod {
    public:
        void deliver(string address){
            cout<<"Shipping to Address: "<< address <<endl;
        }
};

class MailService : public DeliveryMethod {
    public:
    void deliver(string email){
        cout<<"Sending via mail to : "<< email<<endl;
    }
};

class NoDelivery : public DeliveryMethod {
    public:
    void deliver(string none){
        cout<<"This book is not for sale" << endl;
    }
};

#endif
