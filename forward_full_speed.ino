/**********************forward_full_speed************************   

Connect Wire:

Motor Driver Signal line:
UNO R3 development board A0 pin connect Smart Robot Car M6
UNO R3 development board A1 pin connect Smart Robot Car M5
UNO R3 development board A2 pin connect Smart Robot Car M4
UNO R3 development board A3 pin connect Smart Robot Car M3
UNO R3 development board A4 pin connect Smart Robot Car M2
UNO R3 development board A5 pin connect Smart Robot Car M1

Buzzer Signal line: 
UNO R3 development board pin 13 connect Smart Robot Car Buzzer Control interface.

Power Cord and Ground: xax3x
UNO R3 development board 5V connect Smart Robot Car 5V
UNO R3 development board GND connect Smart Robot Car GND


*******************************************************************/

//Pin definition：
int En1 = A0;     //L293D EN1 Correspond Development Board R3 A0 pin
int In1 = A1;     //L293D IN1 Correspond Development Board R3 A1 pin
int In2 = A2;     //L293D IN2 Correspond Development Board R3 A2 pin

int In4 = A3;     //L293D IN4 Correspond Development Board R3 A3 pin
int In3 = A4;     //L293D IN3 Correspond Development Board R3 A4 pin
int En2 = A5;     //L293D EN2 Correspond Development Board R3 A5 pin

int Beep = 13;    //Buzzer Signal line Correspond Development Board R3 13 pin

void BeepCTL(unsigned char S)   //Buzzer control function
{
 if(S==1)                       //Set Parameter is 1, the buzzer is ON
 {
  digitalWrite(Beep,LOW);
 }
 else if(S==0)                  //Set Parameter is 0, the buzzer is OFF
 {
  digitalWrite(Beep,HIGH);  
 }
}

void forward(void)              //Car forward control function
{
 digitalWrite(En1,HIGH);        //Control left wheel forward
 digitalWrite(In1,HIGH); 
 digitalWrite(In2,LOW);

 digitalWrite(En2,HIGH);        //control right wheel forward
 digitalWrite(In3,HIGH); 
 digitalWrite(In4,LOW);
}


void loop() {
  // put your main code here, to run repeatedly:   
}

void setup() {
  // put your setup code here, to run once:
  pinMode(En1,OUTPUT);   //Set the pin to output 
  pinMode(In1,OUTPUT);   //Set the pin to output  
  pinMode(In2,OUTPUT);   //Set the pin to output  
  pinMode(En2,OUTPUT);   //Set the pin to output  
  pinMode(In3,OUTPUT);   //Set the pin to output  
  pinMode(In4,OUTPUT);   //Set the pin to output  

  pinMode(Beep,OUTPUT);  //Set the pin to output  

  BeepCTL(1);            //control the buzzer ON
  delay(1000);           
  BeepCTL(0);            //control the buzzer OFF

  forward();             //Call car forward control function
}
