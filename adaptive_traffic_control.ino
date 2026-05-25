#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Displays
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

// IR Sensors - Lane 1
const int ir1 = 13;
const int ir2 = 12;
const int ir3 = 14;

// IR Sensors - Lane 2
const int ir4 = 27;
const int ir5 = 26;
const int ir6 = 25;

// Lane 1 LEDs
const int red1 = 33;
const int yellow1 = 32;
const int green1 = 23;

// Lane 2 LEDs
const int red2 = 4;
const int yellow2 = 16;
const int green2 = 17;

void setup() {
  Serial.begin(115200);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);

  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  lcd1.init();
  lcd1.backlight();

  lcd2.init();
  lcd2.backlight();
}

int getLane1Density() {
  int count = 0;
  if (digitalRead(ir1) == LOW) count++;
  if (digitalRead(ir2) == LOW) count++;
  if (digitalRead(ir3) == LOW) count++;
  return count;
}

int getLane2Density() {
  int count = 0;
  if (digitalRead(ir4) == LOW) count++;
  if (digitalRead(ir5) == LOW) count++;
  if (digitalRead(ir6) == LOW) count++;
  return count;
}

void lane1Green(int timeSec) {
  digitalWrite(green1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, LOW);

  digitalWrite(red2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Lane 1 GREEN");

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Lane 2 RED");

  delay(timeSec * 1000);
}

void lane2Green(int timeSec) {
  digitalWrite(green2, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, LOW);

  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);

  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Lane 1 RED");

  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Lane 2 GREEN");

  delay(timeSec * 1000);
}

void loop() {
  int lane1 = getLane1Density();
  int lane2 = getLane2Density();

  Serial.print("Lane 1 Density: ");
  Serial.println(lane1);

  Serial.print("Lane 2 Density: ");
  Serial.println(lane2);

  if (lane1 > lane2) {
    lane1Green(10);
    lane2Green(5);
  }
  else if (lane2 > lane1) {
    lane2Green(10);
    lane1Green(5);
  }
  else {
    lane1Green(7);
    lane2Green(7);
  }
}