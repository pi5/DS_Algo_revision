
/* Time functions practice */

#include<iostream>
#include<string>
using namespace std;

#include<iomanip>
using std::setw;

#include<ctime>

int main() {

    // Current time
    time_t now = time(0);
    cout << endl << "char* ctime():\t" << ctime(&now);
    
    tm* time_struct = gmtime(&now);
    cout << endl << "gmtime";
    cout << endl << setw(10) << "time_struct->tm_sec" << setw(10) << time_struct->tm_sec;
    cout << endl << setw(10) << "time_struct->tm_min" << setw(10) << time_struct->tm_min;
    cout << endl << setw(10) << "time_struct->tm_hour" << setw(10) << time_struct->tm_hour;
    cout << endl << setw(10) << "time_struct->tm_mday" << setw(10) << time_struct->tm_mday;
    cout << endl << setw(10) << "time_struct->tm_mon" << setw(10) << time_struct->tm_mon;
    cout << endl << setw(10) << "time_struct->tm_year" << setw(10) << time_struct->tm_year;
    cout << endl << setw(10) << "time_struct->tm_wday" << setw(10) << time_struct->tm_wday;
    cout << endl << setw(10) << "time_struct->tm_year" << setw(10) << time_struct->tm_year;
    cout << endl << setw(10) << "time_struct->tm_wday" << setw(10) << time_struct->tm_wday;
    cout << endl << setw(10) << "time_struct->tm_yday" << setw(10) << time_struct->tm_yday;
    cout << endl << setw(10) << "time_struct->tm_isdst" << setw(10) << time_struct->tm_isdst;
   
    cout << endl; 
    return 0;   
}

