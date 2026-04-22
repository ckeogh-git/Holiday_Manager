#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Customer {
private:
    string customerId;
    string name;
    string email;
    string phoneNumber;

public:
    // Constructors
    Customer();
    Customer(string id, string n, string e, string phone);

    // Setters
    void setCustomerId(string id);
    void setName(string n);
    void setEmail(string e);
    void setPhoneNumber(string phone);

    // Getters
    string getCustomerId() const;
    string getName() const;
    string getEmail() const;
    string getPhoneNumber() const;

    // Display function
    void displayDetails() const;
};

#endif