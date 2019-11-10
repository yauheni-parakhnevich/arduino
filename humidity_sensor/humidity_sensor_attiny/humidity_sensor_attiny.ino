#include <TM1637Display.h>
#include <DHT.h>

#define DHT_PIN 0
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

float hum;  //Stores humidity value
float temp; //Stores temperature value

#define CLK 1
#define DIO 2

TM1637Display display(CLK, DIO);

void setup() {
   delay(500);//Delay to let system boot
   delay(1000);//Wait before accessing Sensor

   display.setBrightness(5);
   dht.begin();
}

void loop() {
      display.clear();
      hum = dht.readHumidity();
      temp = dht.readTemperature();

      int val = int(temp) * 100 + int(hum);
    
      display.showNumberDecEx(val, 0b01000000);

      delay(5000);

}
