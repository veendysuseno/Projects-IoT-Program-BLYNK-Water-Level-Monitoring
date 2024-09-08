/* Projects IoT Program BLYNK Water Level Monitoring */

#define BLYNK_PRINT Serial
#include &lt;ESP8266WiFi.h&gt;
#include &lt;BlynkSimpleEsp8266.h&gt;
#define TRIGGERPIN D1 
#define ECHOPIN D2

char auth[] = "XXXX";                   // masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno";          //nama wifi
char pass[] = "Admin12345";             //password
WidgetLCD lcd(V1);

void setup() {
    Serial.begin(9600);
    pinMode(TRIGGERPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
    Blynk.begin(auth, ssid, pass);
    lcd.clear();
    lcd.print(0, 0, "Jarak dalam cm");
}

void loop() {
    lcd.clear();
    lcd.print(0, 0, "Jarak dalam cm");
    long duration, distance;
    digitalWrite(TRIGGERPIN, LOW);
    delayMicroseconds(3);
    digitalWrite(TRIGGERPIN, HIGH);
    delayMicroseconds(12);
    digitalWrite(TRIGGERPIN, LOW);
    duration = pulseIn(ECHOPIN, HIGH);
    distance = (duration / 2) / 29.1;
    Serial.print(distance);
    Serial.println("Cm");
    lcd.print(7, 1, distance);
    Blynk.run();
    delay(3500);
}
