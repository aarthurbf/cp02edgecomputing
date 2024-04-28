# CHECKPOINT 02 EDGE COMPUTING

# Projeto de Monitoramento Ambiental com Arduino

## Link para o simulador:
<https://wokwi.com/projects/396430011841560577>

## Descrição do Projeto
Este projeto é um sistema de monitoramento ambiental construído com Arduino, projetado especificamente para vinícolas. O sistema lê a umidade, a temperatura e a luminosidade do ambiente, exibe essas informações em um display LCD e controla LEDs e um buzzer de acordo com essas leituras. O objetivo é manter a qualidade na produção dos vinhos, garantindo que as condições ambientais estejam sempre ideais.

## Como Funciona
O sistema utiliza um sensor DHT22 para medir a temperatura e a umidade, um sensor LDR para medir a luminosidade, e um display LCD para exibir as informações. Além disso, ele usa três LEDs (verde, laranja e vermelho) e um buzzer para indicar as condições do ambiente. A cada 5 segundos, o sistema lê os valores dos sensores e exibe as informações no display LCD. Ele também controla os LEDs e o buzzer de acordo com as leituras dos sensores.

## Componentes
Os componentes necessários para este projeto são:
* Arduino Uno
* Sensor DHT22
* Sensor LDR
* Display LCD 16x2
* LEDs (verde, laranja e vermelho)
* Buzzer

## Como Montar
1. Conecte o sensor DHT22 ao pino 2 do Arduino.
2. Conecte o sensor LDR ao pino A0 do Arduino.
3. Conecte o display LCD aos pinos 7, 8, 9, 10, 11 e 12 do Arduino.
4. Conecte os LEDs verde, laranja e vermelho aos pinos 3, 4 e 5 do Arduino, respectivamente.
5. Conecte o buzzer ao pino 6 do Arduino.

## Imagem do projeto
![imagem_2024-04-28_142434117](https://github.com/aarthurbf/cp02edgecomputing/assets/161460625/1c50b333-08d4-486d-9651-0cc4621bd1ca)

## Código
Aqui está o código Arduino usado neste projeto:
~~~arduino
  // Inclui as bibliotecas para o sensor DHT e o display LCD
#include <DHT.h>
#include <LiquidCrystal.h>

// Define os pinos para os sensores e dispositivos
#define DHTPIN 2
#define DHTTYPE DHT22
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
~~~

## Funcionamento Ambiental
Este projeto é ideal para vinícolas, pois monitora a temperatura, a umidade e a luminosidade do ambiente, que são fatores críticos para a produção de vinhos de alta qualidade. O sistema exibe as condições ambientais em um display LCD e usa LEDs e um buzzer para alertar quando as condições estão fora do ideal.

## Problemas Enfrentados
Um dos principais desafios deste projeto foi garantir que o sistema fosse capaz de ler com precisão os valores dos sensores e exibir as informações de forma clara e compreensível. Além disso, foi necessário garantir que o sistema pudesse operar continuamente e de forma confiável, dada a importância de manter as condições ambientais ideais para a produção de vinhos. Para superar esses desafios, foi necessário um cuidadoso planejamento e teste do sistema.
