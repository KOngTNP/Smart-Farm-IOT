//**************************************TIMER MODE*****************************************//

void timerCheck() {
  if (modeSelect == 3) {
    if ((timer1On && timer1WaterStatus) || (timer2On && timer2WaterStatus) || (timer3On && timer3WaterStatus) || (timer4On && timer4WaterStatus) || (timer5On && timer5WaterStatus) || (timer6On && timer6WaterStatus) || (timer7On && timer7WaterStatus) || (timer8On && timer8WaterStatus)) {
      waterValveStatus = 1;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyOpenWaterValve();
      
#endif
    }
    if ((timer1On && timer1SprayStatus) || (timer2On && timer2SprayStatus) || (timer3On && timer3SprayStatus) || (timer4On && timer4SprayStatus) || (timer5On && timer5SprayStatus) || (timer6On && timer6SprayStatus) || (timer7On && timer7SprayStatus) || (timer8On && timer8SprayStatus)) {
      sprayValveStatus = 1;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyOpenSprayValve();
      
#endif
    }
    if ((timer1WaterStatus == 0) && (timer2WaterStatus == 0) && (timer3WaterStatus == 0) && (timer4WaterStatus == 0) && (timer5WaterStatus == 0) && (timer6WaterStatus == 0) && (timer7WaterStatus == 0) && (timer8WaterStatus == 0)) {
      waterValveStatus = 0;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyCloseWaterValve();
      
#endif
    }
    if ((timer1SprayStatus == 0) && (timer2SprayStatus == 0) && (timer3SprayStatus == 0) && (timer4SprayStatus == 0) && (timer5SprayStatus == 0) && (timer6SprayStatus == 0) && (timer7SprayStatus == 0) && (timer8SprayStatus == 0))  {
      sprayValveStatus = 0;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyCloseSprayValve();
#endif

    }
  }
}


void timer1OpenAll() {
  timer1WaterStatus = 1;
  timer1SprayStatus = 1;
}

void timer1CloseAll() {
  timer1WaterStatus = 0;
  timer1SprayStatus = 0;
}

void timer2OpenAll() {
  timer2WaterStatus = 1;
  timer2SprayStatus = 1;
}

void timer2CloseAll() {
  timer2WaterStatus = 0;
  timer2SprayStatus = 0;
}

void timer3OpenAll() {
  timer3WaterStatus = 1;
  timer3SprayStatus = 1;
}

void timer3CloseAll() {
  timer3WaterStatus = 0;
  timer3SprayStatus = 0;
}

void timer4OpenAll() {
  timer4WaterStatus = 1;
  timer4SprayStatus = 1;
}

void timer4CloseAll() {
  timer4WaterStatus = 0;
  timer4SprayStatus = 0;
}

void timer5OpenAll() {
  timer5WaterStatus = 1;
  timer5SprayStatus = 1;
}

void timer5CloseAll() {
  timer5WaterStatus = 0;
  timer5SprayStatus = 0;
}

void timer6OpenAll() {
  timer6WaterStatus = 1;
  timer6SprayStatus = 1;
}

void timer6CloseAll() {
  timer6WaterStatus = 0;
  timer6SprayStatus = 0;
}

void timer7OpenAll() {
  timer7WaterStatus = 1;
  timer7SprayStatus = 1;
}

void timer7CloseAll() {
  timer7WaterStatus = 0;
  timer7SprayStatus = 0;
}

void timer8OpenAll() {
  timer8WaterStatus = 1;
  timer8SprayStatus = 1;
}

void timer8CloseAll() {
  timer8WaterStatus = 0;
  timer8SprayStatus = 0;
}

//timer 1 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_1) {
  if (param.asInt() == 1) {
    timer1Work++;
    if (timer1Work >= 4) {
      timer1Work = 0;
      timer1CloseAll();
    }
    activeToday();
    timer1Label();
  }
}

//timer 2 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_2) {
  if (param.asInt() == 1) {
    timer2Work++;
    if (timer2Work >= 4) {
      timer2Work = 0;
      timer2CloseAll();
    }
    activeToday();
    timer2Label();
  }
}

//timer 3 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_3) {
  if (param.asInt() == 1) {
    timer3Work++;
    if (timer3Work >= 4) {
      timer3Work = 0;
      timer3CloseAll();
    }
    activeToday();
    timer3Label();
  }
}

//timer 4 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_4) {
  if (param.asInt() == 1) {
    timer4Work++;
    if (timer4Work >= 4) {
      timer4Work = 0;
      timer4CloseAll();
    }
    activeToday();
    timer4Label();
  }
}

