#include <DHT.h>

int dhtPin = 8;
float humidity, temperature, heatIndex;

#define DHTTYPE DHT11

DHT dht(dhtPin, DHTTYPE);

void setup(){
    Serial.begin(9600);
    Serial.println("Starting DHT11");
    dht.begin();
}

void loop(){
    delay(1000);

    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)){
        Serial.println("Failed to read from DHT");
        return;
    }
    Serial.print("\nHumidity: ");
    Serial.print(humidity);
    Serial.print("%\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C");
}
