//C++

// Konfigurasi Pin 
const int redPins[4] = {13, 10, 4, 7};
const int yellowPins[4] = {12, 9, 3, 6};
const int greenPins[4] = {11, 8, 2, 5};

const int timeDelay = 1000;

void setup() {
  inisialisasiSistem();
}

void loop() {
  for(int jalurAktif = 0; jalurAktif < 4; jalurAktif++) {
    resetLampuMerah();
    aktifkanJalur(jalurAktif);
    transisiKuning(jalurAktif);
  }
}

void inisialisasiSistem() {
  for(int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }
}

// Semua merah nyala lainnya mati
void resetLampuMerah() {
  for(int i = 0; i < 4; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }
}

//lampu hijau
void aktifkanJalur(int indeksJalur) {
  digitalWrite(redPins[indeksJalur], LOW);
  digitalWrite(greenPins[indeksJalur], HIGH);
  delay(5 * timeDelay);
}
//lampu kuning
void transisiKuning(int indeksJalur) {
  digitalWrite(greenPins[indeksJalur], LOW);
  
  //kedip 3 kali
  for(int blink = 0; blink < 3; blink++) {
    digitalWrite(yellowPins[indeksJalur], HIGH);
    delay(300);
    digitalWrite(yellowPins[indeksJalur], LOW);
    delay(300);
  }
  digitalWrite(yellowPins[indeksJalur], HIGH);
  delay(2 * timeDelay);
}