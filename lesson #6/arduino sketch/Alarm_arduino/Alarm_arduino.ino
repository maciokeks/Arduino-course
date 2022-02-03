//Załączenie biblioteki keypad
#include <Keypad.h>

//zdefiniowanie pinów 
int button_activate = 12;
const byte pir = 2;

#define g A0
#define r A1
#define b A2


//potrzebne nam zmienne
unsigned long int time_pressed = 0;
unsigned long int time_to_activate = 4000; // Time to activate the alarm 
int button_state = LOW;

//hasło poprawne oraz obecne hasło
String password = "112233";
String password_get;


//zmienne bool od statusu alarmu oraz czujnika ruchu
bool alarm_activated = false;
volatile bool alarm_movement = false;

//ilość linijek i kolumn
const byte ROWS = 4;
const byte COLS = 4;

//tablica dwuwymiarowa
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','k','d'}
};
byte colPins[COLS] = {3, 4, 5, 6}; 
byte rowPins[ROWS] = {7, 8, 9, 10};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(115200);

  pinMode(button_activate,INPUT);
  pinMode(pir,INPUT);

  pinMode(g,INPUT);
  pinMode(r,INPUT);
  pinMode(b,INPUT);

  attachInterrupt(digitalPinToInterrupt(pir), alarm, RISING); 
}
void loop(){
  button_state = digitalRead(button_activate);

  if(alarm_movement == true && alarm_activated == true){
    Serial.println("detected movement");
    analogWrite(r,255);
  }


  if(button_state == HIGH && alarm_activated == true){
    Serial.println("alarm after pressed");
    is_pressed_after();
  }
  if(button_state == HIGH &&  alarm_activated == false)
  {
    Serial.println("alarm before pressed");
    is_pressed();
  }
}

void is_pressed_after(){
  time_pressed = 0;
  unsigned long int start = millis();
  while(button_state == HIGH){
    button_state = digitalRead(button_activate);

    if(button_state == LOW){
      unsigned long int time_now = millis();
      time_pressed = (time_now - start);
      break;
    }

  }

  Serial.print("time: ");
  Serial.print(time_pressed);

  if(time_pressed >= time_to_activate){
    Serial.println("Alarm deactivated");
    analogWrite(r,0);

  next_try:

  password_get = "";
    while(true){
      char key = customKeypad.getKey();
       if(key){
          if(key == 'k'){
            Serial.println("exit while");
            break;
          }else{
            password_get = password_get + key;
          } 
        Serial.println(key);
        Serial.println(password_get);
        }
      }

      //Sprawdzanie poprawności wprowadzonego hasła 
      if(password_get==password){
            alarm_movement = false;
            alarm_activated = false;
            Serial.println("Success alarm is unblocked ");
    }else{
      //haslo sie nei zgadza
      Serial.println("Failed try again");
      goto next_try;
      
    }
    //Wypisanie hasla na ekran
    Serial.println(password_get);
  }else{
    //Przytrzymaj dłużej aby wejść w ten tryb
    Serial.println("Please hold more seconds");
  }
  time_pressed = 0;
}



void is_pressed(){
  time_pressed = 0;
  unsigned long int start = millis();
  while(button_state == HIGH){
    button_state = digitalRead(button_activate);
    //Serial.println("pressed");
    if(button_state== LOW){
      unsigned long int time_now = millis();
      time_pressed = (time_now - start);
      break;
    }
  }
  Serial.print("time :");
  Serial.print(time_pressed);
  if(time_pressed >= time_to_activate){
    Serial.println("Alarm activated. 5 second to leave ");
    alarm_activated = true;
    delay(5000);
  }else{
    Serial.println("Please hold more seconds");
  }
  time_pressed = 0;
}

//Funkcja od przerwań
void alarm(){
  alarm_movement = true;
}