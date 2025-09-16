#include<Servo.h> 
Servo s; 
void setup(){ 
pinMode(5,OUTPUT); 
pinMode(6,OUTPUT); 
s.attach(8); 
Serial.begin(9600); 
} 

void loop(){ 
  if(Serial.available()
  { 
char command=Serial.read(); 
} 
if(command=='F'){ 
digitalWrite(5,HIGH); digitalWrite(6,LOW); 
} 
if(command=='B'){ 
digitalWrite(5,LOW); digitalWrite(6,HIGH); 
} 
} 
 


if(command=='L'){ 
s.write(60,70); 
if(command=='R'){ 
s.write(120,70); 
if(command=='S'){ 
digitalWrite(5,LOW); 
} 
digitalWrite(6,LOW); 
3 
} 
