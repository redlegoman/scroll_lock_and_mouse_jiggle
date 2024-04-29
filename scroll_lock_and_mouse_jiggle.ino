#include <Mouse.h>
#include "Keyboard.h"

unsigned long previousMillis = 0;

const long interval = 60000; 
int move_interval = 3;
int distance = 2;
int x=1;
int y=1;

void doit()
{
    Serial.println(millis());

    Serial.println("Pressing scroll lock");
    Keyboard.press(KEY_SCROLL_LOCK);
    delay(10);
    Keyboard.release(KEY_SCROLL_LOCK);

    delay(125);

    Serial.println("Releasing scroll lock");
    Keyboard.press(KEY_SCROLL_LOCK);
    delay(10);
    Keyboard.release(KEY_SCROLL_LOCK);

    
    Serial.print(" distance:");
    Serial.print(distance);
    Serial.print(" x:");
    Serial.print(x);
    Serial.print(" y:");
    Serial.print(y);
    Serial.print(" move_interval:");
    Serial.print(move_interval);
    Serial.println(" ");
    Serial.println("moving back");
    x = 1; y = 1;
    for (int i = 0; i < distance; i++) {
      Mouse.move(x, y, 0);
      delay(move_interval);
    }
    delay(250);
    Serial.print(" distance:");
    Serial.print(distance);
    Serial.print(" x:");
    Serial.print(x);
    Serial.print(" y:");
    Serial.print(y);
    Serial.print(" move_interval:");
    Serial.print(move_interval);
    Serial.println(" ");
    Serial.println("moving forward");
    x = -1; y = -1;
    for (int i = 0; i < distance; i++) {
      Mouse.move(x, y, 0);
      delay(move_interval);
    }

}

void setup()
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
  delay(2000);
  Serial.println("setup...");
  Serial.print("Time interval set to ");
  Serial.print(interval / 1000);
  Serial.println("");
  Mouse.begin();
  Keyboard.begin();
  delay(2000);
  doit();
}

void loop()
{
  unsigned long currentMillis = millis();

  
  /*
  Serial.print("currentMillis=");
  Serial.println(currentMillis/1000);
  Serial.print("previousMillis=");
  Serial.println(previousMillis/1000);
  Serial.print("currentMillis - previousMillis=");
  Serial.println((currentMillis - previousMillis)/1000);
  Serial.println("-");
*/
  
  delay(500);
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    doit();
  } //millis loop
  
}

