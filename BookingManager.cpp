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

// Find booking by ID using STL find_if
int BookingManager::findBookingById(string bookingId) const {
    auto it = find_if(bookings.begin(), bookings.end(),
        [bookingId](const Booking& b) {
            return b.getBookingId() == bookingId;
        });

    if (it != bookings.end()) {
        return it - bookings.begin();
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

// Sort by booking ID
void BookingManager::sortBookingsById() {
    sort(bookings.begin(), bookings.end(),
        [](const Booking& a, const Booking& b) {
            return a.getBookingId() < b.getBookingId();
        });
}

// Sort by customer name
void BookingManager::sortBookingsByCustomerName() {
    sort(bookings.begin(), bookings.end(),
        [](const Booking& a, const Booking& b) {
            return a.getCustomer().getName() < b.getCustomer().getName();
        });
}

// Sort by total cost
void BookingManager::sortBookingsByTotalCost() {
    sort(bookings.begin(), bookings.end(),
        [](const Booking& a, const Booking& b) {
            return a.calculateTotalCost() < b.calculateTotalCost();
        });
}
// Save bookings to file
void BookingManager::saveToFile(string filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        throw runtime_error("Could not open file for writing.");
    }

    for (const Booking& booking : bookings) {
        HolidayPackage* holiday = booking.getHoliday();

        // Save common booking/customer data first
        outFile << booking.getBookingId() << ","
                << booking.getCustomer().getCustomerId() << ","
                << booking.getCustomer().getName() << ","
                << booking.getCustomer().getEmail() << ","
                << booking.getCustomer().getPhoneNumber() << ","
                << booking.getNofTravellers() << ",";

        // Save holiday type + holiday-specific fields
        if (BeachHoliday* bh = dynamic_cast<BeachHoliday*>(holiday)) {
            outFile << "BeachHoliday" << ","
                    << bh->getPackageId() << ","
                    << bh->getDestination() << ","
                    << bh->getDuration() << ","
                    << bh->getBasePrice() << ","
                    << bh->getAllInclusive();
        }
        else if (CityBreak* cb = dynamic_cast<CityBreak*>(holiday)) {
            outFile << "CityBreak" << ","
                    << cb->getPackageId() << ","
                    << cb->getDestination() << ","
                    << cb->getDuration() << ","
                    << cb->getBasePrice() << ","
                    << cb->getNofTours();
        }

        outFile << endl;
    }

    outFile.close();
    cout << "Bookings saved to file successfully." << endl;
}
// Load bookings from file
void BookingManager::loadFromFile(string filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "No existing file found. Starting with empty booking list." << endl;
        return;
    }

    bookings.clear();

    string bookingId, customerId, customerName, email, phone;
    string holidayType, packageId, destination;
    int travellers, duration;
    double basePrice;
    string extraValue;

    while (getline(inFile, bookingId, ',')) {
        getline(inFile, customerId, ',');
        getline(inFile, customerName, ',');
        getline(inFile, email, ',');
        getline(inFile, phone, ',');

        string travellersStr;
        getline(inFile, travellersStr, ',');
        travellers = stoi(travellersStr);

        getline(inFile, holidayType, ',');
        getline(inFile, packageId, ',');
        getline(inFile, destination, ',');

        string durationStr, priceStr;
        getline(inFile, durationStr, ',');
        getline(inFile, priceStr, ',');
        getline(inFile, extraValue);

        duration = stoi(durationStr);
        basePrice = stod(priceStr);

        Customer customer(customerId, customerName, email, phone);
        HolidayPackage* holidayPtr = nullptr;

        if (holidayType == "BeachHoliday") {
            bool allInclusive = (extraValue == "1" || extraValue == "true");
            holidayPtr = new BeachHoliday(packageId, destination, duration, basePrice, allInclusive);
        }
        else if (holidayType == "CityBreak") {
            int nofTours = stoi(extraValue);
            holidayPtr = new CityBreak(packageId, destination, duration, basePrice, nofTours);
        }

        if (holidayPtr != nullptr) {
            Booking booking(bookingId, customer, holidayPtr, travellers);
            bookings.push_back(booking);
        }
    }

    inFile.close();
    cout << "Bookings loaded from file successfully." << endl;
}