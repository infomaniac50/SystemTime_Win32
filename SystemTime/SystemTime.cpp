// SystemTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  SYSTEMTIME* current_time;
  SYSTEMTIME* local_time;
  TIME_ZONE_INFORMATION* timezone;

  current_time = static_cast<SYSTEMTIME*>(malloc(sizeof(SYSTEMTIME)));
  local_time = static_cast<SYSTEMTIME*>(malloc(sizeof(SYSTEMTIME)));

  timezone = static_cast<TIME_ZONE_INFORMATION*>(malloc(sizeof(TIME_ZONE_INFORMATION)));


  GetSystemTime(current_time);
  GetLocalTime(local_time);
  GetTimeZoneInformation(timezone);

  cout << "Current UTC Time: ";
  cout << current_time->wHour;
  cout << ":";
  cout << current_time->wMinute;
  cout << ":";
  cout << current_time->wSecond << endl;

  cout << "Current UTC Date: ";
  cout << current_time->wMonth;
  cout << "-";
  cout << current_time->wDay;
  cout << "-";
  cout << current_time->wYear << endl;

  cout << endl;

  cout << "Current Local Time: ";
  cout << local_time->wHour;
  cout << ":";
  cout << local_time->wMinute;
  cout << ":";
  cout << local_time->wSecond << endl;

  cout << "Current Local Date: ";
  cout << local_time->wMonth;
  cout << "-";
  cout << local_time->wDay;
  cout << "-";
  cout << local_time->wYear << endl;

  cout << endl;

  cout << "Standard Time: ";
  wprintf_s(timezone->StandardName);
  cout << endl;

  cout << "Daylight Time: ";
  wprintf_s(timezone->DaylightName);
  cout << endl;

  SYSTEMTIME zonedate;

  zonedate = timezone->StandardDate;

  cout << "Standard Date: ";
  cout << zonedate.wMonth << "-" << zonedate.wDay << endl;

  zonedate = timezone->DaylightDate;

  cout << "Daylight Date: ";
  cout << zonedate.wMonth << "-" << zonedate.wDay << endl;
  
  free(current_time);
  free(local_time);
  free(timezone);

	return 0;
}

