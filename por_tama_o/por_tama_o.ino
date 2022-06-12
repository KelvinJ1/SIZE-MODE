int linea1=2;
int linea2=3;
int valvula1=4;
int valvula2=5;
long Duration=0;
int trigger=6;
int echo=7;


void setup() {
  // put your setup code here, to run once:
pinMode(trigger,OUTPUT);//trigger
pinMode(echo,INPUT);//echo
pinMode(linea1,INPUT);
pinMode(linea2,INPUT);
pinMode(valvula1,OUTPUT);
pinMode(valvula2,OUTPUT);
Serial.begin(9600);
}

void loop() {

  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  Duration=pulseIn(echo,HIGH);

  long Distance_cm = Distance(Duration);
  Serial.print("Distance= ");
  Serial.print(Distance_cm);
  Serial.println(" cm");
  delay(1000);


if(Distance_cm<10){
 
  if(digitalRead(linea1)==0){
    
    Serial.println("Detectado en primera linea");
   
    digitalWrite(valvula1,HIGH);
    delay(1000);
    digitalWrite(valvula1,LOW);
       }
  else{
    Serial.println("Objeto no detectado");
    }
}
  


if(Distance_cm>10){
  if(digitalRead(linea2)==0){
    
    Serial.println("Detectado en segunda linea");
    
    digitalWrite(valvula2,HIGH);
    delay(1000);
    digitalWrite(valvula2,LOW);
       }
  else{
    Serial.println("Objeto no detectado");
    }}

}
  
  long Distance(long time){
  long DistanceCalc;
  DistanceCalc= (time/2)/29;
  return DistanceCalc;
  }
