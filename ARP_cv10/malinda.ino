#include "Native_LiquidCrystal.h"
/* Definice komunikacnich pinu. Zde je potreba dat pozor na datove piny, protoze UnoArduSim
ma pouze jedno okenko pro nejnizsi dat. pin (DB4) a potom bere, ze dalsi tri nasledujici piny jsou DB5, DB6 a DB7.
   Take je mozne vynechat pin R/W - coz delam, proto�e muj realny displej ho ma natvrdo na GND.
*/
#define RS_PIN   7
#define EN_PIN   6
#define D4_PIN   2
#define D5_PIN   3
#define D6_PIN   4
#define D7_PIN   5
/* Instance lcd displeje, podle toho jakou si vyberu knihovnu */
Native_LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
/* Init displeje */
	lcd.begin(16, 2);
/* Tohle tu musi byt
lcd.setCursor(0, 0);
/* Staticky vypis */
	lcd.print("Hi there");   //vypis textu na prvn� ��dek
	lcd.setCursor(0, 1);	
	lcd.print("Cheers!");    //v�pis textu na druh� ��dek
	Serial.begin(9600);      //inicializace s�riov� linky
	Serial.println("Zadej text:"); //zasl�n� uv�tac� zpr�vy do termin�lu

}
void loop() {
	if(Serial.available())
	{	//kontrola zda je neco poslano
		String msg = Serial.readString();  //nacteni textu
		msg.trim();                        //oriznuti delicich znaku (\r \n)
		lcd.clear();                       //vymazani displeje
		lcd.setCursor(0, 0);
		lcd.print(msg);                    //vypis textu
	}

}
