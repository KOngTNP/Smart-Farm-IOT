//******************************************TFT*********************************************//

#ifdef ILI9341
int ringMeter(int value, int vmin, int vmax, int x, int y, int r, char *units, byte scheme)
{
  // Minimum value of r is about 52 before value text intrudes on ring
  // drawing the text first is an option

  x += r; y += r;   // Calculate coords of centre of ring
  int w = r / 3;    // Width of outer ring is 1/4 of radius
  int angle = 150;  // Half the sweep angle of meter (300 degrees)
  int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v
  byte seg = 3; // Segments are 3 degrees wide = 100 segments for 300 degrees
  byte inc = 1; // Draw segments every 3 degrees, increase to 6 for segmented ring
  // Variable to save "value" text colour from scheme and set default
  int colour = BLUE;

  // Draw colour blocks every inc degrees
  for (int i = -angle + inc / 2; i < angle - inc / 2; i += inc) {
    // Calculate pair of coordinates for segment start
    float sx = cos((i - 90) * 0.0174532925);
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    // Calculate pair of coordinates for segment end
    float sx2 = cos((i + seg - 90) * 0.0174532925);
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v) { // Fill in coloured segments with 2 triangles
      switch (scheme) {
        case 0: colour = RED; break; // Fixed colour
        case 1: colour = GREEN; break; // Fixed colour
        case 2: colour = BLUE; break; // Fixed colour
        case 3: colour = rainbow(map(i, -angle, angle, 0, 127)); break; // Full spectrum blue to red
        case 4: colour = rainbow(map(i, -angle, angle, 70, 127)); break; // Green to red (high temperature etc)
        case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // Red to green (low battery etc)
        default: colour = RED; break; // Fixed colour
      }
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
    }
    else // Fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, GREY);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, GREY);
    }
  }
  // Convert value to a string
  char buf[10];
  byte len = 2; if (value > 999) len = 4;
  dtostrf(value, len, 0, buf);
  // Add blanking space and terminator
  buf[len] = ' '; buf[len] = 0;
  // Set the text colour to default
  tft.setTextSize(1);

  if (value > 9) {
    tft.setTextColor(colour, BLACK);
    tft.setCursor(x - 25, y - 15); tft.setTextSize(5);
    tft.print(buf);
  }
  if (value < 10) {
    tft.setTextColor(colour, BLACK);
    tft.setCursor(x - 25, y - 15); tft.setTextSize(5);
    tft.print(buf);
  }

  // Calculate and return right hand side x coordinate
  return x + r;
}

