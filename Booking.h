#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Customer.h"
#include "HolidayPackage.h"

using namespace std;

class Booking {
private:
    string bookingId;
    Customer customer;
    HolidayPackage* holidayPtr;
    int nofTravellers;

public:
    // Constructors
    Booking();
    Booking(string id, const Customer& cust, HolidayPackage* hol, int travellers);

    // Destructor
    ~Booking();

    // Setters
    void setBookingId(string id);
    void setCustomer(const Customer& cust);
    void setHoliday(HolidayPackage* hol);
    void setNofTravellers(int travellers);

    // Getters
    string getBookingId() const;
    Customer getCustomer() const;
    HolidayPackage* getHoliday() const;
    int getNofTravellers() const;

    // Other functions
    double calculateTotalCost() const;
    void displayDetails() const;
};

#endif