#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Tentukan pin dan jenis sensor DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Inisialisasi LCD dengan alamat I2C (0x27) dan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Tentukan pin untuk LED
#define LED_HIJAU 3
#define LED_MERAH 4

// Tentukan pin untuk relay
#define RELAY_PIN 7

void setup() {
  // Mulai komunikasi serial
  Serial.begin(9600);
  dht.begin();  // Mulai sensor DHT11
  
  // Inisialisasi LCD
  lcd.begin(16, 2);
  lcd.backlight();  // Nyalakan lampu latar LCD
  lcd.setCursor(0, 0);  // Atur kursor di baris pertama
  lcd.print("Suhu & Kelembapan");

  // Inisialisasi pin LED
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  // Inisialisasi pin relay untuk mengendalikan pompa
  pinMode(RELAY_PIN, OUTPUT);

  // Matikan LED dan relay (pompa mati) saat pertama kali
  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(RELAY_PIN, LOW);  // Pompa mati
}

void loop() {
  // Membaca kelembapan
  float kelembapan = dht.readHumidity();
  // Membaca suhu dalam Celcius
  float suhu = dht.readTemperature();

  // Cek jika pembacaan gagal
  if (isnan(kelembapan) || isnan(suhu)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gagal membaca");
    lcd.setCursor(0, 1);
    lcd.print("DHT11!");
    return;
  }

  // Menampilkan suhu dan kelembapan di LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: ");
  lcd.print(kelembapan);
  lcd.print(" %");

  // Kontrol LED berdasarkan suhu
  if (suhu >= 30) {
    // LED Merah nyala jika suhu >= 30
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    
    // Nyalakan pompa jika suhu >= 30
    digitalWrite(RELAY_PIN, HIGH);  // Pompa hidup
    lcd.setCursor(0, 1);
    lcd.print("Pompa: ON  ");
  } else {
    // LED Hijau nyala jika suhu < 30
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(LED_MERAH, LOW);
    
    // Matikan pompa jika suhu < 30
    digitalWrite(RELAY_PIN, LOW);  // Pompa mati
    lcd.setCursor(0, 1);
    lcd.print("Pompa: OFF ");
  }

  // Delay 2 detik sebelum pembacaan berikutnya
  delay(2000);
}
