// Inclui as bibliotecas para o sensor DHT e o display LCD
#include <DHT.h>
#include <LiquidCrystal.h>

// Define os pinos para os sensores e dispositivos
#define DHTPIN 13
#define DHTTYPE DHT11
#define LDRPIN A0
#define LED_VERDE 3
#define LED_LARANJA 4
#define LED_VERMELHO 5
#define BUZZER 6

// Cria uma instância do sensor DHT e do display LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Configura os pinos dos LEDs e do buzzer como saída
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_LARANJA, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Inicia o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Inicia o sensor DHT
  dht.begin();

  // Exibe a mensagem inicial
  lcd.setCursor(0, 0);
  lcd.print("NCREATIVE");
  delay(2000); // Atraso de 2 segundos

  // Apaga a mensagem em forma de animação
  for (int posicao = 0; posicao < 9; posicao++) {
    lcd.setCursor(posicao, 0);
    lcd.print(" "); // Substitui cada caractere por um espaço
    delay(500); // Atraso de 0.5 segundo para a animação
  }
}

void loop() {
  // Adiciona um atraso para dar tempo ao DHT22 para fornecer uma leitura
  delay(2000);

  // Lê a umidade e a temperatura do sensor DHT
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  // Lê a luminosidade do sensor LDR e mapeia o valor para um intervalo de 0 a 100
  int luz = analogRead(LDRPIN);
  luz = map(luz, 0, 1023, 0, 100);

  // Exibe a luminosidade no display LCD e controla os LEDs e o buzzer de acordo com a luminosidade
  lcd.clear();
  if (luz < 30) {
    lcd.print("Ambiente escuro");
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
  } else if (luz >= 30 && luz < 70) {
    lcd.print("Ambiente a meia");
    lcd.setCursor(0, 1);
    lcd.print("Luz");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
  } else {
    lcd.print("Ambiente muito");
    lcd.setCursor(0, 1);
    lcd.print("Claro");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  delay(5000);

  // Exibe a temperatura no display LCD e controla os LEDs e o buzzer de acordo com a temperatura
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1); // Move o cursor para a segunda linha
  if (temp >= 10 && temp <= 15) {
    lcd.print("Temp. OK");
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
  } else if (temp > 15) {
    lcd.print("Temp. Alta");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    lcd.print("Temp. Baixa");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  delay(5000);

  // Exibe a umidade no display LCD e controla os LEDs e o buzzer de acordo com a umidade
  lcd.clear();
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print(" %");
  lcd.setCursor(0, 1); // Move o cursor para a segunda linha
  if (hum >= 50 && hum <= 70) {
    lcd.print("Umidade. OK");
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, LOW);
  } else if (hum > 70) {
    lcd.print("Umidade. Alta");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    lcd.print("Umidade. Baixa");
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_LARANJA, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  delay(5000);
}
