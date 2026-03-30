# 🚦 Smart 4-Way Traffic Light System 

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Tinkercad](https://img.shields.io/badge/Tinkercad-0055B8?style=for-the-badge&logo=autodesk&logoColor=white)

> Sistem otomasi lampu lalu lintas 4 arah berbasis mikrokontroler Arduino Uno. Proyek ini mendemonstrasikan efisiensi manajemen memori dan arsitektur *Clean Code* menggunakan C++ dalam simulasi perangkat keras.

---

## Simulasi

<img width="633" height="542" alt="tugas 4" src="https://github.com/user-attachments/assets/4b4bc9a8-ce44-40f5-8197-6a917a58a2d0" />


## ⚙️ Arsitektur Sistem & Fitur Utama

Sistem ini tidak dibangun menggunakan instruksi linier dasar, melainkan menggunakan pendekatan rekayasa perangkat lunak yang terstruktur:
* **Modularization:** Pemisahan logika program ke dalam modul-modul fungsi independen (`inisialisasiSistem`, `resetLampuMerah`, `aktifkanJalur`, `transisiKuning`) untuk memudahkan *debugging* dan skalabilitas.
* **Array Optimization:** Penggunaan struktur data *Array 2D* untuk mengelompokkan pin I/O, secara drastis mengurangi baris kode repetitif dan menghemat alokasi memori pada *chip* ATmega328P.
* **Overcurrent Protection:** Implementasi desain sirkuit dengan resistor pada setiap LED untuk mencegah kelebihan arus (simulasi batas aman < 40mA per pin).
* **Dynamic Transition:** Dilengkapi dengan algoritma sub-looping untuk menciptakan efek lampu kuning berkedip (*blinking*) sebagai peringatan sebelum penutupan jalur.

## 🧰 Bill of Materials (BOM)

| Komponen | Spesifikasi / Tipe | Jumlah | Fungsi |
| :--- | :--- | :---: | :--- |
| **Microcontroller** | Arduino Uno R3 | 1 | Unit pemrosesan logika utama |
| **Breadboard** | Small / Half+ | 1 | Papan sirkuit prototipe |
| **LED** | Merah, Kuning, Hijau | 12 | Indikator visual lalu lintas |
| **Resistor** | 220 Ω / 330 Ω | 12 | Pembatas arus listrik (*current limiter*) |
| **Jumper Wires** | Male-to-Male | Secukupnya | Penghubung rute kelistrikan |

## 🔌 Skema Rangkaian (Schematic)

*[Letakkan Screenshot Schematic View dari Tinkercad di sini. Contoh: `![Schematic](link-gambar.png)`]*

**Konfigurasi Pin Mapping:**
* **Jalur Kiri:** Merah (13), Kuning (12), Hijau (11)
* **Jalur Atas:** Merah (10), Kuning (9), Hijau (8)
* **Jalur Kanan:** Merah (4), Kuning (3), Hijau (2)
* **Jalur Bawah:** Merah (7), Kuning (6), Hijau (5)

## 🚀 Instalasi & Penggunaan

1.  Kloning repositori ini ke dalam mesin lokal Anda:
    ```bash
    git clone [https://github.com/username-anda/smart-traffic-light.git](https://github.com/username-anda/smart-traffic-light.git)
    ```
2.  Buka file `traffic_light.ino` menggunakan Arduino IDE atau salin kodenya ke panel *Code* di sirkuit Tinkercad Anda.
3.  Pastikan rangkaian perangkat keras sudah sesuai dengan *Pin Mapping* di atas.
4.  Lakukan *Compile* dan *Upload* program ke *board* Arduino.

---

### 👨‍💻 Tentang Pengembang
**Hammed Jastiko Apuranam** *Mahasiswa Teknik Komputer, Universitas Jenderal Soedirman*

Sistem ini dikembangkan sebagai bentuk eksplorasi mendalam terhadap manajemen I/O digital dan arsitektur kode mikrokontroler. Jika Anda memiliki masukan untuk optimasi lebih lanjut (seperti penerapan *Direct Port Manipulation* atau *Bitmasking*), silakan buat *Pull Request*.
