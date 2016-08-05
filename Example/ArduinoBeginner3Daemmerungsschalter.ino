/*
											***SatixCommunity***
										http://www.satixcommunity.de
Autor:     Felix
Beschreibung:	In diesem Programm bauen wir einen kleinen Dämmerungsschalter
				mit einem Fotowiderstand und einer LED.

Bei Fragen, Anregungen, oder Verbesserungsvorschlaegen schreibt einfach bei uns ins Forum,
oder meldet euch bei mir unter: felix@satixcommunity.de

Wenn ihr schnell mehr ueber Funktionen o.ae. wissen wollt, schaut einfach hier vorbei: https://www.arduino.cc/en/Reference/HomePage
*/


// Als erstes werden zwei Konstante Variablen erstellen,
// die für den Fotowiderstand und für die LED sind.
// Der Sensor wird an den Analogen Pin A0 angeschlossen,
const int sensor = A0;
// Die LED wird an einen Digitalen Pin angeschlossen.
const int led = 13;

// Ausserdem brauchen wir noch eine Variable,
// die den aktuellen Wert des Sensor's ausgibt.
int sensorValue;

void setup() 
{
	// Damit wir den Wert des Fotowiderstand überprüfen können,
	// werden wir ihn uns im Seriellen Monitor anzeigen lassen.
	Serial.begin(9600);
	
	// Wir setzen den Digitalen Pin (13) als Output,
	pinMode(led, OUTPUT);
}


void loop() 
{
	// Mit Hilfe der analogRead Funktion, speichern wir nun
	// immer den aktuellen Wert des Sensor in der Variable sensorValue.
	sensorValue = analogRead(sensor);
	Serial.println(sensorValue);

	// Wenn unser Sensor einen geringeren, oder gleich
	// den Wert 500 hat, wird die LED angehen.
	if (sensorValue <= 500)
	{
		digitalWrite(led, HIGH);
	}
	// Ansonsten geht sie aus.
	else
	{
		digitalWrite(led, LOW);
	}

	// Wir warten zwischen jeder Messung eine halbe Sekunde.
	delay(500);
}
