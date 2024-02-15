#include "Native_LiquidCrystal.h"
#include "math.h"
/* Definice komunikacnich pinu. Zde je potreba dat pozor na datove piny, protoze UnoArduSim
ma pouze jedno okenko pro nejnizsi dat. pin (DB4) a potom bere, ze dalsi tri nasledujici piny jsou DB5, DB6 a DB7.
   Take je mozne vynechat pin R/W - coz delam, proto?e muj realny displej ho ma natvrdo na GND.
*/
#define RS_PIN 7
#define EN_PIN 6
#define D4_PIN 2
#define D5_PIN 3
#define D6_PIN 4
#define D7_PIN 5

Native_LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup()
{
	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
	lcd.print("Kvadraticke rovnice:");
	lcd.setCursor(0, 1);
	lcd.print("Malinda Krystof");
	Serial.begin(9600);
}
void loop()
{
	static int state = 0;
	static float a, b, c, x1, x2, d;

	if (state == 0)
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Zadej A:");
		Serial.println("Zadej A:");
		while (Serial.available() == 0)
		{
			// wait for user input
		}
		a = Serial.parseFloat();
		state = 1;
	}
	else if (state == 1)
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Zadej B:");
		Serial.println("Zadej B:");
		while (Serial.available() == 0)
		{
		}
		b = Serial.parseFloat();
		state = 2;
	}
	else if (state == 2)
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Zadej C:");
		Serial.println("Zadej C:");
		while (Serial.available() == 0)
		{
		}
		c = Serial.parseFloat();
		state = 3;
	}
	else if (state == 3)
	{
		lcd.clear();
		d = b * b - 4 * a * c;
		if (d < 0)
		{
			Serial.println("Kvadratická rovnice nemá reálné koreny");
		}
		else if (d == 0)
		{
			x1 = x2 = -b / (2 * a);
			Serial.print("Kvadratická rovnice má jeden koren: ");
			Serial.println(x1);
		}
		else
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			Serial.print("Kvadratická rovnice má dva koreny: ");
			Serial.print(x1);
			Serial.print(", ");
			Serial.println(x2);
		}
		state = 0;
	}
}