//timer 5 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_5) {
  if (param.asInt() == 1) {
    timer5Work++;
    if (timer5Work >= 4) {
      timer5Work = 0;
      timer5CloseAll();
    }
    activeToday();
    timer5Label();
  }
}

//timer 6 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_6) {
  if (param.asInt() == 1) {
    timer6Work++;
    if (timer6Work >= 4) {
      timer6Work = 0;
      timer6CloseAll();
    }
    activeToday();
    timer6Label();
  }
}

//timer 7 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_7) {
  if (param.asInt() == 1) {
    timer7Work++;
    if (timer7Work >= 4) {
      timer7Work = 0;
      timer7CloseAll();
    }
    activeToday();
    timer7Label();
  }
}

//timer 8 button  0=off 1= w+s 2=w 3=s
BLYNK_WRITE(Widget_TimerButton_8) {
  if (param.asInt() == 1) {
    timer8Work++;
    if (timer8Work >= 4) {
      timer8Work = 0;
      timer8CloseAll();
    }
    activeToday();
    timer8Label();
  }
}


//*************************************TIMER MODULE*****************************************//

BLYNK_WRITE(Widget_TimerInput_1) {  //  timer 1

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 1 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 1 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer1On = 1;
          timerNumber = 1;
          //timer1 on
          if (timer1Work == 1) {
            timer1OpenAll();
          } else if (timer1Work == 2) {
            timer1WaterStatus = 1;
            timer1SprayStatus = 0;
          } else if (timer1Work == 3) {
            timer1SprayStatus = 1;
            timer1WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer1CloseAll();
        timer1On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer1CloseAll();
          timer1On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer1On = 1;
          timerNumber = 1;
          //timer1 on
          if (timer1Work == 1) {
            timer1OpenAll();
          } else if (timer1Work == 2) {
            timer1WaterStatus = 1;
            timer1SprayStatus = 0;
          } else if (timer1Work == 3) {
            timer1SprayStatus = 1;
            timer1WaterStatus = 0;
          }
        }
      }
    }
  }
}


BLYNK_WRITE(Widget_TimerInput_2) {  //  timer 2

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 2 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 2 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer2On = 1;
          timerNumber = 2;
          //timer2 on
          if (timer2Work == 1) {
            timer2OpenAll();
          } else if (timer2Work == 2) {
            timer2WaterStatus = 1;
            timer2SprayStatus = 0;
          } else if (timer2Work == 3) {
            timer2SprayStatus = 1;
            timer2WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer2CloseAll();
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer2CloseAll();
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer2On = 1;
          timerNumber = 2;
          //timer2 on
          if (timer2Work == 1) {
            timer2OpenAll();
          } else if (timer2Work == 2) {
            timer2WaterStatus = 1;
            timer2SprayStatus = 0;
          } else if (timer2Work == 3) {
            timer2SprayStatus = 1;
            timer2WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
    }
  }
}


BLYNK_WRITE(Widget_TimerInput_3) {  //  timer 3

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 3 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 3 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer3On = 1;
          timerNumber = 3;
          //timer3 on
          if (timer3Work == 1) {
            timer3OpenAll();
          } else if (timer3Work == 2) {
            timer3WaterStatus = 1;
            timer3SprayStatus = 0;
          } else if (timer3Work == 3) {
            timer3SprayStatus = 1;
            timer3WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer3CloseAll();
        timer3On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer3CloseAll();
          timer3On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer3On = 1;
          timerNumber = 3;
          //timer3 on
          if (timer3Work == 1) {
            timer3OpenAll();
          } else if (timer3Work == 2) {
            timer3WaterStatus = 1;
            timer3SprayStatus = 0;
          } else if (timer3Work == 3) {
            timer3SprayStatus = 1;
            timer3WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
    }
  }
}

BLYNK_WRITE(Widget_TimerInput_4) {  //  timer 4

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 4 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 4 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer4On = 1;
          timerNumber = 4;
          //timer4 on
          if (timer4Work == 1) {
            timer4OpenAll();
          } else if (timer4Work == 2) {
            timer4WaterStatus = 1;
            timer4SprayStatus = 0;
          } else if (timer4Work == 3) {
            timer4SprayStatus = 1;
            timer4WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer4CloseAll();
        timer4On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer4CloseAll();
          timer4On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer4On = 1;
          timerNumber = 4;
          //timer4 on
          if (timer4Work == 1) {
            timer4OpenAll();
          } else if (timer4Work == 2) {
            timer4WaterStatus = 1;
            timer4SprayStatus = 0;
          } else if (timer4Work == 3) {
            timer4SprayStatus = 1;
            timer4WaterStatus = 0;
          }
          //Serial.println("Timer 4 is ON");
        }
      }
    }
  }
}


