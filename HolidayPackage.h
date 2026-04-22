#ifndef HOLIDAYPACKAGE_H
#define HOLIDAYPACKAGE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class HolidayPackage {
protected:
    string packageId;
    string destination;
    int duration;
    double basePrice;

public:
    // Default constructor
    HolidayPackage();

    // Overloaded constructor
    HolidayPackage(string id, string dest, int dur, double price);

    // Virtual destructor
    virtual ~HolidayPackage();

    // Setters
    void setPackageId(string id);
    void setDestination(string dest);
    void setDuration(int dur);
    void setBasePrice(double price);

    // Getters
    string getPackageId() const;
    string getDestination() const;
    int getDuration() const;
    double getBasePrice() const;

    // Pure virtual functions
    virtual double calculatePrice() const = 0;
    virtual void displayDetails() const = 0;
};

#endif