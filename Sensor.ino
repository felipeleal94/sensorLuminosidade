
int sensorPin = A0;                    //Inicializa o sensor no pino A0
int ledPin = 9;                        //Inicializa o Led no pino 9
unsigned long StartMillis = 0; 

void setup() {
pinMode (ledPin, OUTPUT);               //Define o pino do Led como Saída
  Serial.begin(9600);                  //Configura a taxa de comunicação em bits por segundo (baud rate). 
  }
void loop() {

  float tensao = 0;                     //Define a variavel tensão como float
  int sensorValue = 0;                   //Define o valor do sensor como int
  
sensorValue = analogRead(sensorPin);     //A variavel sensorValue recebe o valor  lido em sensorPin
WaitMillis(sensorValue);
if (sensorValue < 700){                  //Caso o sensorValue seja menor que 700 executar o código abaixo
  digitalWrite(ledPin, HIGH);            //Define o estado do led como HIGH
  Serial.print("Canal: ");
  Serial.println(sensorValue);          //imprime o valor a variavel sensorValue, neste caso é o valor do nosso canal
  tensao = CalculaTensao(sensorValue);
  Serial.print("Valor de Tensao: ");
  //Serial.println(tensao);              //Imprime o valor de tensão
  Serial.println("");
  } if (sensorValue > 700){           //Caso o sensor Value seja maior que 700 executar o código abaixo
    digitalWrite(ledPin, LOW);        //Define o estado do led como LOW
  Serial.print("Canal: ");
  Serial.println(sensorValue);//imprime o valor a variavel sensorValue, neste caso é o valor do nosso canal
  tensao = CalculaTensao(sensorValue);
  Serial.print("Valor de Tensao: ");
  //Serial.print(tensao);//Imprime o valor de tensão
  Serial.println("");
    }
}

void WaitMillis(int sensorValue) { //função para definir um intervalo de tempo
StartMillis = millis();
  
do
{
} while (millis() - StartMillis < sensorValue);
return;
}
float CalculaTensao(float sensorValue) { //função para definir a valor da tensão
float x; 
x = sensorValue*5/1023;
return x;
}
