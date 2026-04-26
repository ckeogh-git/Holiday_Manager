#include <iostream>
#include <limits>
#include <string>

#include "BeachHoliday.h"
#include "CityBreak.h"
#include "Customer.h"
#include "Booking.h"
#include "BookingManager.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string getTextInput(const string& message) {
    string value;
    cout << message;
    getline(cin, value);
    return value;
}

int getIntInput(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail()) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";
        clearInput();
    }
}

double getDoubleInput(const string& message) {
    double value;
    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail()) {
            clearInput();
            return value;
        }

        cout << "Invalid input. Please enter a valid price.\n";
        clearInput();
    }
}

bool getYesNoInput(const string& message) {
    char choice;
    while (true) {
        cout << message << " (y/n): ";
        cin >> choice;
        clearInput();

        if (choice == 'y' || choice == 'Y') {
            return true;
        }
        if (choice == 'n' || choice == 'N') {
            return false;
        }

        cout << "Invalid input. Please enter y or n.\n";
    }
}

void addBookingFromUserInput(BookingManager& manager) {
    cout << "\n--- Create New Booking ---\n";

    string bookingId = getTextInput("Booking ID: ");
    string customerId = getTextInput("Customer ID: ");
    string name = getTextInput("Customer name: ");
    string email = getTextInput("Customer email: ");
    string phone = getTextInput("Customer phone number: ");
    int travellers = getIntInput("Number of travellers: ");

    cout << "\nHoliday type\n";
    cout << "1. Beach Holiday\n";
    cout << "2. City Break\n";
    int holidayChoice = getIntInput("Choose holiday type: ");

    string packageId = getTextInput("Package ID: ");
    string destination = getTextInput("Destination: ");
    int duration = getIntInput("Duration in days: ");
    double basePrice = getDoubleInput("Base price: ");

    Customer customer(customerId, name, email, phone);
    HolidayPackage* holiday = nullptr;

    if (holidayChoice == 1) {
        bool allInclusive = getYesNoInput("All inclusive");
        holiday = new BeachHoliday(packageId, destination, duration, basePrice, allInclusive);
    }
    else if (holidayChoice == 2) {
        int tours = getIntInput("Number of tours: ");
        holiday = new CityBreak(packageId, destination, duration, basePrice, tours);
    }
    else {
        cout << "Invalid holiday type. Booking was not created.\n";
        return;
    }

    Booking booking(bookingId, customer, holiday, travellers);
    manager.addBooking(booking);

    cout << "\nBooking created successfully.\n";
    cout << "Total cost: " << booking.calculateTotalCost() << endl;
}

void removeBookingFromUserInput(BookingManager& manager) {
    cout << "\n--- Remove Booking ---\n";
    string bookingId = getTextInput("Enter booking ID to remove: ");
    manager.removeBooking(bookingId);
}

void showMenu() {
    cout << "\n========== Holiday Booking System ==========" << endl;
    cout << "1. Display all bookings" << endl;
    cout << "2. Add a new booking" << endl;
    cout << "3. Remove a booking" << endl;
    cout << "4. Sort bookings by booking ID" << endl;
    cout << "5. Sort bookings by customer name" << endl;
    cout << "6. Sort bookings by total cost" << endl;
    cout << "7. Save bookings" << endl;
    cout << "0. Exit" << endl;
    cout << "============================================" << endl;
}

int main() {
    BookingManager manager(10);
    int choice;

    try {
        manager.loadFromFile("bookings.txt");
    }
    catch (exception& e) {
        cout << "Could not load bookings: " << e.what() << endl;
    }

    do {
        showMenu();
        choice = getIntInput("Enter your choice: ");

        try {
            switch (choice) {
                case 1:
                    manager.displayAllBookings();
                    break;

                case 2:
                    addBookingFromUserInput(manager);
                    break;

                case 3:
                    removeBookingFromUserInput(manager);
                    break;

                case 4:
                    manager.sortBookingsById();
                    cout << "Bookings sorted by booking ID.\n";
                    break;

                case 5:
                    manager.sortBookingsByCustomerName();
                    cout << "Bookings sorted by customer name.\n";
                    break;

                case 6:
                    manager.sortBookingsByTotalCost();
                    cout << "Bookings sorted by total cost.\n";
                    break;

                case 7:
                    manager.saveToFile("bookings.txt");
                    break;

                case 0:
                    manager.saveToFile("bookings.txt");
                    cout << "Bookings saved. Goodbye.\n";
                    break;

                default:
                    cout << "Invalid choice. Please choose a menu option from 0 to 7.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
