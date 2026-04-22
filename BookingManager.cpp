#include "BookingManager.h"

// Default constructor
BookingManager::BookingManager() {
    maxBookings = 10;
}

// Overloaded constructor
BookingManager::BookingManager(int maxB) {
    setMaxBookings(maxB);
}

// Setter
void BookingManager::setMaxBookings(int maxB) {
    if (maxB <= 0) {
        throw invalid_argument("Maximum number of bookings must be greater than 0");
    }
    maxBookings = maxB;
}

// Getter
int BookingManager::getMaxBookings() const {
    return maxBookings;
}

// Add booking
void BookingManager::addBooking(const Booking& booking) {
    if (bookings.size() >= maxBookings) {
        throw out_of_range("Booking manager is full. Cannot add more bookings.");
    }

    if (findBookingById(booking.getBookingId()) != -1) {
        throw logic_error("Booking ID already exists.");
    }

    bookings.push_back(booking);
    cout << "Booking added successfully." << endl;
}

// Display all bookings
void BookingManager::displayAllBookings() const {
    if (bookings.empty()) {
        cout << "No bookings available." << endl;
        return;
    }

    cout << "All Bookings" << endl;
    cout << "============" << endl;

    for (int i = 0; i < bookings.size(); i++) {
        cout << endl;
        bookings[i].displayDetails();
        cout << "------------------------" << endl;
    }
}

// Find booking by ID
int BookingManager::findBookingById(string bookingId) const {
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getBookingId() == bookingId) {
            return i;
        }
    }
    return -1;
}

// Remove booking
void BookingManager::removeBooking(string bookingId) {
    int index = findBookingById(bookingId);

    if (index == -1) {
        throw logic_error("Booking not found.");
    }

    bookings.erase(bookings.begin() + index);
    cout << "Booking removed successfully." << endl;
}

// Helper
int BookingManager::getBookingCount() const {
    return bookings.size();
}