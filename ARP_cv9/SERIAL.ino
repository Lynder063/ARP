void setup() {
Serial.begin(9600); // inicializace sériové komunikace
}

void loop() {
if (Serial.available()) { // pokud jsou k dispozici vstupní data
int n = Serial.parseInt(); // prectení vstupního císla ze sériového portu
Serial.print(n);
Serial.print(" = ");

// rozklad císla na prvocinitele
bool first = true; // pro formátování výstupu
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

if (first) { // pokud nebyly nalezeny žádné prvocísla
  Serial.print("je prvocislo");
}

Serial.println();
}
}