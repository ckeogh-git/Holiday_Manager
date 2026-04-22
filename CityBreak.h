#ifndef CITYBREAK_H
#define CITYBREAK_H

#include "HolidayPackage.h"

class CityBreak : public HolidayPackage {
private:
    int nofTours;

public:
    // Constructors
    CityBreak();
    CityBreak(string id, string dest, int dur, double price, int tours);

    // Setter and getter
    void setNofTours(int tours);
    int getNofTours() const;

    // Overridden functions
    double calculatePrice() const override;
    void displayDetails() const override;
};

#endif