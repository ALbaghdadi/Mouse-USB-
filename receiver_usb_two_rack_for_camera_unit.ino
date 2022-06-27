void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int a=0,b=0,c=0,number;
if(analogRead(A1)>50)
  a=1;
if(analogRead(A2)>50)
  b=1;
  if(analogRead(A3)>50)
 c=1;  

number=a*1+b*2+c*4;
Serial.print("number=");
Serial.println(number);

if(number ==0)
{Serial.println("key no=0");
    
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);

    }
else if(number ==1)
    {Serial.println("key no=1");
   
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);

    }
   else if(number == 2 )
    { Serial.println("key no=2");
  
      digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
  
    }
    
    else if(number == 3)
    {Serial.println("key no=3");
    
     digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW); 
   
    }

  else if(number == 4)
    {Serial.println("key no=4");
   
     digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
 
      
    }
    else if(number == 5 )
    { Serial.println("key no=5");
    digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
    }

    else if(number == 6 )
    { Serial.println("key no=6");
        digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
    }

    else if(number == 7 )
    { Serial.println("key no=7");
       digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
    }



}
