int red = A1;
int green = A2;
int button = A3;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
}

void redOn(){
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    delay(3000);
}

void greenOn(){
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(3000);
}

void loop() {
    if (digitalRead(button) == LOW){
        redOn();
    }
    else{
        greenOn();
    }
}
