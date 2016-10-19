Bluetooth smart car program
Arduino Bluetooth remote control programmable smart car
//*******************************
#define E1  3    
#define E2  11  
#define M1  12          
#define M2  13          
int val;
void M_Control_IO_config(void)// initialization function of motor driver shield IO
{
 pinMode(M1,OUTPUT); //
 pinMode(M2,OUTPUT); //
 pinMode(E1,OUTPUT); //
 pinMode(E2,OUTPUT); //  
}

void advance(void)     // move forward
{
   digitalWrite(M1,LOW);    // right wheel moves forward
   digitalWrite(M2, LOW);  // left wheel moves forward
   analogWrite(E1,150);  
   analogWrite(E2, 150);
}
void turnR(void)        // turn right
{
  digitalWrite(M1,LOW);  // left wheel moves forward
  digitalWrite(M2,HIGH); // right wheel moves forward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}
void turnL(void)        // turn left
{
  digitalWrite(M1,HIGH);   // left wheel moves backward
  digitalWrite(M2, LOW);   // right wheel moves forward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}    
void stopp(void)              // stop
{
   digitalWrite(M1,LOW);    
   digitalWrite(M2, LOW);  
   analogWrite(E1, 0);  
   analogWrite(E2, 0);  // both left and right wheel stop
}
void back(void)            // move backward
{
  digitalWrite(M1,HIGH);   // both left and right wheel move backward
  digitalWrite(M2, HIGH);  
  analogWrite(E1,150);  
  analogWrite(E2, 150);  
}

void setup()
{
  Serial.begin(9600);
  M_Control_IO_config();        // initialization of motor driver shield IO
  stopp();
}
void loop()
{
val=Serial.read();
if(val=='U')advance();
if(val=='D')back();
if(val=='L')turnL();
if(val=='R')turnR();
if(val=='S')stopp();
}
