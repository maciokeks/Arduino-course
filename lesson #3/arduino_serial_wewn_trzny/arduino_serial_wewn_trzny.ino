
int zmienna1 = 12212;
void setup() {
  Serial.begin(115200);
  Serial.println("Tutaj możesz wpisac co chcesz !!!!");
}
void loop() {
  for(int i=0; i<=3;i++){
    Serial.println("Zmienna1 int jest rowna:");
    Serial.print(zmienna1);
    delay(500);
  }
  for(int i=0; i<3;i++){
    Serial.println("Zmienna1 int jest rowna:");
    Serial.print(zmienna1);
    delay(500);
  }
}
