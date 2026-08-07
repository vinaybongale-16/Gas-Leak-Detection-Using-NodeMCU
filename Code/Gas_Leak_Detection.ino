/***************************************************
 * NodeMCU Gas Leak Detection + DC Fan (Relay) Code
 * - ESP8266 (NodeMCU)
 * - MQ sensor on A0
 * - LED on D3
 * - Buzzer on D6
 * - Servo on D4 (valve)
 * - Relay (fan) on D5
 * - I2C LCD at 0x27
 *
 * NOTE:
 * - Relay VCC -> 5V, Relay GND -> common GND, Relay IN -> D5
 * - Fan + -> Relay NO, Fan - -> 5V power GND (common with NodeMCU GND)
 * - Use external 5V supply for fan and servo (common ground)
 ***************************************************/

// ====== Blynk 2.0 Required Definitions ======
#define BLYNK_TEMPLATE_ID "TMPL3ugMD3YQQ"
#define BLYNK_TEMPLATE_NAME "gas sensor"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// ====== Wi-Fi Credentials ======
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ====== Pin Definitions ======
#define MQ_PIN A0
#define LED_PIN D3
#define BUZZER_PIN D6
#define SERVO_PIN D4
#define FAN_RELAY_PIN D5    // Relay input to control fan (NO/COM wiring on relay)
#define LCD_ADDRESS 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

// ====== Objects ======
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
Servo gasServo;

// ====== Variables ======
int gasLevel = 0;
int threshold = 550;    // adjust after calibration
bool fanState = false;  // track fan state (true = ON)

// ====== Optional: allow threshold control from Blynk (V2) ======
BLYNK_WRITE(V2) {
  threshold = param.asInt();
}

void setup() {
  Serial.begin(9600);

  // LCD
  lcd.init();
  lcd.backlight();

  // Pin modes
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);

  // Initialize outputs: assume relay turns ON with HIGH (if your relay is active LOW,
  // invert the logic: use HIGH for OFF and LOW for ON)
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(FAN_RELAY_PIN, LOW); // Fan OFF initially (set to LOW -> relay inactive)

  // Servo
  gasServo.attach(SERVO_PIN);
  gasServo.write(0); // Valve open

  // Connect to Blynk (will block until connected)
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Startup display
  lcd.setCursor(0,0);
  lcd.print("Gas Leak System");
  lcd.setCursor(0,1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {
  Blynk.run();

  // Read gas sensor
  gasLevel = analogRead(MQ_PIN);
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  // Send to Blynk gauge (V0) and show state (V1)
  Blynk.virtualWrite(V0, gasLevel);
  Blynk.virtualWrite(V1, fanState ? 1 : 0);

  // Update LCD (top row)
  lcd.setCursor(0,0);
  lcd.print("Gas: ");
  lcd.print(gasLevel);
  // clear remaining chars in row (simple)
  lcd.print("      ");

  // Gas leak logic
  if (gasLevel > threshold) {
    // Leak detected
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(FAN_RELAY_PIN, HIGH); // Turn fan ON via relay
    gasServo.write(90);               // Close valve
    fanState = true;

    lcd.setCursor(0,1);
    lcd.print("Leak! Fan ON     ");
  } else {
    // Normal
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(FAN_RELAY_PIN, LOW);  // Turn fan OFF
    gasServo.write(0);                 // Open valve
    fanState = false;

    lcd.setCursor(0,1);
    lcd.print("System Normal    ");
  }

  delay(1000);
}
