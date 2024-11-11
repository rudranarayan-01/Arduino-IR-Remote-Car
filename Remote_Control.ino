#include<IRremote.h>
const int RemotePin=8;
IRrecv irrecv(RemotePin);
decode_results results;
int in1=3;
int in2=5;
int in3=6;
int in4=9;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
    
}

void loop() {
  
    if(irrecv.decode(&results))
      {
        if (results.value==0xFF629D)//Press UP Button
        { 
          Forward();
        }
        else if (results.value==0xFFA857)//Press Down Button
        { 
          Backward();
        }
         else if (results.value==0xFF22DD)//Press Left Button
        { 
          Left();
        }
        else if (results.value==0xFFC23D)//Press Right Button
        { 
          Right();
        }
        else if (results.value==0xFF02FD)//Stop
        { 
          Stop();
        }
      irrecv.resume();
    }
    }
   
 
void Backward()
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
 void Forward()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
 void Stop()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  int Left()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    }
  int Right()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    }
