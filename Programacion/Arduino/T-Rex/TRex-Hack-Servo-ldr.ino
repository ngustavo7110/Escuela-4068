//Canal de YouTube -> RobotUNO
//Hackeando el T-Rex de google

#include <Servo.h>  

int valor = 0;  
Servo serv; 
void setup() { 
  serv.attach(9); 
} 
void loop() {
  valor = analogRead(0);   
  if(690>valor){    
   serv.write(60);        
  }
  else{  
   serv.write(90);
  } 
  delay(5);
}
