#include <iostream>
#include "BeachHoliday.h"
#include "CityBreak.h"
#include "Customer.h"
#include "Booking.h"
#include "BookingManager.h"

using namespace std;

int main() {
    cout << "Starting program..." << endl << endl;

    // Holidays
    BeachHoliday b1("BH001", "Mallorca", 7, 899.99, true);
    CityBreak c1("CB001", "Paris", 4, 650.00, 3);

    // Customers
    Customer cust1("C001", "Alice Murphy", "alice@gmail.com", "0871234567");
    Customer cust2("C002", "John Kelly", "john@gmail.com", "0857654321");

    // Bookings
    Booking booking1("B002", cust1, &b1, 2);
    Booking booking2("B001", cust2, &c1, 1);

    // Manager
    BookingManager manager(5);

    try {
        manager.addBooking(booking1);
        manager.addBooking(booking2);

        cout << "\nAll bookings:\n" << endl;
        manager.displayAllBookings();

        cout << "\nSorted by Booking ID:\n" << endl;
        manager.sortBookingsById();
        manager.displayAllBookings();

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nProgram finished." << endl;
    return 0;
}