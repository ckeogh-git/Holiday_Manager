#include <gtest/gtest.h>
#include <cstdio>
#include <string>

#include "BookingManager.h"
#include "BeachHoliday.h"
#include "CityBreak.h"
#include "Customer.h"
#include "Booking.h"

TEST(BookingManagerTest, AddBookingIncreasesCount) {
    BookingManager manager(2);
    BeachHoliday holiday("BH001", "Spain", 7, 1000.0, true);
    Customer customer("C001", "Test User", "test@mail.com", "123456789");
    Booking booking("B001", customer, &holiday, 1);

    manager.addBooking(booking);

    EXPECT_EQ(manager.getBookingCount(), 1);
    EXPECT_EQ(manager.findBookingById("B001"), 0);
}

TEST(BookingManagerTest, AddBookingThrowsWhenFull) {
    BookingManager manager(1);
    BeachHoliday holiday("BH001", "Spain", 7, 1000.0, true);
    Customer customer("C001", "Test User", "test@mail.com", "123456789");

    Booking booking1("B001", customer, &holiday, 1);
    Booking booking2("B002", customer, &holiday, 1);

    manager.addBooking(booking1);

    EXPECT_THROW(manager.addBooking(booking2), std::out_of_range);
}

TEST(BookingManagerTest, AddBookingThrowsOnDuplicateId) {
    BookingManager manager(2);
    BeachHoliday holiday("BH001", "Spain", 7, 1000.0, true);
    Customer customer("C001", "Test User", "test@mail.com", "123456789");

    Booking booking1("B001", customer, &holiday, 1);
    Booking booking2("B001", customer, &holiday, 2);

    manager.addBooking(booking1);

    EXPECT_THROW(manager.addBooking(booking2), std::logic_error);
}

TEST(BookingManagerTest, RemoveBookingDecreasesCount) {
    BookingManager manager(2);
    BeachHoliday holiday("BH001", "Spain", 7, 1000.0, true);
    Customer customer("C001", "Test User", "test@mail.com", "123456789");
    Booking booking("B001", customer, &holiday, 1);

    manager.addBooking(booking);
    manager.removeBooking("B001");

    EXPECT_EQ(manager.getBookingCount(), 0);
    EXPECT_EQ(manager.findBookingById("B001"), -1);
}

TEST(BookingManagerTest, RemoveBookingThrowsIfMissing) {
    BookingManager manager(2);

    EXPECT_THROW(manager.removeBooking("B999"), std::logic_error);
}

TEST(BookingTest, CalculateTotalCostForBeachHoliday) {
    BeachHoliday holiday("BH001", "Mallorca", 7, 900.0, true);
    Customer customer("C001", "Alice", "alice@mail.com", "123456789");
    Booking booking("B001", customer, &holiday, 2);

    EXPECT_DOUBLE_EQ(booking.calculateTotalCost(), 2200.0);
}

TEST(CityBreakTest, CalculatePriceAddsTourCost) {
    CityBreak cityBreak("CB001", "Paris", 4, 650.0, 3);

    EXPECT_DOUBLE_EQ(cityBreak.calculatePrice(), 800.0);
}

TEST(BeachHolidayTest, CalculatePriceAddsAllInclusiveCharge) {
    BeachHoliday holiday("BH001", "Mallorca", 7, 899.99, true);

    EXPECT_DOUBLE_EQ(holiday.calculatePrice(), 1099.99);
}

TEST(BookingManagerTest, SaveAndLoadFromFilePreservesBookings) {
    const std::string testFile = "test_bookings.txt";

    {
        BookingManager manager(5);

        BeachHoliday beach("BH001", "Mallorca", 7, 899.99, true);
        CityBreak city("CB001", "Paris", 4, 650.0, 3);

        Customer cust1("C001", "Alice Murphy", "alice@gmail.com", "0871234567");
        Customer cust2("C002", "John Kelly", "john@gmail.com", "0857654321");

        Booking booking1("B002", cust1, &beach, 2);
        Booking booking2("B001", cust2, &city, 1);

        manager.addBooking(booking1);
        manager.addBooking(booking2);
        manager.saveToFile(testFile);
    }

    BookingManager loadedManager(5);
    loadedManager.loadFromFile(testFile);

    EXPECT_EQ(loadedManager.getBookingCount(), 2);
    EXPECT_NE(loadedManager.findBookingById("B001"), -1);
    EXPECT_NE(loadedManager.findBookingById("B002"), -1);

    std::remove(testFile.c_str());
}

TEST(BookingManagerTest, FindBookingByIdReturnsMinusOneWhenMissing) {
    BookingManager manager(3);

    EXPECT_EQ(manager.findBookingById("NOT_FOUND"), -1);
}

TEST(BookingManagerTest, ConstructorThrowsForInvalidMaxBookings) {
    EXPECT_THROW(BookingManager manager(0), std::invalid_argument);
}

TEST(BookingTest, ConstructorThrowsForInvalidTravellers) {
    BeachHoliday holiday("BH001", "Spain", 7, 1000.0, true);
    Customer customer("C001", "Test User", "test@mail.com", "123456789");

    EXPECT_THROW(Booking booking("B001", customer, &holiday, 0), std::invalid_argument);
}

TEST(CustomerTest, ConstructorThrowsForEmptyName) {
    EXPECT_THROW(Customer("C001", "", "test@mail.com", "123456789"), std::invalid_argument);
}

TEST(CityBreakTest, ConstructorThrowsForNegativeTours) {
    EXPECT_THROW(CityBreak("CB001", "Paris", 4, 650.0, -1), std::invalid_argument);
}