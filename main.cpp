#include <iostream>
#include "BeachHoliday.h"
#include "CityBreak.h"
#include "Customer.h"
#include "Booking.h"
#include "BookingManager.h"

using namespace std;

int main() {
    cout << "Starting program..." << endl << endl;

    BeachHoliday b1("BH001", "Mallorca", 7, 899.99, true);
    CityBreak c1("CB001", "Paris", 4, 650.00, 3);

    Customer cust1("C001", "Alice Murphy", "alice@gmail.com", "0871234567");
    Customer cust2("C002", "John Kelly", "john@gmail.com", "0857654321");

    Booking booking1("B001", cust1, &b1, 2);
    Booking booking2("B002", cust2, &c1, 1);

    BookingManager manager(5);

    try {
        manager.addBooking(booking1);
        manager.addBooking(booking2);

        cout << endl;
        manager.displayAllBookings();

        cout << endl << "Booking count: " << manager.getBookingCount() << endl;

        cout << endl << "Removing booking B001..." << endl;
        manager.removeBooking("B001");

        cout << endl;
        manager.displayAllBookings();

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl << "Program finished." << endl;
    return 0;
}