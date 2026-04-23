#include "Customer.h"

// Default constructor
Customer::Customer() {
    customerId = "UNKNOWN";
    name = "UNKNOWN";
    email = "UNKNOWN";
    phoneNumber = "UNKNOWN";
}

// Overloaded constructor
Customer::Customer(string id, string n, string e, string phone) {
    setCustomerId(id);
    setName(n);
    setEmail(e);
    setPhoneNumber(phone);
}

// Setters
void Customer::setCustomerId(string id) {
    if (id.empty()) {
        throw invalid_argument("Customer ID cannot be empty");
    }
    customerId = id;
}

void Customer::setName(string n) {
    if (n.empty()) {
        throw invalid_argument("Customer name cannot be empty");
    }
    name = n;
}

void Customer::setEmail(string e) {
    if (e.empty()) {
        throw invalid_argument("Customer email cannot be empty");
    }
    email = e;
}

void Customer::setPhoneNumber(string phone) {
    if (phone.empty()) {
        throw invalid_argument("Phone number cannot be empty");
    }
    phoneNumber = phone;
}

// Getters
string Customer::getCustomerId() const {
    return customerId;
}

string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getPhoneNumber() const {
    return phoneNumber;
}

// Display function
void Customer::displayDetails() const {
    cout << "Customer Details" << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}