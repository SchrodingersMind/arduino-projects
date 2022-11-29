/*
  Pianino

  Play a dummy notes using pushbuttons

  Code for handling buzzer was taken from:
  https://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"
#include <Pushbutton.h>


Pushbutton button1(4);
Pushbutton button2(6);
Pushbutton button3(8);
Pushbutton button4(10);

int buzzerPin = 12;

// notes in the melody:
int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};


// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // TODO: add normal opening song
  // iterate over the notes of the melody:

  // for (int thisNote = 0; thisNote < 8; thisNote++) {

  //   // to calculate the note duration, take one second divided by the note type.

  //   //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

  //   int noteDuration = 1000 / noteDurations[thisNote];

  //   tone(8, melody[thisNote], noteDuration);

  //   // to distinguish the notes, set a minimum time between them.

  //   // the note's duration + 30% seems to work well:

  //   int pauseBetweenNotes = noteDuration * 1.30;

  //   delay(pauseBetweenNotes);

  //   // stop the tone playing:

  //   noTone(8);

  // }
  Serial.begin(9600);

  // pinMode(3, INPUT_PULLUP);
}

void loop() {

  if (button1.getSingleDebouncedPress())
  {
    Serial.println("Button1 is pressed!");
    tone(buzzerPin, NOTE_C4, 1000/2);
    // The button was pressed, so perform some action.
  }
  
  if (button2.getSingleDebouncedPress())
  {
    Serial.println("Button2 is pressed");
    tone(buzzerPin, NOTE_D4, 1000/2);

    // The button was pressed, so perform some action.
  }

  if (button3.getSingleDebouncedPress())
  {
    tone(buzzerPin, NOTE_E4, 1000/2);
  }
  
  if (button4.getSingleDebouncedPress())
  {
    tone(buzzerPin, NOTE_F4, 1000/2);
  }

  delay(1);
}