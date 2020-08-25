class Sensor {
  public :
  int clk;
  int dt;
  int value=0;
  int last_value=0;
  int counter=0;
  Sensor() {}
  Sensor(int _dt, int _clk) {
    dt=_dt;
    clk=_clk;
  }
};

Sensor SensorList[3];

void setup() {
  Serial.begin(9600);
  SensorList[0]=Sensor(2,3);
  SensorList[1]=Sensor(4,5);
  SensorList[2]=Sensor(6,7);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
}

void loop() {
  for(int i=0;i<3;i++) {
    SensorList[i].value=(digitalRead(SensorList[i].clk)<<1)|digitalRead(SensorList[i].dt);
    if(SensorList[i].last_value!=SensorList[i].value) {
      if((SensorList[i].value==3 && SensorList[i].last_value==2) || (SensorList[i].value==0 && SensorList[i].last_value==1)) { 
        SensorList[i].counter++; 
        Serial.print("Sensor: ");
        Serial.print(i);
        Serial.print(" - Count: ");
        Serial.println(SensorList[i].counter);
      }
      if((SensorList[i].value==3 && SensorList[i].last_value==1) || (SensorList[i].value==0 && SensorList[i].last_value==2)) { 
        SensorList[i].counter--; 
        Serial.print("Sensor: ");
        Serial.print(i);
        Serial.print(" - Count: ");
        Serial.println(SensorList[i].counter);
      }
      SensorList[i].last_value=SensorList[i].value;
    }
  }
  delay(5);
}
