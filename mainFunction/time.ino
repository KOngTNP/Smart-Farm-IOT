//******************************************Getting time**********************************//

// setting year, month, day and time data for funtion date,time
void getTime() {

  displayYear =   String(year(), DEC);
  displayYear =   displayYear.substring(2, 4);

  int gmMonth = month();
  displayMonth =   String(gmMonth, DEC);
  int monthdigits = displayMonth.length();
  // if month = 01 it will show only "1" this code add '0' before 1 = 01
  if (monthdigits == 1) displayMonth = "0" + displayMonth;

  int gmDayOfMonth = day();
  displayDayOfMonth =   String(gmDayOfMonth, DEC);
  int daydigits = displayDayOfMonth.length();
  if (daydigits == 1) displayDayOfMonth = "0" + displayDayOfMonth;

  int gmthour = hour();
  if (gmthour == 24) gmthour = 0;
  displayHour =   String(gmthour, DEC);
  int hourdigits = displayHour.length();
  if (hourdigits == 1) displayHour = "0" + displayHour;

  displayMinute = String(minute(), DEC);
  int minutedigits = displayMinute.length();
  if (minutedigits == 1) displayMinute = "0" + displayMinute;
}

//  end code  //
