int trigg=12;
int echo=11;
int arled[]={13,9,8,7,6,5,4,3,2};
int totled=9;
int button=10;
int butt=0;
bool holdn = false;       
int laststate = LOW;   
float dist = 0;              
float time_val = 0; 

void setup() {
  pinMode(trigg,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(button,INPUT);

  for (int i=0;i<totled;i++){
    pinMode(arled[i],OUTPUT);
  }
  Serial.begin(9600);
}
 // put your setup code here, to run once:
void loop() {
  int currstate=digitalRead(button);
  if (currstate == HIGH && laststate==LOW){
    holdn = !holdn;
    delay(50); 
  }
  laststate=currstate;

  if (!holdn){
    digitalWrite(trigg,LOW);
    delayMicroseconds(10);
    digitalWrite(trigg,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigg,LOW);

    time_val = pulseIn(echo,HIGH);
    dist = (time_val * 0.034) / 2;
  }

  int ledsglow=0;
  if(dist>0 && dist<=100){
    ledsglow = totled - (int)(dist/(100/totled)); 
    if(ledsglow <= 0){
      ledsglow=1;
    }
  }
  else if(dist>100 || dist==0){
    ledsglow=0;
  }

  for (int i = 0; i < totled; i++) {
    if (i < ledsglow) {
      digitalWrite(arled[i], HIGH);
    } else {
      digitalWrite(arled[i], LOW);  
    }
  }

  if (holdn){
    Serial.print("[HELD] "); 
  }
  Serial.print("distance: ");
  Serial.print(dist);
  Serial.print(" cm;\n");
  delay(500);
}
