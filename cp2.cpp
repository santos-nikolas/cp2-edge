#include <dht.h>
#include <LiquidCrystal.h>

 

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

 

#define LED_VERMELHO 8 
#define LED_AMARELO  7
#define LED_VERDE    6
#define BUZZER       9
#define LDR          A0
#define DHT      13

 

dht meu_dht;
 

 

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

 


void pinos ()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(BUZZER, OUTPUT);
}

 

 

void iluminacao()
{
  
// leitura do LDR 5 vezes:
  int somaLdr = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaLdr += analogRead(LDR);
    delay(1000);
  }
  
// calcula media dos dados:
  int mediaLdr = somaLdr / 5;
  
// iluminacao OK:
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
  
// iluminacao MEIA LUZ:  
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
  
// iluminacao MUITO CLARO:
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

 

 

 

 

 

 

 

void temp()
{
  
// leitura temperatura DHT 5 vezes:
  meu_dht.read11(DHT);
  temperatura = meu_dht.temperature;
  int somaTemp = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaTemp += meu_dht.temperature;
    delay(1000);
  }
  
// calcula media dos dados:
  int mediaTemp = somaTemp / 5;

 

 
// temperatura OK:
  if(mediaTemp >= 10 && mediaTemp <= 15)
  {
      lcd.setCursor(0,0);
      lcd.print("Temperatura OK  ");
      lcd.setCursor(0,1);
      lcd.print("Temp. =     C   ");
      lcd.setCursor(9,1);
      lcd.print(mediaTemp);
  }
  
// temperatura ALTA:
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

 

// temperatura BAIXA:
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

 

 

 

 

 

 

 

void umid()
{
  
// leitura umidade DHT 5 vezes:
  meu_dht.read11(DHT);
  umidade = meu_dht.humidity;
  int somaUmid = 0;
  for (int i = 0; i < 5; i++) 
  {  
    somaUmid += meu_dht.humidity;
    delay(1000);
  }

 

// alcula media dos dados:
  int mediaUmid = somaUmid / 5;
    

 

// umidade OK:
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
  
// umidade ALTA:
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
  
// umidade BAIXA:
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