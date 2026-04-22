#include <iostream>
#include "BeachHoliday.h"

using namespace std;

BeachHoliday::BeachHoliday() : HolidayPackage() {
    allInclusive = false;
}

BeachHoliday::BeachHoliday(string id, string dest, int dur, double price, bool allInc)
    : HolidayPackage(id, dest, dur, price) {
    allInclusive = allInc;
}

void BeachHoliday::setAllInclusive(bool allInc) {
    allInclusive = allInc;
}

bool BeachHoliday::getAllInclusive() const {
    return allInclusive;
}

double BeachHoliday::calculatePrice() const {
    if (allInclusive) {
        return basePrice + 200.0;
    }
    return basePrice;
}

void BeachHoliday::displayDetails() const {
    cout << "Beach Holiday Details" << endl;
    cout << "Package ID: " << packageId << endl;
    cout << "Destination: " << destination << endl;
    cout << "Duration: " << duration << " days" << endl;
    cout << "Base Price: " << basePrice << endl;
    cout << "All Inclusive: " << (allInclusive ? "Yes" : "No") << endl;
    cout << "Total Price: " << calculatePrice() << endl;
}