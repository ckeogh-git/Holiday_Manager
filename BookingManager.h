#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Booking.h"

using namespace std;

class BookingManager {
private:
    vector<Booking> bookings;
    int maxBookings;

public:
    BookingManager();
    BookingManager(int maxB);

    void setMaxBookings(int maxB);
    int getMaxBookings() const;

    void addBooking(const Booking& booking);
    void displayAllBookings() const;
    int findBookingById(string bookingId) const;
    void removeBooking(string bookingId);
    int getBookingCount() const;

    // STL features
    void sortBookingsById();
    void sortBookingsByCustomerName();
    void sortBookingsByTotalCost();
};

#endif