//******************************************INTERNET CONNECT****************************************//

void connectInternet() {
  Serial.println("Start Connect Internet");

  Serial.println("Creating portal and trying to connect... by config");
  // Establish a connection with an autoReconnect option.
  if (Portal.begin()) {
    Serial.println("WiFi connected: " + WiFi.localIP().toString());
    Serial.println(WiFi.getHostname());
  }
}

//  end code  //
