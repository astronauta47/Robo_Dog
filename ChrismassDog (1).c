﻿#include <SoftwareSerial.h>// import the serial library

SoftwareSerial mySerial(10, 11); // RX, TX

int dc1f=13; //DC 1 forward
int dc1b=12; //DC 1 backward
int dc2f=9; //DC 2 forward
int dc2b=8; //DC 2 backward

char BluetoothData; // the data given from Computer

int speakerPin = 0;
int lightNumber;
int length = 69;
char notes[] = "ddaagfedcdefga ddaagfedcdefga avgavCDagfdefgfgavaagfedfedgfgavCDagfed";
int beats[] = { 2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,4,2,2,2,2,2,2,4,1,1,2,4,2,2,2,2,2,2,2,2,2,2,8 };
int tempo = 150;

void playTone(int tone, int duration) 
{ 
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(speakerPin, HIGH);
    
    delayMicroseconds(tone);
    
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
    
  }
 
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 's', 'g', 'a', 'v', 'b', 'C', 'D', 'E' };
int tones[] = { 1915, 1700, 1519, 1432, 1352, 1275, 1136, 1073, 1014, 956, 852, 758 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void PlayMusic()
{
  for (int i = 0; i < length; i++) 
  { 
    if (notes[i] == ' ') delay(beats[i] * tempo); // rest
    
    else 
    {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
}

void setup() {

Serial.begin(4800);

pinMode(speakerPin, OUTPUT);

Serial.println("Type AT commands!"); // put your setup code here, to run once:

mySerial.begin(9600);

Serial.println("Bluetooth On please press 1 or 0 blink LED ..");

pinMode(dc1f,OUTPUT);
pinMode(dc1b,OUTPUT);
pinMode(dc2f,OUTPUT);
pinMode(dc2b,OUTPUT);

}

void loop() {

// put your main code here, to run repeatedly:

  if (mySerial.available())
  {
    BluetoothData=mySerial.read();
    
    //DC 1
    if(BluetoothData=='1') { // if number 1 pressed
      digitalWrite(dc1f,HIGH);
    }
    else if (BluetoothData=='2') { // if number 2 pressed 
      digitalWrite(dc1f, LOW);
    }
    else if(BluetoothData=='3') { // if number 3 pressed 
      digitalWrite(dc1b,HIGH);
    }
    else if(BluetoothData=='4') // if number 4 pressed
    {
      digitalWrite(dc1b, LOW);
    }
    //DC 2
    else if (BluetoothData=='5') { // if number 5 pressed
      digitalWrite(dc2f, HIGH);
    }
    else if(BluetoothData=='6') { // if number 6 pressed
      digitalWrite(dc2f,LOW);
    }

    else if (BluetoothData=='7') { // if number 7 pressed
      digitalWrite(dc2b, HIGH);
    }
    else if(BluetoothData=='8') { // if number 8 pressed
      digitalWrite(dc2b, LOW);
    }
    else if(BluetoothData == '9')
      PlayMusic();
  }
  
    delay(10);// prepare for next data …
}
