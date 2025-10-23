int BUZZER = 13;
int i = 0;
int tonos [] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

void setup(){
  pinMode(BUZZER, OUTPUT);

  for(i=0; i<12; i++){
    pinMode(i, OUTPUT);
  }
}

void setup(){
  for(i=0; i<12; i++){
    if(digitalRead(i)==HIGH){
      tone(BUZZER, tonos[i]);
      delay(500);
    }
  }
  noTone(BUZZER);
}
