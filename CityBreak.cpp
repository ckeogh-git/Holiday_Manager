#include <iostream>
#include <stdexcept>
#include "CityBreak.h"

using namespace std;

// Default constructor
CityBreak::CityBreak() : HolidayPackage() {
    nofTours = 0;
}

// Overloaded constructor
CityBreak::CityBreak(string id, string dest, int dur, double price, int tours)
    : HolidayPackage(id, dest, dur, price) {
    setNofTours(tours);
}

// Setter
void CityBreak::setNofTours(int tours) {
    if (tours < 0) {
        throw invalid_argument("Number of tours cannot be negative");
    }
    nofTours = tours;
}

// Getter
int CityBreak::getNofTours() const {
    return nofTours;
}

// Calculate price
double CityBreak::calculatePrice() const {
    return basePrice + (nofTours * 50.0);
}

// Display details
void CityBreak::displayDetails() const {
    cout << "City Break Details" << endl;
    cout << "Package ID: " << packageId << endl;
    cout << "Destination: " << destination << endl;
    cout << "Duration: " << duration << " days" << endl;
    cout << "Base Price: " << basePrice << endl;
    cout << "Number of Tours: " << nofTours << endl;
    cout << "Total Price: " << calculatePrice() << endl;
}