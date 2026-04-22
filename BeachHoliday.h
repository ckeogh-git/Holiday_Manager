#ifndef BEACHHOLIDAY_H
#define BEACHHOLIDAY_H

#include "HolidayPackage.h"

class BeachHoliday : public HolidayPackage {
private:
    bool allInclusive;

public:
    BeachHoliday();
    BeachHoliday(string id, string dest, int dur, double price, bool allInc);

    void setAllInclusive(bool allInc);
    bool getAllInclusive() const;

    double calculatePrice() const override;
    void displayDetails() const override;
};

#endif