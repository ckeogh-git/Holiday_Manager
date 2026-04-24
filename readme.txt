installation and running guide
Step 1: install msys2 https://www.msys2.org/
Step 2: open the UCRT64 terminal
Step 3: Run pacman -Syu
if closes reopen and run pacman -Syu
Step 4: install g++ ;
 pacman -S mingw-w64-ucrt-x86_64-gcc

verify installation with 
g++ --version

install gtest
step 1
pacman -S mingw-w64-ucrt-x86_64-gtest
installing gcovr
pacman -S mingw-w64-ucrt-x86_64-gcovr use this command to install the library

if that does not work do pacman -Ss gcovr and replace the above command with the mingw of ucrt64 given from that

cyclomatic complexity calculator
step 1 install a venv using below commands
python -m venv venv
source venv/bin/activate
pip install lizard

change directory to file directory
to get your file directory easily just go to the file location and copy as path
then paste it in to the example file directory
cd (example file directory)


===============================================================================================================================================
compilation and running
Main=== run the below command
g++ -std=c++17 main.cpp BookingManager.cpp Booking.cpp Customer.cpp HolidayPackage.cpp BeachHoliday.cpp CityBreak.cpp -o main.exe
to run the main enter 
./main.exe

to compile the test files(coverage report)
g++ -std=c++17 --coverage \
TestBookingManager.cpp BookingManager.cpp Booking.cpp Customer.cpp HolidayPackage.cpp BeachHoliday.cpp CityBreak.cpp \
-lgtest -lgtest_main -pthread \
-o tests.exe

to run it 
./tests.exe
gcovr --root . --html-details coverage.html

to run cyclomatic complexity calculations 
lizard *.cpp *.h

to remove exe google files and coverage files run
rm -f rm -f *.gcda *.gcno *.gcov *.html *.js *.css tests.exe main.exe
