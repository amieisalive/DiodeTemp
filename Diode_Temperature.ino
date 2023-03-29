const int sensorPin = A0;
const float baselineTemp = 17.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber <7; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor value: ");
  Serial.print(sensorVal);
  // přeměn ADC na volty
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print("volts: ");
  Serial.print(voltage);
  Serial.print("degrees C: ");
  //přemněn volty na stupně celsia
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  if(temperature < baselineTemp + 2){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }else if(temperature >= baselineTemp +2 && temperature < baselineTemp +4){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }else if(temperature >= baselineTemp +4 && temperature < baselineTemp +6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }else if(temperature >= baselineTemp +6 && temperature < baselineTemp +8){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }else if(temperature >= baselineTemp + 8 && temperature < baselineTemp +10){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }else if(temperature>= baselineTemp +10){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
  delay(1);
}
}
