//*******************************************firebase***********************************************//

#ifdef FIREBASE
void sendFirebase() {
  Firebase.begin(firebaseHost, firebaseAuth);
  Firebase.pushFloat(firebaseData, "temperature", temperatureData, 2);
  Firebase.pushInt(firebaseData, "moisture", moistureData);
  Firebase.pushInt(firebaseData, "fertility", fertilityData);
  Firebase.pushInt(firebaseData, "light", lightData);
  Firebase.pushFloat(firebaseData, "battery", batteryData, 2);
  Firebase.pushString(firebaseData, "time", timeStamp);
  Serial.println("update firebase complete");
}

#endif

//  end code  //
