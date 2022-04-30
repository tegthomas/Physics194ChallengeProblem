#include <avr/sleep.h>
int lightCurrent = 0;
enum State{
  seriesSpinning,
  seriesNoSpinning,
  parallelSpinning,
  parallelNoSpinning
};
State DCMotorState = seriesSpinning;
void setup() {
  // put your setup code here, to run once:
set_sleep_mode(SLEEP_MODE_PWR_DOWN);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  DCMotorState=nextState(DCMotorState);
}

State nextState(State DCMotorState){
 switch(DCMotorState){
  case seriesSpinning:
    Serial.println("Graph of the current through lights when DC motor is running in series: ");
    while(millis()<5000){
    lightCurrent = 0;
    Serial.println(" ");
    delay(100);
    lightCurrent = 1;
    Serial.println("l");
    delay(100);
    }
      Serial.println("");
      DCMotorState = seriesNoSpinning;
    break;
   case seriesNoSpinning:
   Serial.println("Graph of the current through lights when DC motor is in series and stopped: ");
    while(millis()<10000){
    lightCurrent = 10;
   for(int i=0; i<lightCurrent; i++){
     Serial.print("l");
    }
    delay(100);
   Serial.println("");
   }
      Serial.println("");
      DCMotorState = parallelSpinning; 
    break;
   case parallelSpinning:
   Serial.println("Graph of the current through lights when DC motor is running in parallel: ");
    while(millis()<15000){
    lightCurrent = 101;
    for(int i=0; i<lightCurrent; i++){
     Serial.print("l");
    }
    Serial.println("");
    delay(100);
    lightCurrent = 100;
    for(int i=0; i<lightCurrent; i++){
     Serial.print("l");
    }
    Serial.println("");
    delay(100);
    }
      Serial.println("");
      DCMotorState = parallelNoSpinning; 
    break;
   case parallelNoSpinning:
   Serial.println("Graph of the current through lights when DC motor is parallel and stopped: ");
    while(millis()<20005){
    lightCurrent = 90;
    for(int i=0; i<lightCurrent; i++){
     Serial.print("l");
    }
    delay(100);
    Serial.println("");
    }
      sleep_mode();
      break;
 }
 return DCMotorState;
}
