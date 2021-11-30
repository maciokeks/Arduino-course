int wartosc;
#define red 3
void setup() {
  Serial.begin(115200);
  pinMode(red,OUTPUT);
}
void loop() { 
  while(Serial.available()==0){
  }
  wartosc = Serial.parseInt();
  Serial.println(wartosc);
  if(wartosc<0 || wartosc>255){
    Serial.println("Wartosc niedozwolona");
  }else{
    analogWrite(red,wartosc);
  }
}
