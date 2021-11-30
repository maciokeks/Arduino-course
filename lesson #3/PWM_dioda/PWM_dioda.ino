#define red 3
void setup() {
  pinMode(red, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  for(int i=0; i<255; i++){
    analogWrite(red,i); //ustawiamy wartość PWM na diodzie
    Serial.println(i); //Wypisujemy wartość na monitorze portu szeregowego
    delay(50); // czekamy 50 milisekund
  }
}
