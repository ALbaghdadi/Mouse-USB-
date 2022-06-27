#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
int number=0;
byte enable1 = A2; 
int led=0;
long unsigned int x=0;
class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown  (uint8_t mod, uint8_t key);
    void OnKeyUp  (uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  //Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  //Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  //Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  //Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

 // Serial.print(" >");
 // PrintHex<uint8_t>(key, 0x80);
  //Serial.print("< ");

  //Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  //Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  //Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  //Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
 // Serial.print("DN ");
 // PrintKey(mod, key);
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(key);

  
     
    number*=10;
    if(number>16)
    number=0;
   
    if(key =='Y')
    {  
      number+=1;
      
    }
   else if(key =='Z')
    { number+=2;
    }
    
    else if(key =='[')
    {number+=3;
    }
    else if(key ==']')
   { number+=5;
      
    }
    else if(key =='^')
    {number+=6;
      
    }
    
    else if(key =='_')
    {number+=7;
      
    }
    else if(key =='`')
    {number+=8;
      
    }
    else if(key =='a')
    number+=9;

      else if(key =='b')
    number+=0;
    else if(key >'[' && key<']')
    {number+=4;
      
    }
    else
    number=0;


if((x>0 && millis()-x>1000 && number >=10) || number>16)
 { number-=10;
   x=0;
 }
 
     if(number ==1)
    {
     mySerial.print('a');
      delay(100);
  digitalWrite(enable1,LOW);    
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      x=millis();
    }
   else if(number == 2 )
    { 
    mySerial.print('b');
      delay(100);
      digitalWrite(enable1,LOW);  
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
   
    }
    
    else if(number == 3)
    {
     mySerial.print('c');
      delay(100);
      digitalWrite(enable1,LOW);  
     digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW); 
  
    }

  else if(number == 4)
    {mySerial.print('d');
      delay(100);
      digitalWrite(enable1,LOW);  
     digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      
    }
    else if(number == 5 )
    { mySerial.print('e');
        delay(100);
      digitalWrite(enable1,LOW);  
     digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
    }

    else if(number == 6 )
    { mySerial.print('f');
        delay(100);
       digitalWrite(enable1,LOW);  
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
    }

    else if(number == 7 )
    { mySerial.print('g');
        delay(100);
       digitalWrite(enable1,LOW);  
      digitalWrite(6,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
    }

    else if(number == 8 )
    { mySerial.print('h');
     delay(100);
       digitalWrite(enable1,LOW);  
      digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
    }
    else if(number == 9)
   { mySerial.print('i');
     digitalWrite(enable1,HIGH);  
 
      
    }
    else if(number == 10)
    {mySerial.print('j');
      digitalWrite(enable1,HIGH);  

      
    }
    
    else if(number == 11)
    {mySerial.print('k');
      digitalWrite(enable1,HIGH);  
   
    }
    else if(number == 12)
    {mySerial.print('l');
      digitalWrite(enable1,HIGH);  
      
    }

    else if(number == 13)
    {mySerial.print('m');
       digitalWrite(enable1,HIGH);  
      
    }
    else if(number == 14)
    {mySerial.print('n');
       digitalWrite(enable1,HIGH);  
     
      
    }
    else if(number == 15)
    {mySerial.print('o');
      digitalWrite(enable1,HIGH);  
    
    }
    else if(number == 16)
    {mySerial.print('p');
      digitalWrite(enable1,HIGH);  

      
    }
 
    

Serial.print("number=");
Serial.println(number);
if(number>16 )
number=0;
 
  digitalWrite(13,led);
   led=1-led;


    
}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    Serial.println("LeftGUI changed");
  }

  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
   Serial.println("RightGUI changed");
  }

}


void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
  Serial.print("UP ");
  PrintKey(mod, key);
}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  Serial.print("ASCII: ");
  Serial.println((char)key);
};

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

KbdRptParser Prs;

void setup()
{
  Serial.begin( 9600 );

  Serial.println("Start");
mySerial.begin(9600);
  mySerial.println("Hello, world?");
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(4,OUTPUT);
pinMode(2,OUTPUT);
pinMode(enable1,OUTPUT);
digitalWrite(enable1,LOW);
pinMode(13,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);

digitalWrite(13,LOW);
digitalWrite(A2,LOW);
digitalWrite(A3,LOW);
  if (Usb.Init() == -1)
    Serial.println("OSC did not start.");

  delay( 200 );
  

  HidKeyboard.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
