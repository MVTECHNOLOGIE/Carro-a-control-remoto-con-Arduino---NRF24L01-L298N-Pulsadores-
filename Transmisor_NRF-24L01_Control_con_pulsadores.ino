/*Versión 1.0 Control de radiofrecuencia "Pulsadores" [c,c++]
 * Programa para transmisor..........!!!!!!
Este sistema está diseñado para carros a control remoto, 
el cual está compuesto por dos motores,
uno en la parte de adelante y el otro en la parte posterior del carro, 
uno dirige al carro hacia atrás y adelante y el
otro se encarga de direccionar sea izquierda o derecha. 

Librerías a utilizar "RF24":https://github.com/nRF24/RF24

Pines para la comunicación del módulo NRF24L01.
Para el correcto funcionamiento del módulo, no alimentar a 3.3 V del 
microcontrolador se recomienda tener una fuente externa con dicho voltaje.

VCC - 3.3V "No conectar a 5 V porque podemos quemar al módulo"
GND - GND

Pines para Arduno Nano, Uno, Pro mini             Pines para Arduino Mega.
SCK  13  //Obligatorio deberá ser el pin 13       SCK  52  //Obligatorio deberá ser el pin 52
MISO 12  //Obligatorio deberá ser el pin 12       MISO 50  //Obligatorio deberá ser el pin 50
MOSI 11  //Obligatorio deberá ser el pin 11       MOSI 51  //Obligatorio deberá ser el pin 51
CE    9  //Pueden variar previa declaracion       CE    9  //Pueden variar previa declaracion
CSN  10  //Pueden variar previa declaracion       CSN  10  //Pueden variar previa declaracion
Nota: No se puede utilizar en el Arduino Pro micro amenos que ya esté integrado el módulo "NRF24L01"

Creador: Perea Vera Manuel - M&V Technologie 
*/ 

#include <SPI.h>      //Esta biblioteca le permite comunicarse con dispositivos SPI
#include <nRF24L01.h> //Se incluye libreria 
#include <RF24.h>     //Se incluye libreria

#define boton1 A0     //Declaramos que la variable botón esté vinculada con el pin A0
#define boton2 A1     //Declaramos que la variable botón esté vinculada con el pin A1
#define boton3 A4     //Declaramos que la variable botón esté vinculada con el pin A4
#define boton4 A5     //Declaramos que la variable botón esté vinculada con el pin A5
#define boton5 A3     //Declaramos que la variable botón esté vinculada con el pin A3

int Estado1 = 0;      //Creamos una variable que tendra un valor de 0
int Estado2 = 0;      //Creamos una variable que tendrá un valor de 0
int Estado3 = 0;      //Creamos una variable que tendrá un valor de 0
int Estado4 = 0;      //Creamos una variable que tendrá un valor de 0
int Estado5 = 0;      //Creamos una variable que tendrá un valor de 0

RF24 radio(9, 10);    // CE, CSN

const byte Direccion[6] = "00002"; // Canal 2

