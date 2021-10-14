//*******************************************LORA***************************************************//

void initLora() {
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DI0);
  LoRa.setSyncWord(0xA8);
//  LoRa.setTxPower(1);  //1-17

  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("LoRa init succeeded.");
}

void sendData() {
  sendMessage(String(sensorRoundSet));
  Serial.print("Sending Sensor Round Set : "); Serial.print(sensorRoundSet);  Serial.println(" minute");
}

void sendMessage(String outgoing) {
  LoRa.beginPacket();                   // start packet
  LoRa.write(destination);              // add destination address
  LoRa.write(localAddress);             // add sender address
  LoRa.write(msgCount);                 // add message ID
  LoRa.write(outgoing.length());        // add payload length
  LoRa.print(outgoing);                 // add payload
  LoRa.endPacket();                     // finish packet and send it
  msgCount++;                           // increment message ID
}

void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return
  else
  {
    Serial.println("Packet Size: " + String(packetSize));
  }
  // read packet header bytes:
  int recipient = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length

  String incoming = "";

  while (LoRa.available()) {
    incoming += (char)LoRa.read();
  }

  if (incomingLength != incoming.length()) {   // check length for error
    Serial.println("error: message length does not match length");
    return;                             // skip rest of function
  }

  // if the recipient isn't this device or broadcast,
  if (recipient != localAddress && recipient != 0xA9) {
    Serial.println("This message is not form your device, skip rest of function.");
    return;                             // skip rest of function
  }

  Serial.println(); Serial.println("************Recieve Data Frome Sensor************");

  sendData();

  Serial.println("Received from: 0x" + String(sender, HEX));
  Serial.println("Sent to: 0x" + String(recipient, HEX));
  Serial.println("Message ID: " + String(incomingMsgId));
  Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("Snr: " + String(LoRa.packetSnr()));

  temperatureData = getValue(incoming, ';', 1).toFloat();
  moistureData = getValue(incoming, ';', 2).toInt();
  fertilityData = getValue(incoming, ';', 3).toInt();
  lightData = getValue(incoming, ';', 4).toInt();
  batteryData = getValue(incoming, ';', 5).toFloat();

  Serial.print("temperature : "); Serial.print(temperatureData); Serial.println("°C ");
  Serial.print("fertility : "); Serial.print(fertilityData); Serial.println(" us/cm ");
  Serial.print("moisture : "); Serial.print(moistureData); Serial.println("%H ");
  Serial.print("light : "); Serial.print(lightData); Serial.println(" lux ");
  Serial.print("battery : "); Serial.print(batteryData); Serial.println(" Volt ");
  Serial.println("recieve data from sensor success");

  resetSensor();
  if (modeSelect != 1) forceStopAllValve();

  getTime();
  timeStamp = displayHour + ":" + displayMinute;
  Blynk.virtualWrite(Widget_SensorLabel, displayHour + ":" + displayMinute);
  syncAllBlynk();
  autoMillis = currentMillis;
  sensorRoundMillis = currentMillis;
  firstDisplay = 0;
  sensorStatus = 1;
  updateBlynk();

#ifdef WEATHER
  updateWeather();
#else
  #ifdef ILI9341
    clearScreenData();
    displayDataSensor();
  #endif
#endif

#ifdef LINENOTIFY
  lineNotifySensor();
#endif

#ifdef FIREBASE
  sendFirebase();
#endif


}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//  end code  //
