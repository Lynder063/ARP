int ledPin[] = {A1, 11, 12, 13, A0, 8, 9, 10}; // definice pinů pro LED
int switchPin = A3;                            // pin pro spínač

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(ledPin[i], OUTPUT); // nastavení pinů LED jako výstupy
  }
  pinMode(switchPin, INPUT_PULLUP); // nastavení pinu spínače jako vstup s interním pull-up rezistorem
}

void loop()
{
  if (digitalRead(switchPin) == LOW)
  { // pokud je spínač stisknut
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(ledPin[i], HIGH); // rozsvítí všechny LED
      delay(100);                    // počká 100 ms
      digitalWrite(ledPin[i], LOW);  // zhasne všechny LED
    }
  }
  else
  { // pokud spínač není stisknut
    for (int i = 7; i >= 0; i--)
    {                                // zmena smeru behu
      digitalWrite(ledPin[i], HIGH); // rozsvítí LED na pozici i
      delay(100);                    // počká 100 ms
      digitalWrite(ledPin[i], LOW);  // zhasne LED na pozici i
    }
  }
}
