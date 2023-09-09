int fsrPin= A2;
int button=2;
int LED=3;
int buzzer=4;
int state=0;
int motor=10;
int fsrReading;
int initialSpeed=255;
int minSpeed=0;
int pressureThreshold=600;

void setup(void)
{
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(motor,OUTPUT);
  analogWrite(motor,initialSpeed);
  
 
}

void loop(void)
{
  state=digitalRead(button);
  
  if (state==HIGH){
    digitalWrite(LED,LOW);
    digitalWrite(buzzer,LOW);
  int fsrReading= analogRead(fsrPin);
  int speed=map(fsrReading,1000,0,0,255);
  analogWrite(motor,speed);
  
  Serial.println(fsrReading);
    delay(1000);}
  
  else if(state==LOW){
    
     int fsrReading= analogRead(fsrPin);
    Serial.println(fsrReading);
    delay(1000);
    
    if(fsrReading>600){
    
    digitalWrite(LED,HIGH);
    digitalWrite(buzzer,HIGH);
      int fsrReading= analogRead(fsrPin);
      int newSpeed=map(fsrReading,pressureThreshold,1000,initialSpeed,minSpeed);
  analogWrite(motor,newSpeed);
      
    }
  }
    
}
