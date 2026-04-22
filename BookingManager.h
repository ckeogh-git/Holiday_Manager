#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Booking.h"

using namespace std;

class BookingManager {
private:
    vector<Booking> bookings;
    int maxBookings;

public:
    // Constructors
    BookingManager();
    BookingManager(int maxB);

    // Setter and getter
    void setMaxBookings(int maxB);
    int getMaxBookings() const;

    // Main functions
    void addBooking(const Booking& booking);
    void displayAllBookings() const;
    int findBookingById(string bookingId) const;
    void removeBooking(string bookingId);

    // Extra helper
    int getBookingCount() const;
};

#endif