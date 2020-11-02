
char BYTE ; 
int button_right =6 ; 
int button_left =7 ; 





void setup() {
pinMode(10,OUTPUT); 
pinMode(11,OUTPUT);
Serial.begin(9600);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
pinMode(button_right,INPUT);
pinMode(button_left,INPUT);
}

void loop() {
int right= digitalRead(button_right);
int left = digitalRead(button_left);



  if (right=LOW){
    Serial.write(1);
    Serial.println("deplacement droit\n");
    delay(500);
    
    }
    else if (left=LOW){
      Serial.write(2);
      Serial.println("deplacement à gauche\n");
      delay(500);
    }
    else{
      Serial.write(0);
      Serial.println("pas de deplacement\n");
      delay(500);
      
    }
    if (Serial.available()>0)



BYTE=Serial.read();
if (BYTE=='1'){
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  Serial.write(1);
  Serial.println("collision à droite\n");
  
  
}
else if(BYTE=='2'){
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  Serial.write(2);
  Serial.println("collision à gauche\n");
}

else if (BYTE=='0'){
   digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.write(0);
  Serial.println("pas de collision \n");
}
      
    }
    