void setup() {
  
  Serial.begin(9600);  //Inicializa el monitor serial
  radio.begin();       //Inicializa el NRF24L01
  radio.openWritingPipe(Direccion); ////Abrimos un canal de escritura
  radio.setPALevel(RF24_PA_MIN);    //Establecemos el nivel del amplificador de potencia, en este caso Minimo
  radio.stopListening();            //radio.stopListening() que configura el módulo como transmisor
                                    //radio.startListening() que configura el módulo como receptor

  
  pinMode(boton1,INPUT_PULLUP);//Declaramos el botón como entrada añadiendo una resistencia interna en Pull Up
  pinMode(boton2,INPUT_PULLUP);//Declaramos el botón como entrada añadiendo una resistencia interna en Pull Up
  pinMode(boton3,INPUT_PULLUP);//Declaramos el botón como entrada añadiendo una resistencia interna en Pull Up
  pinMode(boton4,INPUT_PULLUP);//Declaramos el botón como entrada añadiendo una resistencia interna en Pull Up
  pinMode(boton5,INPUT_PULLUP);//Declaramos el botón como entrada añadiendo una resistencia interna en Pull Up

}
void loop() { //Inicia El blucle infinito "Lo que se encuentre en ese blucle se repetira infinitamente"

  Estado1 = digitalRead(boton1); //Indicamos que la variable "Estado1"Sea igual a la lectura del "boton1"
  Estado2 = digitalRead(boton2); //Indicamos que la variable "Estado2"Sea igual a la lectura del "boton2"
  Estado3 = digitalRead(boton3); //Indicamos que la variable "Estado3"Sea igual a la lectura del "boton3"
  Estado4 = digitalRead(boton4); //Indicamos que la variable "Estado4"Sea igual a la lectura del "boton4"
  Estado5 = digitalRead(boton5); //Indicamos que la variable "Estado5"Sea igual a la lectura del "boton5"
  
  //Retro
  if (Estado1 == HIGH){       //Si el pulso es alto "HIGH" o 1 se envía
    Estado1 = 1;              //un 1
  }
  else{                       //Si el pulso es bajo "LOW" o 0 se envía
    Estado1 = 0;              //un 0
  }
  
  //Avanza
  if (Estado2 == HIGH){       //Si el pulso es alto "HIGH" o 1 se envía
    Estado2 = 3;              //un 3
  }
  else{                       //Si el pulso es bajo "LOW" o 0 se envía
    Estado2 = 2;              //un 2
  }
  
  //Izquierda
  if (Estado3 == HIGH){       //Si el pulso es alto "HIGH" o 1 se envía
    Estado3 = 4;              //un 4
  } 
  else{                       //Si el pulso es bajo "LOW" o 0 se envía
    Estado3 = 5;              //un 5
  }
  
  //Derecha
    if (Estado4 == HIGH){     //Si el pulso es alto "HIGH" o 1 se envía
    Estado4 = 6;              //un 6
  }
  else{                       //Si el pulso es bajo "LOW" o 0 se envía
    Estado4 = 7;              //un 7
  }
    //360°
    if (Estado5 == HIGH){     //Si el pulso es alto "HIGH" o 1 se envía
    Estado5 = 8;              //un 8
  }
  else{                       //Si el pulso es bajo "LOW" o 0 se envía
    Estado5 = 9;              //un 9
  }
  
//  Serial.print(Estado1);   //Imprimimos en la terminal el valor almacenado en el "Estado1"
//  Serial.print("\t");      //Imprimimos un espacio horizontal
//  Serial.print(Estado2);   //Imprimimos en la terminal el valor almacenado en el "Estado2"
//  Serial.print("\t");      //Imprimimos tabulación horizontal
//  Serial.print(Estado3);   //Imprimimos en la terminal el valor almacenado en el "Estado3"
//  Serial.print("\t");      //Imprimimos tabulación horizontal
//  Serial.print(Estado4);   //Imprimimos en la terminal el valor almacenado en el "Estado4"
//  Serial.print("\t");      //Imprimimos tabulación horizontal
//  Serial.println(Estado5); //Imprimimos en la terminal el valor almacenado en el "Estado5"

  radio.write(&Estado1, sizeof(Estado1)); //Enviaremos un mensaje al receptor. El primer argumento aquí es la variable que queremos que se envíe.
  radio.write(&Estado2, sizeof(Estado2)); //Enviaremos un mensaje al receptor. El primer argumento aquí es la variable que queremos que se envíe.
  radio.write(&Estado3, sizeof(Estado3)); //Enviaremos un mensaje al receptor. El primer argumento aquí es la variable que queremos que se envíe.
  radio.write(&Estado4, sizeof(Estado4)); //Enviaremos un mensaje al receptor. El primer argumento aquí es la variable que queremos que se envíe.
  radio.write(&Estado5, sizeof(Estado5)); //Enviaremos un mensaje al receptor. El primer argumento aquí es la variable que queremos que se envíe.
}
