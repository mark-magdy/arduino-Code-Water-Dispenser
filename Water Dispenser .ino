#define trigger 9
#define echo 8
#define LED 13
#define MOSFET 12

#define VAR_DIS 4
#define MAX_TIME 120

float time = 0,distance = 0,d1 = 0,d2 = 0,flag = 0;

void setup(){
 Serial.begin(9600);
 pinMode(MOSFET,OUTPUT);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(LED,OUTPUT);
 //delay(2000);
}
void loop(){
  d1 = measure_distance() ; 
  delay(500);
  d2 = measure_distance (); 
  while ( distance < VAR_DIS && d1 < VAR_DIS ){
      measure_distance();   
      if (distance > VAR_DIS){
      flag = 0 ;
    } 
      flag ++ ;
      if(distance < VAR_DIS && flag < MAX_TIME ){
         digitalWrite(LED,HIGH);
         digitalWrite(MOSFET,HIGH);
      }else{
         digitalWrite(LED,LOW);
         digitalWrite(MOSFET,LOW);
 
      }
      delay(100);
    
      Serial.println(distance);
  }
  delay(100) ;
  Serial.println(distance);
  measure_distance() ;     
}
float measure_distance(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
 
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);

  time = pulseIn(echo,HIGH);

  distance = time * 340/20000;
  return distance ; 
}
  
