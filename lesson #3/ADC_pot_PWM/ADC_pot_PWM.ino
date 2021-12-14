int analog_pot = 0; //deklarujemy zmienną int
#define diode_pin 3
void setup() {
  Serial.begin(9600);// Konfigurujemy UART
  pinMode(diode_pin,OUTPUT);
}

void loop() {
  analog_pot = analogRead(A5);//Odczytujemy wartość napięcia
  analogWrite(diode_pin,analog_pot);
  Serial.println(analog_pot);//Wysyłamy ją do terminala
  delay(200); // dajemy delay aby zbyt częto nie odbierać danych 
}
