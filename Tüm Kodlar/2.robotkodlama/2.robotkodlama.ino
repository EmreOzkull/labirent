#include <Servo.h>

Servo servo1;  // servo larımızı isimlendiriyoruz
Servo servo2;

int okunandeger1 ; // joistik den gelen verilerin kaydedilçeği değişkenler 
int okunandeger2 ;

int potpin1 = A0;  // joistik modülünün çıkış sinyallerinin baglı oldugu pinler
int potpin2 = A1; 
 
int buton   = 5;    

void setup() {
  Serial.begin (9600);
  servo1.attach  (9); // servolarımızın sinyal pinin baglı olduğu pinleri çalıştırıyoruz
  servo2.attach (10);
}

void loop() {
 
  
  okunandeger1 = analogRead(potpin1);            // joistikden gelen verileri okuyup okunandeger1 adlı degişkene kaydediyoruz
  okunandeger1 = map(okunandeger1, 0, 1023, 32, 62);     // joistik den gelen 0 ila 1023 arasındakı degeri 0 ila 60 a orantılıyoruz.
  servo1.write(okunandeger1);           // orantıladıgımız değeri servomuza gönderip servoyu çalıştırıyoruz
  Serial.println (okunandeger1);  // servoya gönderdiğimiz degeri serial monitörde görüyoruz
  
  okunandeger2 = analogRead(potpin2);            
  okunandeger2 = map(okunandeger2, 0, 1023, 70, 100);     
  servo2.write(okunandeger2);
  Serial.println (okunandeger2);
  delay(30);                           
}
