void setup() {
Serial.begin(9600); // inicializace s�riov� komunikace
}

void loop() {
if (Serial.available()) { // pokud jsou k dispozici vstupn� data
int n = Serial.parseInt(); // precten� vstupn�ho c�sla ze s�riov�ho portu
Serial.print(n);
Serial.print(" = ");

// rozklad c�sla na prvocinitele
bool first = true; // pro form�tov�n� v�stupu
for (int i = 2; i <= n; i++) {
  while (n % i == 0) {
    if (!first) {
      Serial.print("*");
    }
    Serial.print(i);
    n /= i;
    first = false;
  }
}

if (first) { // pokud nebyly nalezeny ��dn� prvoc�sla
  Serial.print("je prvocislo");
}

Serial.println();
}
}