int trigg=12;
int echo=11;
int arled[]={13,9,8,7,6,5,4,3,2};
int totled=10;
void setup() {
  pinMode(trigg,OUTPUT);
  pinMode(echo,INPUT);
  for (int i=0;i<10;i++){
    pinMode(arled[i],OUTPUT);
  }
  Serial.begin(9600);
}
 // put your setup code here, to run once:
void loop() {
digitalWrite(trigg,LOW);
delayMicroseconds(10);
digitalWrite(trigg,HIGH);
delayMicroseconds(10);
digitalWrite(trigg,LOW);
int ledsglow=0;

float time=pulseIn(echo,HIGH);
float dist=(time*0.034)/2;
if(dist>0 && dist<=100){
  ledsglow=totled-dist/10;
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

Serial.print("distance: ");
Serial.print(dist);
Serial.print(" cm;\n");


delay(500);
}