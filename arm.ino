/*#include<SoftwareSerial.h>*/

 #define outputA 2
 #define outputB 3
 #define outputC 12
 #define outputD 13
 
 int counter1 = 0;
 int counter2 = 0;
 int aState1;
 int aLastState1;  
 int aState2;
 int aLastState2;

  
 float X; //value of x-coordinate
 float Y; //value of y-coordinate
 
 float r1;
 float r2;
 float degree1; //angle of link 1
 float degree2; //angle of link 2
 
 float l1=10; //link 1 length
 float l2=10; //link 2 length

 int a;
 int b;

 char data;
  
void setup() 
{
Serial.begin(9600);
 pinMode(4,OUTPUT);    //mot pin1 
 pinMode(5,OUTPUT);     //mot pin2
 pinMode(6,OUTPUT);    //enable m1
 pinMode(10,OUTPUT);    //mot pin3 
 pinMode(11,OUTPUT);    //mot pin4 
 pinMode(9,OUTPUT);     //enable m2
 
 pinMode (outputA,INPUT);
 pinMode (outputB,INPUT);
 pinMode (outputC,INPUT);
 pinMode (outputD,INPUT);
 aLastState1 = digitalRead(outputA); 
 aLastState2 = digitalRead(outputC);
 //Serial.println("LABEL,X_val,Y_val"); //sending data to excel sheet
 user();
}


 void user()
 {
  Serial.println(".........POSITION PLOTTER.........");
  Serial.println("A: HOME,  B: POSITION   Enter your choice: ");
  while(!Serial.available())
   {
      //wait till the user enter choice
   }
   {
       data=Serial.read();
       Serial.println(data);
   }
       switch(data)
       {
        case'A':
          {
            X=20;
            Y=0;
            loop();
             break;
          }
        case'B':
        {
            calculation();
           break;
        } 
 }
 }

  void calculation()
 {
  Serial.println("Enter values in Centimeter");
  Serial.print("X=");
  while(!Serial.available())
  {
    //wait till get the value
  }
  X=Serial.parseFloat();
  Serial.print(X);
  Serial.println(" cm");
  
  Serial.print("Y=");
  while(!Serial.available())
  {
    //wait till get the value
  }
  Y=Serial.parseFloat();
  Serial.print(Y);
  Serial.println(" cm");
  r2=acos(((X*X)+(Y*Y)-(100)-(100))/(2*100));
  r1=(atan(Y/X))-(atan(10*sin(r2)/(10+(10*cos(r2)))));  //link 1 length =10 cm, link 2 length= 10 cm
  degree1=r1* 57.2957795;
  degree2=r2* 57.2957795;
  Serial.print("Degree1: ");
  Serial.println(degree1);
  Serial.print("Degree2: ");
  Serial.println(degree2);
  Serial.println(" ");

{
  if(degree1<=6)
  {
  Serial.println("Degree1:0 ");
  int a=0;
  }
  if(degree1<=12&&degree1>6)
  {
  Serial.println("Degree1:12 ");
  int a=1;
  }
  if(degree1<=24&&degree1>18)
  {
  Serial.println("Degree1:24 ");
  int a=2;
  }
  if(degree1<=36&&degree1>30)
  {
  Serial.println("Degree1:36 ");
  int a=3;
  }
  if(degree1<=48&&degree1>42)
  {
  Serial.println("Degree1:48, ");
  int a=4;
  }
  if(degree1<=60&&degree1>54)
  {
  Serial.println("Degree1:60 ");
  int a=5;
  }
  if(degree1<=72&&degree1>66)
  {
  Serial.println("Degree1:72 ");
  int a=6;
  }
  if(degree1<=84&&degree1>78)
  {
  Serial.println("Degree1:84 ");
  int a=7;
  }
}

{
  if(degree2<=6)
  {
  Serial.println("Degree2:0 ");
  int b=0;
  }
  if(degree2<=12&&degree2>6)
  {
  Serial.println("Degree2:12 ");
  int b=1;
  }
  if(degree2<=24&&degree2>18)
  {
  Serial.println("Degree2:24 ");
  int b=2;
  }
  if(degree2<=36&&degree2>30)
  {
  Serial.println("Degree2:36 ");
  int b=3;
  }
  if(degree2<=48&&degree2>42)
  {
  Serial.println("Degree2:48 ");
  int b=4;
  }
  if(degree2<=60&&degree2>54)
  {
  Serial.println("Degree2:60 ");
  int b=5;
  }
  if(degree2<=72&&degree2>66)
  {
  Serial.println("Degree2:72 ");
  int b=6;
  }
  if(degree2<=84&&degree2>78)
  {
  Serial.println("Degree2:84 ");
  int b=7;
  }
}
 loop();
 }