BLYNK_WRITE(Widget_TimerInput_5) {  //  timer 5

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 5 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 5 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;
    if (weekday() == 1) dayadjustment =  6;
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer5On = 1;
          timerNumber = 5;
          //timer5 on
          if (timer5Work == 1) {
            timer5OpenAll();
          } else if (timer5Work == 2) {
            timer5WaterStatus = 1;
            timer5SprayStatus = 0;
          } else if (timer5Work == 3) {
            timer5SprayStatus = 1;
            timer5WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer5CloseAll();
        timer5On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer5CloseAll();
          timer5On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer5On = 1;
          timerNumber = 5;
          //timer5 on
          if (timer5Work == 1) {
            timer5OpenAll();
          } else if (timer5Work == 2) {
            timer5WaterStatus = 1;
            timer5SprayStatus = 0;
          } else if (timer5Work == 3) {
            timer5SprayStatus = 1;
            timer5WaterStatus = 0;
          }
        }
      }
    }
  }



BLYNK_WRITE(Widget_TimerInput_6) {  //  timer 6

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 6 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 6 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;
    if (weekday() == 1) dayadjustment =  6;
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer6On = 1;
          timerNumber = 6;
          //timer6 on
          if (timer6Work == 1) {
            timer6OpenAll();
          } else if (timer6Work == 2) {
            timer6WaterStatus = 1;
            timer6SprayStatus = 0;
          } else if (timer6Work == 3) {
            timer6SprayStatus = 1;
            timer6WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer6CloseAll();
        timer6On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer6CloseAll();
          timer6On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer6On = 1;
          timerNumber = 6;
          //timer6 on
          if (timer6Work == 1) {
            timer6OpenAll();
          } else if (timer6Work == 2) {
            timer6WaterStatus = 1;
            timer6SprayStatus = 0;
          } else if (timer6Work == 3) {
            timer6SprayStatus = 1;
            timer6WaterStatus = 0;
          }
        }
      }
    }
  }


BLYNK_WRITE(Widget_TimerInput_7) {  //  timer 7

  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 7 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 7 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer7On = 1;
          timerNumber = 7;
          //timer7 on
          if (timer7Work == 1) {
            timer7OpenAll();
          } else if (timer7Work == 2) {
            timer7WaterStatus = 1;
            timer7SprayStatus = 0;
          } else if (timer7Work == 3) {
            timer7SprayStatus = 1;
            timer7WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer7CloseAll();
        timer7On = 0;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer7CloseAll();
          timer7On = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer7On = 1;
          timerNumber = 7;
          //timer7 on
          if (timer7Work == 1) {
            timer7OpenAll();
          } else if (timer7Work == 2) {
            timer7WaterStatus = 1;
            timer7SprayStatus = 0;
          } else if (timer7Work == 3) {
            timer7SprayStatus = 1;
            timer7WaterStatus = 0;
          }
        }
      }
    }
  }
}


BLYNK_WRITE(Widget_TimerInput_8) {  //  timer 8
  
  if (modeSelect == 3) {
    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());
    TimeInputParam t(param);
    Serial.print("Timer 8 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 8 Checked schedule at: "); terminal.println(Time); terminal.flush();
    int dayadjustment = -1;
    if (weekday() == 1) dayadjustment =  6;
    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      if (nowseconds >= startsecondswd) {
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= startsecondswd + 90) {
          timer8On = 1;
          timerNumber = 8;
          //timer8 on
          if (timer8Work == 1) {
            timer8OpenAll();
          } else if (timer8Work == 2) {
            timer8WaterStatus = 1;
            timer8SprayStatus = 0;
          } else if (timer8Work == 3) {
            timer8SprayStatus = 1;
            timer8WaterStatus = 0;
          }
          // code here to switch the relay ON
        }
      }
      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      if (nowseconds >= stopsecondswd) {
        timer8CloseAll();
        timer8On = 0;
        timerNumber = 8;
        // 90s on 60s timer ensures 1 trigger command is sent
        if (nowseconds <= stopsecondswd + 90) {
          timer8CloseAll();
          timer8On = 0;
          timerNumber = 8;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          timer8On = 1;
          timerNumber = 8;
          //timer8 on
          if (timer8Work == 1) {
            timer8OpenAll();
          } else if (timer8Work == 2) {
            timer8WaterStatus = 1;
            timer8SprayStatus = 0;
          } else if (timer8Work == 3) {
            timer8SprayStatus = 1;
            timer8WaterStatus = 0;
          }
        }
      }
    }
  }
}

//  end code  //
