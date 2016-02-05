int ENABLE=5; //MOTOR A
int IN1=6; //in 1
int IN2=7; //in 2 
int ENABLE2=11;//MOTOR B
int IN3=9;
int IN4=10;
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
        else
        {
              analogWrite(IN1,255-mssg2);//apagado
              digitalWrite(IN2,LOW);
              analogWrite(IN3,255-mssg2);
              digitalWrite(IN4,LOW);   
        
        }
     
     /*if(mssg == '4') // Movimiento hacia la izquierda
     {
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
     }
     if(mssg == '6') //Movimiento hacia la derecha
     {
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
     }
     if(mssg == '2') //Movimiento hacia atrás
     {
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
     }
     if(mssg == '5') //Parar
     {
        
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,LOW);
     }
     */
   }
}

