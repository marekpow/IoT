#include <SoftwareSerial.h>
 
SoftwareSerial gsm(10,11);
 
String atCommand;
 
void setup()  
{
  
 
  // Ustawiamy transmisje na 9600 bodow Arduino--PC
  Serial.begin(9600);
 
  // Czekamy na inicjalizacje
  while (!Serial) {
  }
 
  // Ustawiamy transmisje na 9600 bodow SIMxxx-Arduino
  gsm.begin(9600);

  
}
 
void loop()
{
  // Jesli SIMxxx wysyla nam dane, odbieramy i wysylamy na port szeregowy
  if (gsm.available())
  {
    Serial.write(gsm.read());
  }
 
  // Odczytujemy nasze polecenie
  while (Serial.available())
  {
    delay(10);
    if (Serial.available() > 0)
    {
      char c = Serial.read();
      atCommand += c;
    }
  }
 
  // Jesli jest polecenie, wyslij do moduly GSM
  if (atCommand.length() > 0)
  {
    gsm.println(atCommand);
    atCommand = "";
  }  
}
