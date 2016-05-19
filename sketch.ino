#include <Servo.h>

Servo miServo;
Servo miServo2;
int angulo=90;
int angulo2=90;

int ENABLE=4; //MOTOR A
int IN1=5; //motor A1
int IN2=6; //motor A2
int ENABLE2=12;//MOTOR B
int IN3=10; //motor B1
int IN4=11; //motor B2
int mssg = 0; //variable para guardar el mensaje
int mssg2 = 255; 

void avanzar(int mssg)
{
          analogWrite(IN1,255-mssg);//inverso
          digitalWrite(IN2,HIGH);
          analogWrite(IN3,255-mssg);
          digitalWrite(IN4,HIGH);
}

void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  miServo.attach(9); //declaración de pin 9 para servo1
  miServo2.attach(3); //declaración de pin 3 para servo2
  
  digitalWrite(ENABLE, HIGH);// (pin,high =1 low=0)
  digitalWrite(ENABLE2,HIGH); 
  Serial.setTimeout(50);
  
  Serial.begin(9600); //iniciando Serial

}

void loop()
{ 
     
  
  if (Serial.available() > 0)
  {
        mssg = Serial.parseInt(); 
        angulo=constrain(angulo,0,180); //restricción de angulo
        angulo2=constrain(angulo2,0,180);//restricción de angulo2
        if(mssg==8)
        {       
              analogWrite(IN1,255-mssg2); //adelante
              digitalWrite(IN2,HIGH);
              analogWrite(IN3,255-mssg2);
              digitalWrite(IN4,HIGH);              
        }
        
        else if(mssg==4)
        {             
              analogWrite(IN1,255-mssg2);//izquierda
              digitalWrite(IN2,HIGH);
              analogWrite(IN3,255-mssg2);
              digitalWrite(IN4,LOW);              
        }
        
        else if(mssg==6)
        {       
              analogWrite(IN1,255-mssg2);//derecha
              digitalWrite(IN2,LOW);
              analogWrite(IN3,255-mssg2);
              digitalWrite(IN4,HIGH);              
        }
        
        else if(mssg==2)
        {
              analogWrite(IN2,255-mssg2);//datras
              digitalWrite(IN1,HIGH);
              analogWrite(IN4,255-mssg2);
              digitalWrite(IN3,HIGH);    
        
        }        

        else if(mssg==1)
        {    
              angulo=angulo+10;  
              miServo.write(angulo); 
        }

         else if(mssg==3)
        {
              angulo=angulo-10;  
              miServo.write(angulo);
        }

         else if(mssg==7)
        {
              angulo2=angulo2+10;  
              miServo2.write(angulo2);
        }

         else if(mssg==9)
        {
              angulo2=angulo2-10;  
              miServo2.write(angulo2);
        }

         else if(mssg==5)
        {
              mssg2=mssg2-10;
              if(mssg2<160)
              {
                  mssg2=160; 
              }
        }

         else if(mssg==0)
        {
              mssg2==mssg2+10;
              if(mssg2>255)
              {
                  mssg2=255; 
              }
        }
        
        else
        {
              analogWrite(IN1,255-mssg2);//apagado
              digitalWrite(IN2,LOW);
              analogWrite(IN3,255-mssg2);
              digitalWrite(IN4,LOW);      
        }
   }
}

