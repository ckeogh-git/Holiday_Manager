#include <iostream>
#include "BeachHoliday.h"
#include "CityBreak.h"

using namespace std;

int main() {
    cout << "Starting program..." << endl << endl;

    BeachHoliday b1("BH001", "Mallorca", 7, 899.99, true);
    CityBreak c1("CB001", "Paris", 4, 650.00, 3);

    b1.displayDetails();
    cout << endl;
    c1.displayDetails();

    cout << endl << "Program finished." << endl;
    return 0;
}