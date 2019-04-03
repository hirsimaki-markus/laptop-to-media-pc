int led = 3;
int sound = 2;
int data;
int value = 0;
unsigned long start;
unsigned long test;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sound, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  data = digitalRead(sound);
  //delay(100);
  if (data == 1) {
    start = millis();
    value += 1;
    Serial.println(value);
    delay(100);
  }
  test = millis();
  if (test - start > 1000){
    value = 0;
  }
  if (value == 3) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW); 
    value = 0;
  }
}
