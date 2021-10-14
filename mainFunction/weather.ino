//******************************************WEATHER*************************** *************//



// city ID 77 Province
char* citys[78] = {"","1621060","1621035","1609350","1611475","1611453","1611439","1611416","1611407","1611269","1153671","1153669","1611110","1153557","1610469","1153090",
"1153081","1609776","1152633","1152473","1152468","1609071","1609032","1152222","1608900","1608597","1608539","1608534","1608531","1608529","1608527",
"1151933","1608452","1608409","1608269","1608232","1608133","1607983","1607978","1151464","1607779","1151426","1607737","1149698","1607725","1607708",
"1607532","1607552","1151254","1607280","1151074","1150965","1150954","1607017","1607001","1606807","1606790","1606590","1606588","1606586","1606418",
"1606376","1606270","1606239","1606147","1150533","1606033","1150515","1606030","1150490","1150007","1605279","1605245","1605239","1605221","1605215","1604870","1604769"};
char* oldcityID;
BLYNK_WRITE(Weather_Location) {   // Menu Widget on V0 to select city
  int index = param.asInt();
  switch (index)
  {
    case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:
    case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:case 24:case 25:case 26:case 27:case 28:case 29:case 30:
    case 31:case 32:case 33:case 34:case 35:case 36:case 37:case 38:case 39:case 40:case 41:case 42:case 43:case 44:case 45:
    case 46:case 47:case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 58:case 59:case 60:
    case 61:case 62:case 63:case 64:case 65:case 66:case 67:case 68:case 69:case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:
               cityID = citys[index];
               break;
    default:

               break;
  }
  
  if (oldcityID != cityID){
    updateWeather();
    oldcityID = cityID;
    }
}

#ifdef WEATHER
void updateWeather() {
  HTTPClient http;
  const size_t capacity = JSON_ARRAY_SIZE(3) + 2 * JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 3 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(12) + 340;
  DynamicJsonDocument doc(capacity);

  http.begin(weatherHost + cityID + "&units=metric&appid=" + weatherKey);
  int httpCode = http.GET();

  String payload;
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      delay(120000);
      return;
    }

    JsonObject weather_0 = doc["weather"][0];
    const char* weather_0_main = weather_0["main"];
    const char* weather_0_description = weather_0["description"];
    JsonObject main = doc["main"];
    const char* name = doc["name"];

    weatherMain = String(weather_0_main);
    weatherDescription = String(weather_0_description);
    weatherCity = String(name);

    Serial.print("Weather Main : "); Serial.println(weatherMain);
    Serial.print("Weather Description : "); Serial.println(weatherDescription);
    Serial.print("Weather City : "); Serial.println(weatherCity);

    if ((rainDelayWork == 1) && ((weatherMain == "Rain") || (weatherDescription == "thunderstorm with light rain") ||
                                 (weatherDescription == "thunderstorm with rain") || (weatherDescription == "thunderstorm with heavy rain") ||
                                 (weatherDescription == "light intensity drizzle rain") || (weatherDescription == "drizzle rain") ||
                                 (weatherDescription == "heavy intensity drizzle rain") || (weatherDescription == "shower rain and drizzle") ||
                                 (weatherDescription == "heavy shower rain and drizzle"))) {
      rainStatus = 1;
    } else {
      rainStatus = 0;
    }

    Serial.print("Rain Status : "); Serial.println(rainStatus);
    
    #ifdef ILI9341
      clearScreenData();
      displayDataSensor();
    #endif
  
  } else {
    Serial.println("Error on HTTP request");
  }
  http.end();
}

#endif

//  end code  //
