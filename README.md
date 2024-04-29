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

## Funcionamento Ambiental
Este projeto é ideal para vinícolas, pois monitora a temperatura, a umidade e a luminosidade do ambiente, que são fatores críticos para a produção de vinhos de alta qualidade. O sistema exibe as condições ambientais em um display LCD e usa LEDs e um buzzer para alertar quando as condições estão fora do ideal.

## Problemas Enfrentados
Um dos principais desafios deste projeto foi garantir que o sistema fosse capaz de ler com precisão os valores dos sensores e exibir as informações de forma clara e compreensível. Além disso, foi necessário garantir que o sistema pudesse operar continuamente e de forma confiável, dada a importância de manter as condições ambientais ideais para a produção de vinhos. Para superar esses desafios, foi necessário um cuidadoso planejamento e teste do sistema.
