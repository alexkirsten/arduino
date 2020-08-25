int pinCLK=3;
int pinDT=2;
int value=0;
int last_value=0;
int counter=0;

void setup() {
  Serial.begin(9600);
  pinMode(pinCLK,INPUT);
  pinMode(pinDT,INPUT);
}

void loop() {
  value=(digitalRead(pinCLK)<<1)|digitalRead(pinDT);
  if(last_value!=value) {
    if((value==3 && last_value==2) || (value==0 && last_value==1)) { 
      counter++;
      Serial.print("ClockWise - Count: ");
      Serial.println(counter); 
    }
    if((value==3 && last_value==1) || (value==0 && last_value==2)) { 
      counter--;
      Serial.print("AntiClockWise - Count: "); 
      Serial.println(counter); 
    }
    last_value=value;
  }
  delay(5);
}
