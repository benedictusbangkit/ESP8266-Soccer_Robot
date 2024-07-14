#include <Arduino.h>

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6TyDp6dT_"
#define BLYNK_TEMPLATE_NAME "Robot"
#define BLYNK_AUTH_TOKEN "-ku_DdG-HeTcKgi2yVclPTJyeREdG0ae"
#include <BlynkSimpleEsp8266.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "test";
char pass[] = "cukup123";

#define PIN1 D1
#define PIN2 D2
#define PIN3 D3
#define PIN4 D4

float Vforward;
float Vright;
float Vleft;

void forward()
{
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, HIGH);
  analogWrite(PIN1, 255);
  analogWrite(PIN2, 0);
}

void right()
{
 digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
  analogWrite(PIN1, 255);
  analogWrite(PIN2, 0); 
}

void left()
{
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
  analogWrite(PIN1, 0);
  analogWrite(PIN2, 255);
}

void stop()
{
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, LOW);
  analogWrite(PIN1, 0);
  analogWrite(PIN2, 0);
}

BLYNK_WRITE(V0)
{
  Vforward = param.asInt() == 0;
  if (Vforward == 0)
  {
    forward();
  }
  else
  {
    stop();
  }
}

BLYNK_WRITE(V1)
{
  Vright = param.asInt() == 0;
  if (Vright == 0)
  {
    right();
  }
  else
  {
    stop();
  }
}

BLYNK_WRITE(V2)
{
  Vleft = param.asInt() == 0;
  if (Vleft == 0)
  {
    left();
  }
  else
  {
    stop();
  }
}

void setup()
{
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  Blynk.run();
}
