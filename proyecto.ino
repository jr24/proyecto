int valorLDR = 0; //Declaracion variable de recepcion del valor
int pinLDR = A0; //Declaracion variable pin analogico LDR
int pinLed = 10;  //Declaracion variable pin Digital LED
int pinSHARP = A2;//Declaracion variable pin analogico SHARP
int valorSHARP = 0;//Declaracion variable recepcion del valor
int pinBuzzer = 12;//Declaracion variable pin Digital Buzzer


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Inicializamos el monitor serie para visualizar los valores del LDR.
  pinMode(pinLed, OUTPUT); //Configuramos como output o salida de datos el pin del LED
  pinMode(pinBuzzer,OUTPUT);//Configuramos como output o salida de datos el pin del BUZZER  
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLDR = analogRead(pinLDR);//Recibimos el valor del LDR
  Serial.println(valorLDR);//Imprimimos en el monitor serial el valor del LDR
  valorSHARP = analogRead(pinSHARP);
  //Serial.println(valorSHARP);//Imprimimos en el monitor serial el valor del SHARP
  delay(100);//tiempo de respuesta
  if(valorLDR<20){//Condicion para encender o apagar el led segun la intensidad luminosa
    digitalWrite(pinLed, HIGH);//Enciende el led si hay poca luz
  }
  else{
    digitalWrite(pinLed, LOW);//Apaga el led si hay mucha luz
  }
  if(valorSHARP>=150){//Condicion para realizar un zumbido segun la distacia al sensor
    digitalWrite(pinBuzzer, HIGH);//Realiza un zumbido si hay una distancia corta
  }
  else{
    digitalWrite(pinBuzzer, LOW);//No realiza ningun zumbido si hay una distancia larga
  }
  
}