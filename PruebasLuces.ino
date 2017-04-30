#include <Wire.h>
#include <TimeLib.h>
#include <Time.h>

#include <RTClib.h>

RTC_DS1307 rtc;

// Hora
int hora1 = 19;
int hora2 = 24;
int hora3 =1;
int hora4=6;
#define Relay 7

//SCL 7
//SDA 5
//Relay 2
void setup() {
  pinMode(Relay, OUTPUT);
 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  //rtc.adjust(DateTime(anio, mes, dia, horas, min, seg));
  rtc.adjust(DateTime(2017, 4, 25, 18, 59, 50)); //para ajustar la hora
}

void loop() {
  DateTime now = rtc.now();
  if (now.hour() >= hora1 && now.hour()<= hora2) {
    digitalWrite(Relay, HIGH);
    delay(80);
  } if (now.hour() >= hora3 && now.hour() <= hora4) {
    digitalWrite(Relay, HIGH);
    delay(80);
  } else {
    digitalWrite(Relay, LOW);
  }

}
