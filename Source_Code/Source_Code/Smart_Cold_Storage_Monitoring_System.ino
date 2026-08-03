
#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define BUZZER 19

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid="Wokwi-GUEST";
const char* password="";

unsigned long channelID=3443110;
const char* writeAPIKey="LELDJDOKG87WT7N6";

WiFiClient client;

float temperature=0, humidity=0;
String status;

void startupScreen(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(12,12);
  display.println("SMART COLD");
  display.setCursor(2,26);
  display.println("STORAGE MONITOR");
  display.setCursor(28,48);
  display.println("Loading...");
  display.display();
  delay(2000);
}

void connectWiFi(){
  WiFi.begin(ssid,password);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Connecting WiFi");
  display.display();

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  ThingSpeak.begin(client);
}

void readSensors(){
  temperature=dht.readTemperature();
  humidity=dht.readHumidity();

  if(isnan(temperature)||isnan(humidity)){
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(20,20);
    display.println("ERROR");
    display.display();
    Serial.println("Sensor Error");
    noTone(BUZZER);
    while(true);
  }
}

void determineStatus(){
  if(temperature<2) status="TOO COLD";
  else if(temperature<=8) status="SAFE";
  else status="TOO HOT";
}

void updateBuzzer(){
  if(status=="SAFE"){
    noTone(BUZZER);
    return;
  }
  tone(BUZZER,1000);
  delay(150);
  noTone(BUZZER);
  delay(150);
  tone(BUZZER,1000);
  delay(150);
  noTone(BUZZER);
}

void updateDisplay() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Title
  display.setCursor(10, 0);
  display.println("COLD STORAGE");

  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  // Temperature
  display.setCursor(0, 18);
  display.print("Temp : ");
  display.print(temperature, 1);
  display.println(" C");

  // Humidity
  display.setCursor(0, 30);
  display.print("Hum  : ");
  display.print(humidity, 1);
  display.println(" %");

  // Status
  display.setCursor(0, 42);
  display.print("Status: ");
  display.println(status);

  // WiFi Status
  display.setCursor(0, 54);
  display.print("WiFi : ");

  if (WiFi.status() == WL_CONNECTED) {
    display.print("Connected");
  } else {
    display.print("Disconnected");
  }

  display.display();
}
void printSerial(){
  Serial.println("----------------------------");
  Serial.print("Temperature : ");
  Serial.println(temperature);
  Serial.print("Humidity    : ");
  Serial.println(humidity);
  Serial.print("Status      : ");
  Serial.println(status);
}

void uploadThingSpeak(){
  ThingSpeak.setField(1,temperature);
  ThingSpeak.setField(2,humidity);

  int st=0;
  if(status=="SAFE") st=1;
  else if(status=="TOO COLD") st=0;
  else st=2;
  ThingSpeak.setField(3,st);

  int x=ThingSpeak.writeFields(channelID,writeAPIKey);
  if(x==200) Serial.println("ThingSpeak Upload OK");
  else{
    Serial.print("ThingSpeak Error: ");
    Serial.println(x);
  }
}

void setup(){
  Serial.begin(115200);
  dht.begin();

  pinMode(BUZZER,OUTPUT);
  noTone(BUZZER);

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    while(true);
  }

  startupScreen();
  connectWiFi();
}

void loop(){
  readSensors();
  determineStatus();
  updateDisplay();
  updateBuzzer();
  printSerial();
  uploadThingSpeak();
  delay(20000);
}


