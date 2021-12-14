int analog_pot = 0; //deklarujemy zmienną int
#define diode_pin 3
void setup() {
  Serial.begin(9600);// Konfigurujemy UART
  pinMode(diode_pin,OUTPUT);
}
void loop() {
  analog_pot = analogRead(A5);//Odczytujemy wartość napięcia
  Serial.println(analog_pot);//Wysyłamy ją do terminala
  digitalWrite(diode_pin, HIGH);
  delay(analog_pot);
  digitalWrite(diode_pin, LOW);
  delay(analog_pot); 
}
