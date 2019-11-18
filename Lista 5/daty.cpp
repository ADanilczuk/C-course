#include <ctime>
#include <iostream>
using namespace std;

const char* MONTHS[] =
  {
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
  };

int main()
  {
  time_t     rawtime;
  struct tm* timeinfo;

  time( &rawtime );
  timeinfo = localtime( &rawtime );

  cout << "Today's date is "
       << timeinfo->tm_mday << " "
       << MONTHS[ timeinfo->tm_mon ] << " "
       << (timeinfo->tm_year) << ".\n";

  return 0;
  }
