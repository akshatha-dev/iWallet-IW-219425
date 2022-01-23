#include<TinyGPS++.h>
#include<HardwareSerial.h>
#include<Wire.h>

float lati, longi;
TinyGPSPlus gps;
HardwareSerial SerialGPS(1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17); //1, 3
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(gps.satellites.value());
  //Serial.println(NULL);
  while(SerialGPS.available()>0)
  {
    if(gps.encode(SerialGPS.read()))
    {
      if(gps.location.isValid())
      {
        lati = gps.location.lat();
        longi = gps.location.lng();
        Serial.print("Latitude: ");
        Serial.println(lati);
        Serial.print("Longitude: ");
        Serial.println(longi);
        Serial.println("");
      }
    }
  }
}
