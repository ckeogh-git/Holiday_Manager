#include <iostream>
#include "TestHolidayPackage.h"

using namespace std;

// Constructors
TestHolidayPackage::TestHolidayPackage() : HolidayPackage() {}

TestHolidayPackage::TestHolidayPackage(string id, string dest, int dur, double price)
    : HolidayPackage(id, dest, dur, price) {}

// Override functions
double TestHolidayPackage::calculatePrice() const {
    return basePrice; // simple test logic
}

void TestHolidayPackage::displayDetails() const {
    cout << "Package ID: " << packageId << endl;
    cout << "Destination: " << destination << endl;
    cout << "Duration: " << duration << endl;
    cout << "Base Price: " << basePrice << endl;
}

// Single test function
void runHolidayPackageTest() {
    cout << "\n--- Running HolidayPackage Test ---\n" << endl;

    try {
        TestHolidayPackage p("PKG001", "Spain", 7, 899.99);

        p.displayDetails();

        cout << "Calculated Price: " << p.calculatePrice() << endl;

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}