#include <iostream>
#include "BeachHoliday.h"

using namespace std;

int main() {
    cout << "Starting program..." << endl << endl;

    BeachHoliday b1("BH001", "Mallorca", 7, 899.99, true);
    b1.displayDetails();

    cout << endl << "Program finished." << endl;
    return 0;
}