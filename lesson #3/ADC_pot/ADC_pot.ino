int analog_pot = 0; //deklarujemy zmienną int

void setup() {
  Serial.begin(9600);// Konfigurujemy UART
}

void loop() {
  analog_pot = analogRead(A5);//Odczytujemy wartość napięcia
  
  Serial.println(odczytanaWartosc);//Wysyłamy ją do terminala
  
  delay(200); // dajemy delay aby zbyt częto nie odbierać danych 
}
