//Moteurs Droit
int PWDD = 3;
int DIRD = 4;
//Moteurs Gauche
int PWDG = 5;
int DIRG = 6;


void setup() {
pinMode(PWDD, OUTPUT);
pinMode(DIRD, OUTPUT);
pinMode(PWDG, OUTPUT);
pinMode(DIRG, OUTPUT);
Serial.begin(9600);
}

void loop() {
Serial.println("Avance");
digitalWrite(PWDD,HIGH);
digitalWrite(DIRD,HIGH);
digitalWrite(PWDG,HIGH);
digitalWrite(DIRG,LOW);
delay(5000);
digitalWrite(PWDD, LOW);
digitalWrite(PWDG, LOW);
delay(2000);

Serial.println("Recule");
digitalWrite(PWDD,HIGH);
digitalWrite(DIRD,LOW);
digitalWrite(PWDG,HIGH);
digitalWrite(DIRG,HIGH);
delay(5000);
digitalWrite(PWDD, LOW);
digitalWrite(PWDG, LOW);
delay(2000);
}
