void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // ustawienie pinu LED_BUILTIN jako OUTPUT(wyjście) 
}

void litera_G(){
    //Długi sygnał
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);

  //Długi sygnał
  digitalWrite(LED_BUILTIN,HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);

  //Krótki sygnał
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
}

void loop() {
    litera_G();
}
