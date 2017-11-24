#include <SoftwareSerial.h>
#include <LiquidCrystal.h>


SoftwareSerial mySerial(0, 1);
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

//motor A pins
int ma1=3;
int ma2=4;
int ena=2;

//motor B pins
int mb1=5;
int mb2=6;
int enb=13;

//variables
int start=0;
int num=0;
int siz=0; 
char check=0;
int finish=0;
void setup() 
{
mySerial.begin(38400);

pinMode(ma1,OUTPUT);
digitalWrite(ma1,HIGH);
pinMode(ma2,OUTPUT);
digitalWrite(ma2,LOW);
pinMode(ena,OUTPUT);

pinMode(mb1,OUTPUT);
digitalWrite(mb1,HIGH);
pinMode(mb2,OUTPUT);
digitalWrite(mb2,LOW);
pinMode(enb,OUTPUT);



lcd.begin(16, 2);
}


void loop()
{
 intro();
 input();
 confirm();
 process();
}


void intro()
     {lcd.clear();
      while(start==0)
       {
        lcd.setCursor(0,0);
        lcd.write("Paper Cutting ");
        lcd.setCursor(0,1);
        lcd.write("Machine  V1.0");

        if (mySerial.available())
                  {
                 start=mySerial.parseInt();
                  }

       
       }
      
     }

void input()
    {
        lcd.clear();
        while(num==0)
           {    
            lcd.setCursor(0,0);
            lcd.write("No. of papers");
            lcd.setCursor(0,1);
            lcd.print("to be cut ?"); 

              if (mySerial.available())
                  {
                 num=mySerial.parseInt();
          
                 mySerial.println("Papers to be cut :");
                 mySerial.println(num);
                  }
            } // end of num while
              lcd.clear();
        while(num!=0&& siz==0)
             {
            lcd.setCursor(0,0);
            lcd.write("Select the size");
            lcd.setCursor(0,1);
            lcd.print("1(S),2(M),3(L)"); 

              if (mySerial.available())
                  {
                 siz=mySerial.parseInt();
          
                 mySerial.println("Size of the paper :");
                 mySerial.println(siz);
                  }
             } //end of size while


              
             }

//function to confirm the entry
void confirm()
    {

        while(check==0)        //Checking if correct
         {
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.write("Number :");
           lcd.setCursor(10,0);
           lcd.print(num,DEC);
           lcd.setCursor(0,1);
           lcd.write("Size :");
           lcd.setCursor(10,1);
           lcd.print(siz,DEC);
           delay(2000);

           lcd.clear();
           lcd.setCursor(0,0);
           lcd.write("Press OK");
           lcd.setCursor(0,1);
           lcd.write("to confirm");
           delay(2000);

           if (mySerial.available())
                  {
                 check=mySerial.parseInt();
                  }
    }
 }

void process()
    {
      lcd.clear();
    while(finish==0)
        { 
        lcd.setCursor(0,0);
        lcd.write("Processing...");
        digitalWrite(ena,HIGH);
        delay(500);
        digitalWrite(ena,LOW);
        delay(400);
        digitalWrite(enb,HIGH);
        delay(750);
        
        digitalWrite(enb,LOW);
     
        }

        lcd.clear();
    }