unsigned int rainbow(byte value) {
  byte red = 0; // Red is the top 5 bits of a 16 bit colour value
  byte green = 0;// Green is the middle 6 bits
  byte blue = 0; // Blue is the bottom 5 bits
  byte quadrant = value / 32;

  if (quadrant == 0) {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1) {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2) {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3) {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}

float sineWave(int phase) {
  return sin(phase * 0.0174532925);
}

void drawUi() {
  tft.setCursor (2, 5);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("Wifi:");


  tft.setCursor (230, 15);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("TEMPERTURE (C)");

  tft.setCursor (230, 60);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("LIGHT (LUX)");

  tft.setCursor (230, 105);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("FERTILITY (U/C)");

  tft.setCursor (230, 155);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("MODE");

  tft.setCursor (130, 205);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("WATER   SPRAY");
}


//drawing value of mode, water, spray and rain delay
void displayButtonSet() {
  // mode
  tft.setCursor (235, 170);
  tft.setTextSize (2);
  tft.setTextColor (BLUE, BLACK);
  if (modeSelect == 1) {
    tft.print ("MANUAL");
  } else if (modeSelect == 2) {
    tft.print ("AUTO  ");
  } else {
    tft.print ("TIMER ");
  }
  
  // water
  tft.setCursor (130, 220);
  tft.setTextSize (2);
  if (waterValveStatus == 1) {
    tft.setTextColor (GREEN, BLACK);
    tft.print ("ON  ");
  } else {
    tft.setTextColor (RED, BLACK);
    tft.print ("OFF ");
  }
  
  // spray
  if (sprayValveStatus == 1) {
    tft.setTextColor (GREEN, BLACK);
    tft.print ("ON ");
  } else {
    tft.setTextColor (RED, BLACK);
    tft.print ("OFF");
  }

  // rain delay
  tft.setCursor (230, 205);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("RAIN DELAY");
  
  tft.setCursor (230, 220);
  tft.setTextSize (2);
  if (rainDelayWork == 1) {
    tft.setTextColor(GREEN, BLACK);
    tft.print (" ON ");
  } else {
    tft.setTextColor(RED, BLACK);
    tft.print (" OFF ");
  }

  Serial.println("displayButtonSet");

}

//drawing moisture, working time, sync time, temperture and light
void displayDataSet() {

  // moisture
  tft.setCursor(78, 135);
  tft.setTextSize(1);
  tft.setTextColor (WHITE, BLACK);
  tft.print("SET : ");
  tft.setTextColor(BLUE, BLACK);
  String strMoistureSet = String(moistureSet);
  if (moistureSet < 10) strMoistureSet = "0" + strMoistureSet;
  tft.print(moistureSet);
  tft.setTextColor (WHITE, BLACK);
  tft.print(" %");

  // working time
  tft.setCursor(60, 145);
  tft.setTextSize(1);
  tft.setTextColor (WHITE, BLACK);
  tft.print("Working : ");
  tft.setTextColor(BLUE, BLACK);
  tft.print(autoWaterSprayDurationSet);
  tft.setTextColor (WHITE, BLACK);
  tft.print(" min");

  // sync time
  tft.setCursor(2, 215);
  tft.setTextSize(1);
  tft.setTextColor (WHITE, BLACK);
  tft.print("Sync every: ");
  tft.setTextColor(BLUE, BLACK);
  tft.print(sensorRoundSet);
  tft.setTextColor(WHITE, BLACK);
  tft.print(" min");

  // temperature
  tft.setCursor (275, 46);
  tft.setTextSize (1);
  tft.setTextColor (RED, BLACK);
  tft.print ("/ ");
  tft.print (temperatureSet);

  // light
  tft.setCursor (275, 91);
  tft.setTextSize (1);
  tft.setTextColor (YELLOW, BLACK);
  tft.print ("/ ");
  tft.print (lightSet);

  Serial.println("displayDataSet");

}

//drawing moisture, last sync, audino battary and data value of temperature, light, fertility, moisture, last sync, audino battary and weather 
void displayDataSensor() {

  if (moistureData > 0) tesmod = 1;

  if (tesmod == 0) reading = 99;
  if (tesmod == 1) reading = moistureData;

  int xpos = 0, ypos = 5, gap = 4, radius = 52;
  xpos = 320 / 2 - 160, ypos = 0, gap = 100, radius = 105;
  ringMeter(reading, 0, 100, xpos, ypos, radius, "", RED2GREEN);

  tft.setCursor (235, 30);
  tft.setTextSize (2);
  tft.setTextColor (RED, BLACK);
  tft.print (temperatureData, 2);

  tft.setCursor (235, 75);
  tft.setTextSize (2);
  tft.setTextColor (YELLOW, BLACK);
  tft.print (lightData);

  tft.setCursor (235, 120);
  tft.setTextSize (2);
  tft.setTextColor (GREEN, BLACK);
  tft.print (fertilityData);

  tft.setCursor (65, 73);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("   MOISTURE   ");

  tft.setCursor(2, 205);
  tft.setTextSize(1);
  tft.setTextColor (WHITE, BLACK);
  tft.print("Last Sync: ");
  if (sensorRoundStatus == 0) {
    tft.setTextColor(BLUE, BLACK);
  } else {
    tft.setTextColor(RED, BLACK);
  }
  tft.print(timeStamp);

  tft.setCursor(2, 225);
  tft.setTextSize(1);
  tft.setTextColor (WHITE, BLACK);
  tft.print("Audino bat: ");
  tft.setTextColor (BLUE, BLACK);
  tft.print(batteryData);
  tft.setTextColor (WHITE, BLACK);
  tft.print(" v.");

  // drawing weather description value and show city that weather is
  // where is weather at
  tft.setCursor (75, 172);
  tft.setTextSize (1);
  tft.setTextColor (WHITE, BLACK);
  tft.print ("AT ");
  tft.setTextColor(YELLOW, BLACK);
  tft.print (weatherCity);

  // weather description
  const int SCREEN_WIDTH = 270;
  int intTextLength = weatherDescription.length();
  if (intTextLength > 26) weatherDescription = weatherDescription.substring(0, 26);
  const char* text = weatherDescription.c_str();
  int textPosition = (SCREEN_WIDTH - (strlen(text) * 10)) / 2;
  tft.setCursor (63, 185);
  tft.setTextSize (1.2);
  tft.setTextColor (MAGENTA, BLACK);
  weatherDescription.toUpperCase();
  tft.print (weatherDescription);
  Serial.println("displayDataSensor");
}

// drawing time and date
void displayClock() {
  if ((currentMillis - runTime) > 500 ) {
    runTime = millis();
    dots = !dots;

    if (second() == 0) {
      getTime();
    }

    if (waterValveStatus == 1) {
      digitalWrite(waterLed, dots);
    } else {
      digitalWrite(waterLed, LOW);
    }

    if (sprayValveStatus == 1) {
      digitalWrite(sprayLed, dots);
    } else {
      digitalWrite(sprayLed, LOW);
    }

    tft.setCursor(190, 20);
    tft.setTextColor(BLUE, BLACK);
    tft.setTextSize(1);
    tft.print(displayHour);
    if (dots) {
      tft.print(":");
    } else {
      tft.print(" ");
    }
    tft.print(displayMinute);
  }
  tft.setCursor(150, 3);
  tft.setTextColor(GREEN, BLACK);
  tft.setTextSize(1);
  tft.print(Day[weekday()]);
  tft.print(" ");
  tft.print(displayDayOfMonth);
  tft.print("/");
  tft.print(displayMonth);
  tft.print("/");
  tft.print(displayYear);
}

// drawing the wifi rssi percentage
void displayWifi() {
  int wifiDisplay = WifiPercentSignal();
  tft.setCursor(2, 20);
  tft.setTextColor(YELLOW, BLACK);
  tft.setTextSize(1.5);
  tft.print(wifiDisplay);
  tft.setTextColor (WHITE, BLACK);
  tft.print("%");

}

// calculate the wifi rssi percentage
int WifiPercentSignal() {
  CurrentWifiSignal = WiFi.RSSI();
  if (CurrentWifiSignal > -40) CurrentWifiSignal = -40;
  if (CurrentWifiSignal < -90) CurrentWifiSignal = -90;
  WifiSignal = map(CurrentWifiSignal, -40, -90, 100, 1);
  return WifiSignal;
}

// check funtion DisplayButtonSet that work correctly
void checkDisplayButtonSet() {
  if ((lastMode != modeSelect) || (lastWater != waterValveStatus) ||
      (lastSpray != sprayValveStatus) || (lastRainDelay != rainDelayWork) ||
      (lastAutoWater != waterAutoTimerWork) || (lastAutoSpray != sprayAutoTimerWork)) {

    displayButtonSet();
    lastMode = modeSelect;
    lastWater = waterValveStatus;
    lastSpray = sprayValveStatus;
    lastRainDelay = rainDelayWork;
    lastAutoWater = waterAutoTimerWork;
    lastAutoSpray = sprayAutoTimerWork;
  }
}

// organize and drawing dividing linesorganize
void drawScreenline() {
  for (int i = 0; i < 306; i++) {
    // line beside ring meterring Meter
    if (i <= 250) {
      tft.setCursor (220, i);
      tft.setTextSize (2);
      tft.setTextColor (GREY, GREY);
      tft.print ("|");
      }
    //line before WATER
    if (i >= 200) {
      tft.setCursor (114, i);
      tft.setTextSize (2);
      tft.setTextColor (GREY, GREY);
      tft.print ("|");
      }
      
    //line under TEMPPERTURE
    if (i >= 224) {
      tft.setCursor (i, 43);
      tft.setTextSize (2);
      tft.setTextColor (GREY, GREY);
      tft.print ("_");
    
      //line under LIGHT
      tft.setCursor (i, 88);
      tft.setTextSize (2);
      tft.setTextColor (GREY, GREY);
      tft.print ("_");

      //line under FERTILITY
      tft.setCursor (i, 130);
      tft.setTextSize (2);
      tft.setTextColor (GREY, GREY);
      tft.print ("_");
    }

    //line under location
    tft.setCursor (i, 186);
    tft.setTextSize (2);
    tft.setTextColor (GREY, GREY);
    tft.print ("_");    
  }
}

// to clear unconnect data on screen
void clearScreenData() {
  tft.setCursor (235, 30);
  tft.setTextSize (2);
  tft.setTextColor (RED, BLACK);
  tft.print ("     ");

  tft.setCursor (235, 75);
  tft.setTextSize (2);
  tft.setTextColor (YELLOW, BLACK);
  tft.print ("     ");

  tft.setCursor (235, 120);
  tft.setTextSize (2);
  tft.setTextColor (GREEN, BLACK);
  tft.print ("     ");
}

#endif

//  end code  //
