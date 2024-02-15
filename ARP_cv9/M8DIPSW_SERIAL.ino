const int MAX_SIZE = 10;
int matrix[MAX_SIZE][MAX_SIZE];

void setup() {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	int size = 0;

	while (true) {
		Serial.print("Enter matrix size (3-10): ");
		while (!Serial.available());
		size = Serial.parseInt();
		if (size >= 3 && size <= MAX_SIZE) {
			break;
		}
		Serial.println("Invalid size!");
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = i * size + j;
		}
	}

	int minVal = matrix[0][0];
	int maxVal = matrix[0][0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] < minVal) {
				minVal = matrix[i][j];
			}
			if (matrix[i][j] > maxVal) {
				maxVal = matrix[i][j];
			}
		}
	}

	Serial.println("Matrix:");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Serial.print(matrix[i][j]);
			Serial.print('\t'); 
		}
		Serial.println();
	}

	Serial.print("Min: ");
	Serial.println(minVal);
	Serial.print("Max: ");
	Serial.println(maxVal);

	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	delay(1000);
}
