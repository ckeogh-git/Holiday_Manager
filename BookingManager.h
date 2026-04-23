#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include "Booking.h"
#include "BeachHoliday.h"
#include "CityBreak.h"

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

    void sortBookingsById();
    void sortBookingsByCustomerName();
    void sortBookingsByTotalCost();

    // File handling
    void saveToFile(string filename) const;
    void loadFromFile(string filename);
};

#endif