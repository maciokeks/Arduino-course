/*
MIT License

Copyright (c) 2021 maciokeks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <Buzzer.h>
#define buzzer_pin 11
Buzzer buzzer(buzzer_pin);
#define echo_pin  11
#define trigger_pin 10
#define r_pin 4
#define g_pin 3
#define b_pin 2
unsigned int time; // time to travel sound must travel in both ways
double distance_cm;
double distance_inch;
void setup(){
  Serial.begin(115200);
  //Ser pins for our distance sensor
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  //Set pins for our rgb led
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
}
void loop(){
  show_cm();
  dist();
  delay(100); // delay to be able to read values in serial monitor
}
//Function for rgb led and buzzer
void show_cm(){
  if(distance_cm <=10){
    analogWrite(r_pin, 255);
    analogWrite(g_pin, 0);
    analogWrite(b_pin, 0);
    //uncomment if you want to use buzzer
    // buzzer.begin(0);
    // buzzer.sound(NOTE_G3, 100);
    // buzzer.end(0);
  }else if(distance_cm > 10 && distance_cm < 50 ){
    analogWrite(r_pin, 0);
    analogWrite(g_pin, 255);
    analogWrite(b_pin, 0);
    //uncomment if you want to use buzzer
    // buzzer.begin(0);
    // buzzer.sound(NOTE_G3, 500);
    // buzzer.end(0);
  }else{
    analogWrite(r_pin, 0);
    analogWrite(g_pin, 0);
    analogWrite(b_pin, 255);
  }
}
//Function for HC-SR04
void dist(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  pinMode(echo_pin,INPUT);
  time = pulseIn(echo_pin, HIGH);
  //Serial.println(time);

  //calculations
  //speed of soud travels one cm in 0.0343 uS - microseconds
  //we divide by 2 because we want to know the distance in one direction to the object
  distance_cm  = (time/2) * 0.0343;
  Serial.println(distance_cm);
  //speed of sound travels one inch in 0.0135 uS - microseconds
  distance_inch = (time/2) * 0.0135;
  Serial.print(" ");
  Serial.println(distance_inch);
}