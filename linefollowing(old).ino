Line tracking car program
#define SensorLeft    4   // left sensor input pin
#define SensorMiddle  5  // middle sensor input pin
#define SensorRight   6  // right sensor input pin
unsigned char SL;        // left sensor status
unsigned char SM;        // middle sensor status
unsigned char SR;        // right sensor status
#define E1  3    // speed control pin, ENA pin on motor driver shield
#define E2  11   // speed control pin, ENA pin on motor driver shield
#define M1  12            // motor direction control, IN1 pin on motor driver shield
#define M2  13          // motor direction control, IN2 pin on motor driver shield
void Sensor_IO_Config()
{
 pinMode(SensorLeft,INPUT);
 pinMode(SensorMiddle,INPUT);
 pinMode(SensorRight,INPUT);
}
void Sensor_Scan(void)
{
 SL = digitalRead(SensorLeft);
 SM = digitalRead(SensorMiddle);
 SR = digitalRead(SensorRight);
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
   digitalWrite(M1,LOW);    // wheel on the right moves forward
   digitalWrite(M2, LOW);  // wheel on the left moves forward
   analogWrite(E1,150);  
   analogWrite(E2, 150);
}
void turnR(void)        // turn right
{
  digitalWrite(M1,LOW);  // wheel on the left moves forward
  digitalWrite(M2,HIGH); // wheel on the right moves backward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}
void turnL(void)        // turn left
{
  digitalWrite(M1,HIGH);   // wheel on the left moves backward
  digitalWrite(M2, LOW);   // wheel on the right moves forward
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}    
void stopp(void)              // stop
{
   digitalWrite(M1,LOW);    
   digitalWrite(M2, LOW);  
   analogWrite(E1, 0);  
   analogWrite(E2, 0);  // both right &left wheel stop  
}
void back(void)            // move backwards
{
  digitalWrite(M1,HIGH);   // both right &left wheel moves backwards
  digitalWrite(M2, HIGH);  
  analogWrite(E1,150);  
  analogWrite(E2, 150);
}

void setup()
{
  Sensor_IO_Config();
  M_Control_IO_config();        //  initialization of motor controller module IO
  stopp();
}
void loop()
{
Sensor_Scan();  if((SL==1&&SM==1&&SR==1)||(SL==1&&SM==1&&SR==0)||(SL==0&&SM==1&&SR==1)||(SL==0&&SM==1&&SR==0))advance();
if((SL==0&&SM==0&&SR==0)||(SL==0&&SM==0&&SR==1))turnL();
if(SL==1&&SM==0&&SR==0)turnR();
}