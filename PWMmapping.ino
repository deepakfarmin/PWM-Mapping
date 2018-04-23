 /*
 *  Author: Deepak Reddy
 *  Version : v1.0
 *  Edited on : 03/18/2018
 */
#include "ASD.h"
const int ShaftOneEncoder = 21;
volatile unsigned long ticks = 0;
int Revs = 0;
int RPM = 0;


unsigned long startMillis = 0;
void setup() 
{
    Serial.begin(115200);

// Main Motor encoder setup
  
  pinMode(MainMotorPin, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(ShaftOneEncoder, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ShaftOneEncoder), countTicks, CHANGE);
   

// Changing PWM frequency to 31KHz on PIns 5 and 3
  TCCR3B = (TCCR3B & 0b11111000) | 0x01; 
  

    while (! Serial);
  Serial.println("Speed 0 to 255");

}

void loop() 
{
  startMillis = millis();
  digitalWrite(RELAY, HIGH);
  for (uint8_t i = 30; i<=255; i++)
  {
    analogWrite(MainMotorPin, i);
    
    if((millis()-startMillis)>=60000)
    {
      startMillis = millis();
      
      break
    }
  }
  {
    
     
    int speed = Serial.parseInt();
    if (speed > 0 && speed <= 255)
    {
     
      
      
    }
    else
    {
      digitalWrite(RELAY, LOW);
    }
    }

    Revs = ticks/36;

   Serial.print("\n"); 
  Serial.print("MT");
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print("MR");
  Serial.print("\t");
  Serial.print("\t");


  Serial.print("Time");
  Serial.print("\t");
  Serial.print("\t");
  
     Serial.print("\n"); 
  Serial.print(ticks);
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print(Revs);
  Serial.print("\t");
  Serial.print("\t");

  
  Serial.print(millis());
  Serial.print("\t");
  Serial.print("\t");

if((millis()-startMillis)>=300000)
{
  RPM = ticks*1000*60/(millis()-startMillis);
  
   Serial.print("\n"); 
  Serial.print("Revs after 5mins");
  Serial.print("\t");
  Serial.print("\t");

   Serial.print(RPM);
  Serial.print("\t");
  Serial.print("\t");
}
  
   
   
  }

   void countTicks()
   {
 // digitalWrite(tick_led,HIGH);
  ticks++;
  
 }
  


