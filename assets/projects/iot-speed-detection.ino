#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 🔥 เปลี่ยนเป็น 0x3F ถ้าไม่ขึ้น
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== Ultrasonic Sensor 1 =====
#define trigPin1 4
#define echoPin1 5

// ===== Ultrasonic Sensor 2 =====
#define trigPin2 2
#define echoPin2 3

// ===== LED + Buzzer =====
#define LED_GREEN 8
#define LED_YELLOW 9
#define LED_RED 10
#define BUZZER 11

// ===== ค่าระบบ =====
float threshold = 30;         // ระยะ detect (cm)
float sensorDistance = 2.0;   // ระยะห่างระหว่าง Sensor 2 ตัว (เมตร)

// ===== เวลา =====
unsigned long startTime = 0;
unsigned long endTime = 0;

// ===== สถานะ =====
bool firstDetected = false;

// ===== อ่านระยะแบบนิ่ง (กันค่าเด้ง) =====
long readDistance(int trigPin, int echoPin) {
  long sum = 0;

  for (int i = 0; i < 5; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);
    long distance = duration * 0.034 / 2;

    if (distance == 0) distance = 999;

    sum += distance;
    delay(5);
  }

  return sum / 5;
}

void setup() {
  Serial.begin(115200);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Speed Meter");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  delay(1500);

  lcd.clear();
}

void loop() {
  long distance1 = readDistance(trigPin1, echoPin1);
  long distance2 = readDistance(trigPin2, echoPin2);

  Serial.print("D1: ");
  Serial.print(distance1);
  Serial.print(" | D2: ");
  Serial.println(distance2);

  // ===== Sensor 1 เริ่มจับเวลา =====
  if (distance1 < threshold && !firstDetected) {
    firstDetected = true;
    startTime = millis();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("START DETECT");
    Serial.println("START");
  }

  // ===== Sensor 2 หยุดจับเวลา =====
  if (distance2 < threshold && firstDetected) {
    endTime = millis();

    float timeSec = (endTime - startTime) / 1000.0;
    if (timeSec <= 0) return;

    float speed = sensorDistance / timeSec;
    float speedKmH = speed * 3.6;

    // กันค่ามั่ว
    if (speedKmH < 1 || speedKmH > 200) {
      firstDetected = false;
      return;
    }

    // ปิดไฟก่อน
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Speed:");
    lcd.print(speedKmH, 1);
    lcd.print("km/h");

    if (speedKmH <= 20) {
      digitalWrite(LED_GREEN, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Safe");
      noTone(BUZZER);
    }
    else if (speedKmH <= 40) {
      digitalWrite(LED_YELLOW, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Slow Down");
      tone(BUZZER, 1000, 200);
    }
    else if (speedKmH <= 60) {
      digitalWrite(LED_RED, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Warning!");
      tone(BUZZER, 1500, 300);
    }
    else {
      lcd.setCursor(0, 1);
      lcd.print("OVER SPEED!");

      for (int i = 0; i < 5; i++) {
        digitalWrite(LED_RED, HIGH);
        tone(BUZZER, 2000);
        delay(200);

        digitalWrite(LED_RED, LOW);
        noTone(BUZZER);
        delay(200);
      }
    }

    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Waiting...");

    firstDetected = false;
  }
}