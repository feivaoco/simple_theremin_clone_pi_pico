# Pi Pico Theremin Simple
### Un clon del theremín bien simple hecho con la Pi Pico y dos sensores ultrasonicos


## Resumen
El proyecto trata sobre el uso de la Pi Pico para detectar la distancia de los sensores ultrasonicos y utilizar esos datos en el programa Pure Data para hacer un sintetizador.

## Introducción
Un Sensor Ultrasonico funciona como de que manda un sonido ultrasonico por una de sus bocinitas y la segunda bocinita capta cuando ese sonido que se lanzó choca con algo. Cuenta con dos transductores, uno para enviar y otro para recibir, el que envía manda un señal de 40khz en línea recta, y antes de mandar esas señales el pin trigger recibe la suya y se apaga para mandar las señales sonicas, en cuanto estas señales sonicas se mandan el pin de echo se activa hasta que el transductor que recibe los rebotes obtenga la señal sonica de regreso, es ahí cuando el pin de echo se apaga y desupés todo se repite. De momento nada es MIDI pero ya pronto, ya que con la investigación realizada durante este proyecto pude encontrar un librería para el Arduino IDE y es muy sencillo de usar, nada más falta entenderle. Pure Data y para programar a la Pi Pico ya se ha utilizado en un proyecto anterior.

## Desarrollo
### Circuito
Había visto que usaban dos resistencias en el pin de TRIGGER por alguna razón pero en otros circuitos no, así que lo hice sin resistencias y pues todo sirvió.
![circuito](/imgs/circuito.drawio.png)
Como siempre, el circuito lo hice en el drawio porque no encuentro otro programa así más simple con el que pueda dibujarlos, además de que me permite hacer figuras personalizadas, nada más me falta aprender a hacer conexiones personalizadas, jeje.
### Código Arduino IDE
Hay casos en el que creo que no podré poner todo el codígo, tengo que ver como hacer que solamente sea una ventanita el codígo y que no abarque todo.
```arduino
int trigPin = 15;    // Trigger
int echoPin = 14;    // Echo
long duration, cm, inches;

int trigPin2 = 17;    // Trigger
int echoPin2 = 16;    // Echo
long duration2, cm2, inches2;

void setup() {
  //Serial Port begin
  Serial.begin (115200);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}
 
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // cm = (duration/2) / 29.1;     
  inches = (duration/2) / 74;  
  

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 

  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  // cm2 = (duration2/2) / 29.1;     
  inches2 = (duration2/2) / 74;  
  Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm | ");
  Serial.print(" ");

  Serial.print(inches2);
  // Serial.print("in, ");
  // Serial.print(cm2);
  // Serial.print("cm");
  
  Serial.println();
  
  delay(5);
}
```
### Parches de Pure Data
Ya por fin aprendí a hacer sub parches y hacer que funcionen como objetos, por lo que se cuentan con tres parches, el que abre el puerto de comunicación serial con la Pi Pico, el que dice que frecuencia de la nota se va utilizar dependiendo del valor que se lee del sensor, y el principal que junta estos dos y contiene los objetos para hacer funcionar el sintetizador theremin.



## Referencias
- [Como usar el sensor ultrasonico: https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/](https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/)
