#define BLYNK_PRINT Serial

#define LED_PIN_D1 5
#define LED_PIN_D2 4
#define LED_PIN_D3 0

#include <BlynkSimpleEsp8266.h>

char auth[] = "my-auth";
char ssid[] = "my-wifi";
char pass[] = "my-wifi-password";

void setup()
{
  pinMode(LED_PIN_D1, OUTPUT);
  pinMode(LED_PIN_D2, OUTPUT);
  pinMode(LED_PIN_D3, OUTPUT);

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
