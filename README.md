# 🌡️ Sistem Monitoring Suhu & Kelembapan Otomatis dengan DHT11, LCD, dan Relay

Proyek ini adalah sistem monitoring suhu dan kelembapan berbasis **Arduino** yang menggunakan **sensor DHT11**, **LCD I2C**, dan **relay** untuk mengontrol pompa atau perangkat lain berdasarkan suhu. Cocok untuk **otomatisasi rumah**, **greenhouse**, atau **proyek IoT skala kecil**.

---

## 🎯 Fitur

- ✅ Membaca suhu & kelembapan secara real-time dengan sensor DHT11
- ✅ Menampilkan data ke LCD 16x2 via I2C
- ✅ Menyalakan **LED indikator suhu**
- ✅ Mengontrol **relay/pompa air** secara otomatis saat suhu tinggi
- ✅ Tampilan status "Pompa ON/OFF" di LCD

---

## 🧰 Komponen yang Digunakan

| Komponen             | Fungsi                                       |
|----------------------|----------------------------------------------|
| Arduino Uno / Nano   | Mikrokontroler utama                         |
| Sensor DHT11         | Membaca suhu dan kelembapan udara            |
| LCD 16x2 I2C (0x27)  | Menampilkan suhu, kelembapan, status pompa   |
| LED Hijau (D3)       | Menyala saat suhu < 30°C                     |
| LED Merah (D4)       | Menyala saat suhu ≥ 30°C                     |
| Relay (D7)           | Menghidupkan pompa jika suhu ≥ 30°C         |
| Breadboard & kabel   | Perakitan rangkaian                          |

---

## 🔌 Wiring / Skema Pin

| Komponen         | Pin Arduino |
|------------------|-------------|
| DHT11 Data       | D2          |
| LED Hijau        | D3          |
| LED Merah        | D4          |
| Relay            | D7          |
| LCD I2C SDA      | A4          |
| LCD I2C SCL      | A5          |
| VCC & GND        | 5V / GND    |

![skema sensor suhu](https://github.com/Luddinritonga/arduino-sensor-suhu/blob/main/skema%20sensor%20suhu.png)
---

## 🖥️ Tampilan di LCD
Suhu: 29.5 C<br>
Kelembapan: 60.0 %<br>
Pompa: ON / OFF<br>


> Pompa otomatis hidup jika suhu ≥ 30°C dan mati jika < 30°C

---

## 📦 Library yang Digunakan

Pastikan menginstal library berikut di Arduino IDE:

- [`DHT sensor library`](https://github.com/adafruit/DHT-sensor-library)
- `LiquidCrystal_I2C`
- `Wire` (bawaan Arduino IDE)

---

## ▶️ Cara Menggunakan

1. Rakit semua komponen sesuai tabel pin.
2. Upload kode `monitor_suhu.ino` ke board Arduino.
3. LCD akan menampilkan suhu, kelembapan, dan status pompa.
4. Pompa menyala otomatis jika suhu ≥ 30°C.
5. LED Merah menyala saat suhu tinggi, Hijau saat normal.

---

---

## 💡 Pengembangan Lanjutan

- Tambahkan buzzer saat suhu ekstrem (>40°C)
- Gunakan LCD 20x4 untuk tampilan lebih lengkap
- Simpan data ke SD Card atau kirim ke server IoT
- Gunakan sensor suhu & kelembapan yang lebih akurat seperti DHT22 atau BME280

---

## Author<br>
**Luddin ritonga**  <br>
[![Website](https://img.shields.io/badge/Website-000000?style=for-the-badge&logo=about-dot-me&logoColor=white)](https://yourwebsite.com)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/luddinritonga)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:luddinritonga03email.com)
[![YouTube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://youtube.com/@nama_channel_anda)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/username)


<!--[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://instagram.com/username)
[![Facebook](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://facebook.com/username)
[![Twitter/X](https://img.shields.io/badge/Twitter-000000?style=for-the-badge&logo=x&logoColor=white)](https://twitter.com/username)
[![Telegram](https://img.shields.io/badge/Telegram-0088cc?style=for-the-badge&logo=telegram&logoColor=white)](https://t.me/yourusername)-->


## 🪪 Lisensi

Proyek ini dilisensikan di bawah [MIT License](LICENSE)  
Bebas digunakan dan dimodifikasi untuk kebutuhan pribadi dan edukasi.


