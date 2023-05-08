//Adicionando as bibliotecas
#include <dht.h>
#include <LiquidCrystal.h>

//Pinos utilizados para controlar o lcd
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

//Definindo as portas
#define LED_VERMELHO 8 
#define LED_AMARELO  7
#define LED_VERDE    6
#define BUZZER       9
#define LDR          A0
#define DHT      13

dht meu_dht;

//Definindo Variáveis 
float temperatura = 0;
float umidade = 0;

void setup()
{
  pinos();
  lcd.begin(16,2);              
  lcd.clear();                        
  Serial.begin(9600);
} 

void loop()
{
  iluminacao();
  temp();
  umid();
} 

//Criando uma função para controlar os pinos
void pinos ()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUZZER, OUTPUT);
}

//Criando uma função para controlar a iluminação 
void iluminacao()
{
  
//Leitura do LDR 5 vezes em 5 segundos:
  int somaLdr = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaLdr += analogRead(LDR);
    delay(1000);
  }
  
//Calcula média dos dados:
  int mediaLdr = somaLdr / 5;
  
//Iluminação OK:
  if(mediaLdr < 105)
  {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente               ");
    lcd.setCursor(0,1);
    lcd.print("OK                  ");
    digitalWrite(BUZZER, LOW);
  }
  
//Iluminação MEIA LUZ:  
  else if (mediaLdr >= 105 && mediaLdr <= 210) 
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente a           ");
    lcd.setCursor(0,1);
    lcd.print("MEIA LUZ                ");
  }
  
//Iluminação MUITO CLARO:
    else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente             ");
    lcd.setCursor(0,1);
    lcd.print("MUITO CLARO         ");
  }
    Serial.println(mediaLdr);
}

//Criando uma variável para controlar a temperatura 
void temp()
{
  
//Leitura temperatura DHT 5 vezes em 5 segundos:
  meu_dht.read11(DHT);
  temperatura = meu_dht.temperature;
  int somaTemp = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaTemp += meu_dht.temperature;
    delay(1000);
  }
  
//Calcula media dos dados:
  int mediaTemp = somaTemp / 5;

//Temperatura OK:
  if(mediaTemp >= 10 && mediaTemp <= 15)
  {
      lcd.setCursor(0,0);
      lcd.print("Temperatura OK  ");
      lcd.setCursor(0,1);
      lcd.print("Temp. =     C   ");
      lcd.setCursor(9,1);
      lcd.print(mediaTemp);
  }
  
//Temperatura ALTA:
  else if(mediaTemp > 15)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temp. ALTA      ");
    lcd.setCursor(0,1);
    lcd.print("Temp. =     C   ");
    lcd.setCursor(9,1);
    lcd.print(mediaTemp);
  }

//Temperatura BAIXA:
  else 
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Temp. BAIXA     ");
    lcd.setCursor(0,1);
    lcd.print("Temp. =     C   ");
    lcd.setCursor(9,1);
    lcd.print(mediaTemp);
  }
  Serial.println(mediaTemp);
}

//Criando uma variável para controlar a umidade 
void umid()
{
  
//Leitura umidade DHT 5 vezes em 5 segundos:
  meu_dht.read11(DHT);
  umidade = meu_dht.humidity;
  int somaUmid = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaUmid += meu_dht.humidity;
    delay(1000);
  }
//Calcula media dos dados:
  int mediaUmid = somaUmid / 5;

//Umidade OK:
  if(mediaUmid >= 50 && mediaUmid <= 70)
  {
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_AMARELO, LOW);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(BUZZER, LOW);
      lcd.setCursor(0,0);
      lcd.print("Umidade OK      ");
      lcd.setCursor(0,1);
      lcd.print("Umid. =     %   ");
      lcd.setCursor(9,1);
      lcd.print(mediaUmid);
  }
  
//Umidade ALTA:
  else if(mediaUmid > 70)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Umid. ALTA      ");
    lcd.setCursor(0,1);
    lcd.print("Umid. =     %   ");
    lcd.setCursor(9,1);
    lcd.print(mediaUmid);
  }
  
//Umidade BAIXA:
  else 
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(BUZZER, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Umid. BAIXA     ");
    lcd.setCursor(0,1);
    lcd.print("Umid. =     %   ");
    lcd.setCursor(9,1);
    lcd.print(mediaUmid);
  }
  Serial.println(mediaUmid);
}
