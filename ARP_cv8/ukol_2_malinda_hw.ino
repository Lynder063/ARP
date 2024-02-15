// pripravek M8LED na portu BC

int pins[] = {A1, 11, 12, 13, A0, 8, 9, 10}; // vystupni piny v poradi v jakem se budou prochazet
unsigned char pos = 3;						 // aktualni  pozice

void setup()
{
	// nastaveni pinu jako vystupni
	for (int i = 0; i < 8; i++)
	{
		pinMode(pins[i], OUTPUT);
	}
}

void loop()
{
	// Nastavení zpoždění podle stavu vstupních pinů
	int delay_time = 0;
	if (digitalRead(16) == LOW && digitalRead(17) == LOW)
	{
		delay_time = 50;
	}
	else if (digitalRead(16) == LOW && digitalRead(17) == HIGH)
	{
		delay_time = 100;
	}
	else if (digitalRead(16) == HIGH && digitalRead(17) == LOW)
	{
		delay_time = 500;
	}
	else if (digitalRead(16) == HIGH && digitalRead(17) == HIGH)
	{
		delay_time = 1000;
	}

	digitalWrite(pins[pos], HIGH); // zhasnout LED
	if (++pos > 7)
		pos = 0;				  // posuv na dalsi pozici
	digitalWrite(pins[pos], LOW); // rozsvitit dalsi
	delay(delay_time);			  // cekani podle zvoleneho zpozdeni
}