void loop() 
{
 {
  r2=acos(((X*X)+(Y*Y)-(100)-(100))/(2*100));
  r1=(atan(Y/X))-(atan(10*sin(r2)/(10+(10*cos(r2)))));
  degree1=r1* 57.2957795;
  degree2=r2* 57.2957795;
 }

{
  if(degree1<=6)
  {
  int a=0;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)  
   {  
     if (digitalRead(outputB) != aState1) 
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,100);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
 
  
  
  if(degree1<=12&&degree1>6)
  {
  int a=1;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++; 
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,150);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
 
  
  if(degree1<=24&&degree1>18)
  {
  int a=2;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,150);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
 
  
  
  if(degree1<=36&&degree1>30)
  {
  int a=3;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1)  
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,200);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
 
  
  
  if(degree1<=48&&degree1>42)
  {
  int a=4;
   aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,200);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }

  
  
  if(degree1<=60&&degree1>54)
  {
  int a=5;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++; 
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,200);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }

  
  
  if(degree1<=72&&degree1>66)
  {
  int a=6;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,200);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
 
  
  
  if(degree1<=84&&degree1>78)
  {
  int a=7;
     aState1 = digitalRead(outputA);
   if (aState1 != aLastState1)
   {     
     if (digitalRead(outputB) != aState1) 
       counter1 ++;
     else 
       counter1 --;
     Serial.print("Position1: ");
     Serial.println(counter1);
   }
   aLastState1 = aState1; 
 
  if(counter1<a)
  {
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            analogWrite(6,200);
  }
  else if(counter1>a)
  {
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            analogWrite(6,100);
  }
  else if(counter1==a)
  {
          digitalWrite(4,LOW);
            digitalWrite(5,LOW);
            analogWrite(6,0);
  }
  }
}

{

  
  if(degree2<=6)
  {
  int b=0;
  {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,70);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,70);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }
  
  
  if(degree2<=12&&degree2>6)
  {
  int b=1;
  {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,150);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,150);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
 }
  }

  
  if(degree2<=24&&degree2>18)
  {
  int b=2;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,180);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,180);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }

  
  if(degree2<=36&&degree2>30)
  {
  int b=3;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,200);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,200);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }
  
  
  if(degree2<=48&&degree2>42)
  {
  int b=4;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2)  
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,255);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,255);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }
  
  
  if(degree2<=60&&degree2>54)
  {
  int b=5;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,200);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,200);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }

  
  if(degree2<=72&&degree2>66)
  {
  int b=6;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,200);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,200);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }

  
  if(degree2<=84&&degree2>78)
  {
  int b=7;
    {
   aState2 = digitalRead(outputC);
    if (aState2 != aLastState2)
     {
     if (digitalRead(outputD) != aState2) 
       counter2 ++;
     else 
       counter2 --;
     Serial.print("Position2: ");
     Serial.println(counter2);
   } 
   aLastState2 = aState2;
   if(counter2<b)
  {
            digitalWrite(10,HIGH);
            digitalWrite(11,LOW);
            analogWrite(9,200);
  }
  else if(counter2>b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
            analogWrite(9,100);
  }
  else if(counter2==b)
  {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
            analogWrite(9,0);
  }
  }
  }
}
while(Serial.available())
  {
    user();
  }
}


