//******************************************DEFINE FUNTION*******************************************//

#define BLYNKLOCAL  //define if use blynk local server (option)
#define LINENOTIFY  //define if use linenotify (option)
#define WEATHER  //define if use weather and rain delay (option)
#define ILI9341  //define if use tftlcd (option)
#define PHYBUTTON  //define if use physical button (option)
#define FIREBASE  //define if use firebase (option)

//**************************************************************************************************//

const char* ssid = "KOng-wifi"; // <<<  input wifi name
const char* pass = "55554321";  // <<< input wifi password

#ifdef  BLYNKLOCAL
#define serverBlynk "blynk.iot-cm.com" // <<< input blynk server name
#define portBlynk 8080
const char* auth = "YCc1UGEgkHjFRLIYQ65mLLG3CwXS8a8X";  // <<< input blynk local key

// if you want to use official blynk
#else
const char* auth = "gk285LJOLrfff5984by5MSY25gt9eYBH";  // <<< input blynk official
#endif

//lora setting
byte localAddress = 0xA8;     // lora address of this device
byte destination = 0xA9;      // lora destination to send to

//line notify setting
#ifdef LINENOTIFY                                               
#define LINE_TOKEN  "M7XPWWnMZi5JbWB5zBFYcMZIYj6udtCPLQqBlHmbQrr"  // <<< input line token
#endif

// weather setting form openweathermap
#ifdef WEATHER
const String weatherHost = "http://api.openweathermap.org/data/2.5/weather?id=";
const char* weatherKey = "b6ca45ff002e68ab7ab98b3c31f18ec6";  // <<< input weather key
//const char* cityID = "1611110";  // <<< input city id, In this case is id of Chon Buri, Thailand
#endif

// friebase setting
#ifdef FIREBASE
const char* firebaseHost = "smart-farm-5d39d-default-rtdb.asia-southeast1.firebasedatabase.app"; // input friebase server
const char* firebaseAuth = "BxLmeucqHzAFKmhO7H6Ne4e9CD9SDWUnC2bztefF"; // <<< input friebase key
#endif

//  end code //
