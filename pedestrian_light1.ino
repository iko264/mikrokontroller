// C++ code
// 
const int pinMerahKendaraan = 13;
const int pinKuningKendaraan = 12;
const int pinHijauKendaraan = 11;
const int pinMerahPedKiri = 10;
const int pinHijauPedKiri = 9;
const int pinMerahPedKanan = 8;
const int pinHijauPedKanan = 7;
const int pinButton = 2; 

volatile bool request = false;

void setup() {
  for(int i=7; i<=13; i++) pinMode(i, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP); 
  statusAwal();
  attachInterrupt(digitalPinToInterrupt(pinButton), pencetTombol, FALLING);
}

void loop() {
  if (request) {
    prosesPenyeberangan();
    request = false; 
  }
}

// ISR 
void pencetTombol() {
  request = true;
}

void statusAwal() {
  digitalWrite(pinHijauKendaraan, HIGH);
  digitalWrite(pinMerahKendaraan, LOW);
  digitalWrite(pinKuningKendaraan, LOW);
  updatePedestrian(HIGH, LOW);
}

void updatePedestrian(int merah, int hijau) {
  digitalWrite(pinMerahPedKiri, merah);
  digitalWrite(pinMerahPedKanan, merah);
  digitalWrite(pinHijauPedKiri, hijau);
  digitalWrite(pinHijauPedKanan, hijau);
}

void prosesPenyeberangan() {
  digitalWrite(pinHijauKendaraan, LOW);
  for(int i=0; i<3; i++) {
    digitalWrite(pinKuningKendaraan, HIGH);
    delay(500);
    digitalWrite(pinKuningKendaraan, LOW);
    delay(500);
  }
  
  digitalWrite(pinKuningKendaraan, LOW);
  digitalWrite(pinMerahKendaraan, HIGH);
  updatePedestrian(LOW, HIGH);
  delay(10000); 
  
  updatePedestrian(HIGH, LOW);
  delay(1000);
  
  digitalWrite(pinMerahKendaraan, LOW);
  for(int i=0; i<3; i++) {
    digitalWrite(pinKuningKendaraan, HIGH);
    delay(500);
    digitalWrite(pinKuningKendaraan, LOW);
    delay(500);
  }
  
  statusAwal();
}
