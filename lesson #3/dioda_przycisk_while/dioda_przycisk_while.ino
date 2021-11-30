#define red  3
#define button 2
void setup(){
    pinMode(red, OUTPUT);
    pinMode(button, INPUT_PULLUP);
}
void red_on(){
    digitalWrite(red, HIGH);
}
void loop() {
    while(digitalRead(button) == HIGH){
      red_on();
    }
    digitalWrite(red, LOW);
}
