int smokeD0 = A5;

void setup() {
  // put your setup code here, to run once:
  pinMode(smokeD0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int smoke = analogRead(smokeD0);
  Serial.print("Pin A0: ");
  Serial.println(smoke);
  delay(1000);
}
