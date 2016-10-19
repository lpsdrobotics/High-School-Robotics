#define IRSensorLeft    10   // left sensor input pin
#define IRSensorMiddle  9  // middle sensor input pin
#define IRSensorRight   8  // right sensor input pin
unsigned char IRSL;        // left sensor status
unsigned char IRSM;        // middle sensor status
unsigned char IRSR;        // right sensor status
#define E1  3    
#define E2  11  
#define M1  12            
#define M2  13        
void Sensor_IO_Config()
{
 pinMode(IRSensorLeft,INPUT);
 pinMode(IRSensorMiddle,INPUT);
 pinMode(IRSensorRight,INPUT);
}
void Sensor_Scan(void)
{
 IRSL = digitalRead(IRSensorLeft);
 IRSM = digitalRead(IRSensorMiddle);
 IRSR = digitalRead(IRSensorRight);
}
void M_Control_IO_config(void)// initialization function of motor driver shield IO
{
 pinMode(M1,OUTPUT);
 pinMode(M2,OUTPUT);
 pinMode(E1,OUTPUT);
 pinMode(E2,OUTPUT);  
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
  digitalWrite(M2,HIGH); // right wheel moves backward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}
void turnL(void)        // turn left
{
  digitalWrite(M1,HIGH);   // left wheel moves backwards
  digitalWrite(M2, LOW);   // right wheel moves forward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}    
void stop(void)              // stop
{
   digitalWrite(M1,LOW);    
   digitalWrite(M2, LOW);  
   analogWrite(E1, 0);  
   analogWrite(E2, 0);  // both left and right wheels stop
}
void back(void)            // move backward
{
  digitalWrite(M1,HIGH);   // both left and right wheels move forward
  digitalWrite(M2, HIGH);  
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}

void setup()
{
  Sensor_IO_Config();
  M_Control_IO_config();        // initialization of motor driver shield IO
  stop();
}
unsigned char old_IRSL,old_IRSM,old_IRSR;
void loop()
{
Sensor_Scan();
if(IRSL==1&&IRSM==1&&IRSR==1)advance(); if((IRSL==0&&IRSM==0&&IRSR==1)||(IRSL==0&&IRSM==1&&IRSR==1)||(IRSL==1&&IRSM==0&&IRSR==1))turnL();
if((IRSL==0&&IRSM==0&&IRSR==0)||(IRSL==1&&IRSM==0&&IRSR==0)||(IRSL==1&&IRSM==1&&IRSR==0))turnR();
}