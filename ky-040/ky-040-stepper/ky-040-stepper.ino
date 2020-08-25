unsigned char full_step[4]={0x3,0x6,0xC,0x9};
int array_pos=0;
int pinDT=6;
int pinCLK=7;
int value=0;
int last_value=0;

void setup() {
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);  // Pin 1 - ULN2003 Driver
  pinMode(9,OUTPUT);  // Pin 2 - ULN2003 Driver
  pinMode(10,OUTPUT); // Pin 3 - ULN2003 Driver
  pinMode(11,OUTPUT); // Pin 4 - ULN2003 Driver
 
}

void loop() {
    value=(digitalRead(pinCLK)<<1)|digitalRead(pinDT);
    if(last_value!=value) {
      if((value==3 && last_value==2) || (value==0 && last_value==1)) { 
        array_pos++;
        if(array_pos==4) array_pos=0;
        PORTB=full_step[array_pos];
      }
      if((value==3 && last_value==1) || (value==0 && last_value==2)) { 
        if(array_pos==0) array_pos=4;
        array_pos--;
        PORTB=full_step[array_pos];
      }
      last_value=value;
    }
  delay(5);
  
}
