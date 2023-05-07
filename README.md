# Checkpoint 2 - Edge Computing
## Medidor de temperatura, umidade e luminosidade
### Integrantes do grupo:
* Nikolas Rodrigues Moura dos Santos RM: 551566
* Pedro Henrique Pedrosa Tavares RM: 97877
* Thiago Jardim De Oliveira RM: 551624
* Guilherme Rocha Bianchini RM: 97974
### Descrição do Código
Este código, desenvolvido para o microcontrolador Arduino, utiliza um sensor de temperatura e umidade DHT11, juntamente com um sensor de luz LDR e um display LCD. Ele monitora as condições ambientais (temperatura, umidade e iluminação) e exibe informações relevantes no display LCD. Além disso, utiliza LEDs e um buzzer para fornecer indicações visuais e sonoras com base nas condições medidas.
### Materiais utilizados:
* 1 arduíno UNO R3
* 1 protoboard
* 25 jumper cables
* 5 resistores de 220 ohms
* 3 leds (um vermelho, um amarelo e um verde)
* 1 sensor LDR
* 1 sensor DHT11
* 1 display LCD 16:2
* 1 buzzer (piezo)
### Pinagem
* Pino 8: LED vermelho
* Pino 7: LED amarelo
* Pino 6: LED verde
* Pino 9: Buzzer
* Pino A0: LDR
* Pino 12: LCD (RS)
* Pino 11: LCD (E)
* Pino 10: LCD (D4)
* Pino 5: LCD (D5)
* Pino 4: LCD (D6)
* Pino 3: LCD (D7)
* Pino 2: LCD (LED+)
### Funções
* setup(): Configura os pinos e inicializa o display LCD.
* loop(): Executa repetidamente as funções iluminacao(), temp() e umid() para monitorar continuamente as condições ambientais.
* pinos(): Configura os pinos dos LEDs, buzzer e LDR.
* iluminacao(): Realiza a leitura do sensor de luz LDR e determina a intensidade da iluminação ambiente com base na média dos valores lidos. Aciona os LEDs e exibe mensagens no display LCD de acordo com a intensidade medida.
* temp(): Realiza a leitura do sensor de temperatura DHT11 e determina a temperatura ambiente com base na média dos valores lidos. Aciona os LEDs, buzzer e exibe mensagens no display LCD de acordo com a temperatura medida.
* umid(): Realiza a leitura do sensor de umidade DHT11 e determina a umidade ambiente com base na média dos valores lidos. Aciona os LEDs, buzzer e exibe mensagens no display LCD de acordo com a umidade medida.
