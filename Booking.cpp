#include "Booking.h"

// Default constructor
Booking::Booking() {
    bookingId = "UNKNOWN";
    holidayPtr = nullptr;
    nofTravellers = 1;
}

// Overloaded constructor
Booking::Booking(string id, const Customer& cust, HolidayPackage* hol, int travellers) {
    setBookingId(id);
    setCustomer(cust);
    setHoliday(hol);
    setNofTravellers(travellers);
}

// Destructor
Booking::~Booking() {
    // booking does not own/delete holidayPtr here
    // because the holiday object may be managed elsewhere
}

// Setters
void Booking::setBookingId(string id) {
    if (id.empty()) {
        throw invalid_argument("Booking ID cannot be empty");
    }
    bookingId = id;
}

void Booking::setCustomer(const Customer& cust) {
    customer = cust;
}

void Booking::setHoliday(HolidayPackage* hol) {
    if (hol == nullptr) {
        throw invalid_argument("Holiday package cannot be null");
    }
    holidayPtr = hol;
}

void Booking::setNofTravellers(int travellers) {
    if (travellers <= 0) {
        throw invalid_argument("Number of travellers must be greater than 0");
    }
    nofTravellers = travellers;
}

// Getters
string Booking::getBookingId() const {
    return bookingId;
}

Customer Booking::getCustomer() const {
    return customer;
}

HolidayPackage* Booking::getHoliday() const {
    return holidayPtr;
}

int Booking::getNofTravellers() const {
    return nofTravellers;
}

// Calculate total cost
double Booking::calculateTotalCost() const {
    if (holidayPtr == nullptr) {
        throw logic_error("No holiday package assigned to booking");
    }

    return holidayPtr->calculatePrice() * nofTravellers;
}

// Display details
void Booking::displayDetails() const {
    cout << "Booking Details" << endl;
    cout << "Booking ID: " << bookingId << endl;
    cout << "Number of Travellers: " << nofTravellers << endl;
    cout << "Total Cost: " << calculateTotalCost() << endl;
    cout << endl;

    customer.displayDetails();
    cout << endl;

    if (holidayPtr != nullptr) {
        holidayPtr->displayDetails();
    } else {
        cout << "No holiday package assigned." << endl;
    }
}