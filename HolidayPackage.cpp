#include "HolidayPackage.h"

// Default constructor
HolidayPackage::HolidayPackage() {
    packageId = "UNKNOWN";
    destination = "UNKNOWN";
    duration = 1;
    basePrice = 0.0;
}

// Overloaded constructor
HolidayPackage::HolidayPackage(string id, string dest, int dur, double price) {
    setPackageId(id);
    setDestination(dest);
    setDuration(dur);
    setBasePrice(price);
}

// Virtual destructor
HolidayPackage::~HolidayPackage() {
    // Nothing special to clean up here,
    // but virtual destructor is important for inheritance
}

// Setters
void HolidayPackage::setPackageId(string id) {
    if (id.empty()) {
        throw invalid_argument("Package ID cannot be empty");
    }
    packageId = id;
}

void HolidayPackage::setDestination(string dest) {
    if (dest.empty()) {
        throw invalid_argument("Destination cannot be empty");
    }
    destination = dest;
}

void HolidayPackage::setDuration(int dur) {
    if (dur <= 0) {
        throw invalid_argument("Duration must be greater than 0");
    }
    duration = dur;
}

void HolidayPackage::setBasePrice(double price) {
    if (price < 0) {
        throw invalid_argument("Base price cannot be negative");
    }
    basePrice = price;
}

// Getters
string HolidayPackage::getPackageId() const {
    return packageId;
}

string HolidayPackage::getDestination() const {
    return destination;
}

int HolidayPackage::getDuration() const {
    return duration;
}

double HolidayPackage::getBasePrice() const {
    return basePrice;
}