#ifndef TESTHOLIDAYPACKAGE_H
#define TESTHOLIDAYPACKAGE_H

#include "HolidayPackage.h"

// Concrete class for testing (since HolidayPackage is abstract)
class TestHolidayPackage : public HolidayPackage {
public:
    TestHolidayPackage();
    TestHolidayPackage(string id, string dest, int dur, double price);

    double calculatePrice() const override;
    void displayDetails() const override;
};

// Test function (we will only call ONE in main)
void runHolidayPackageTest();

#endif