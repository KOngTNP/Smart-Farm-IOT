//*********************************************AUTO MODE********************************************************//

// waterAutoTimerStatus and sprayAutoTimerStatus it form auto_timer function below
// therefore if you want to open the auto funtion you shoude open the auto_timer function and set the time that you want to do the auto mode
// this function do every time that sensor sent the data to master and each working time according to the time that setting


//                                                                    vv                                           vv
//                     WATER      ----->      sensorStatus  >>>>  rainStatus  >>>>  waterAutoTimerStatus  >>>>  moisture
// if sensor sent data and rainStatus off or not have rain
//    then do the funtion when turn on the water_auto_timer and moisture > moisture_set
void autoCheck() {
  if ((sensorStatus == 1) && (rainStatus == 0)) {
    if ((currentMillis - autoMillis) <= (autoWaterSprayDurationSet * ONE_MINUTE)) {
      //auto water check
      if ((waterAutoTimerStatus  == 1) && (moistureData <= moistureSet)) {
        lineSender = "Auto Sensor";
        lineDataSet = " Moisture Set : ";
        lineDataSet += moistureSet;
        lineDataSet += " %H";

#ifdef LINENOTIFY
        lineNotifyOpenWaterValve();
#endif
        waterValveStatus = 1;
      }
      //auto spray check
      
      //                                                vv                 vv
      //                     SPRAY      ----->      temperature  >>>>  lightData  >>>>  sprayAutoTimerStatus
      // if spray_auto_time are turn on , temperature and light >= setting then do this funtion 
      if ((sprayAutoTimerStatus  == 1) && (temperatureData >= temperatureSet) || (lightData >= lightSet)) {

        lineSender = "Auto Sensor";
        lineDataSet += " Temperature Set : ";
        lineDataSet += temperatureSet;
        lineDataSet += " C * Light Set : ";
        lineDataSet += lightSet;
        lineDataSet += " lux";

#ifdef LINENOTIFY
        lineNotifyOpenSprayValve();
#endif
        sprayValveStatus = 1;
      }
    } else {
      lineSender = "Auto Sensor";
      closeAllValve();
    }
  } else {
    closeAllValve();
  }
}

//**************************************AUTO TIMER INPUT********************************************************//


BLYNK_WRITE(Widget_WaterAutoTimerInput) {  //  auto water by timer V21

  if ((modeSelect == 2) && (waterAutoTimerWork == 1)) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Auto Water Timer Checked schedule at: "); Serial.println(Time);
    terminal.print("Auto Water Timer Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          waterAutoTimerStatus = 1;
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        waterAutoTimerStatus = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          waterAutoTimerStatus = 0;
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          waterAutoTimerStatus = 1;
        }
      }
    }
  }


BLYNK_WRITE(Widget_SprayAutoTimerInput) {  //  auto water timer V23
  if ((modeSelect == 2) && (sprayAutoTimerWork == 1)) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Auto Spray Timer Checked schedule at: "); Serial.println(Time);
    terminal.print("Auto Spray Timer Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;
    if (weekday() == 1) dayadjustment =  6;
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          sprayAutoTimerStatus = 1;
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        sprayAutoTimerStatus = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          sprayAutoTimerStatus = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          sprayAutoTimerStatus = 1;
        }
      }
    }
  }

//  end code  //
