//******************************************DEFINE FUNTION*******************************************//

#define BLYNKLOCAL  //define if use blynk local server (option)
#define LINENOTIFY  //define if use linenotify (option)
#define WEATHER  //define if use weather and rain delay (option)
#define ILI9341  //define if use tftlcd (option)
#define PHYBUTTON  //define if use physical button (option)
#define FIREBASE  //define if use firebase (option)

//**************************************************************************************************//

const char* ssid = ""; // <<<  input wifi name
const char* pass = "";  // <<< input wifi password

#ifdef  BLYNKLOCAL
#define serverBlynk "blynk.iot-cm.com" // <<< input blynk server name
#define portBlynk 8080
const char* auth = "";  // <<< input blynk local key

// if you want to use official blynk
#else
const char* auth = "";  // <<< input blynk official
#endif

//lora setting
byte localAddress = 0xA8;     // lora address of this device
byte destination = 0xA9;      // lora destination to send to

//line notify setting
#ifdef LINENOTIFY                                               
#define LINE_TOKEN  ""  // <<< input line token
#endif

// weather setting form openweathermap
#ifdef WEATHER
const String weatherHost = "http://api.openweathermap.org/data/2.5/weather?id=";
const char* weatherKey = "";  // <<< input weather key
//const char* cityID = "";  // <<< input city id, In this case is id of Chon Buri, Thailand
#endif

// friebase setting
#ifdef FIREBASE
const char* firebaseHost = ""; // input friebase server
const char* firebaseAuth = ""; // <<< input friebase key
#endif

//  end code //
