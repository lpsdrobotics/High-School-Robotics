#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

const int motor1 = 5;
const int motor2 = 6;
int x_hiz=0;
int y_hiz=0;



const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN); 

int data[9]; 

void setup()   
{
 pinMode(motor1,OUTPUT);
 pinMode(motor2,OUTPUT);
  Serial.begin(9600);
    
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    radio.read( data, sizeof(data) ); 
    
  
Serial.print("data[0]=");
Serial.println(data[0]);
Serial.print("data[1]=");
Serial.println(data[1]);
Serial.print("data[2]=");
Serial.println(data[2]);
Serial.print("data[3]=");
Serial.println(data[3]);
Serial.print("data[4]=");
Serial.println(data[4]);
Serial.print("data[5]=");
Serial.println(data[5]);
Serial.print("data[6]=");
Serial.println(data[6]);
Serial.print("data[7]=");
Serial.println(data[7]);
Serial.print("data[8]=");
Serial.println(data[8]);

hareket(data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8]);

  }
}

void hareket(int x_axis, int y_axis, int button1, int button2, int button3, int button4, int button5, int button6, int button7) {
 
 x_hiz= map(x_axis,0,1023,0,255);
 analogWrite(motor1, x_hiz);
 
 y_hiz= map(y_axis,0,1023,0,255);
 analogWrite(motor2, y_hiz);

  }

