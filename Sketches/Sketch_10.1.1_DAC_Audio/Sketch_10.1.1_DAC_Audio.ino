/**********************************************************************
  Filename    : Sketch_10.1.1_DAC_Audio
  Description : Use DAC to play music
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "analogWave.h"
#include "pitches.h"

// Melody and rhythm defined as an array
// Each note is followed by its duration (4 = quarter note, 8 = eighth note, etc.)
int melody[] = {
  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
};

analogWave wave(DAC);  // Initialize the analogWave object for DAC(A0)

int noteCounter = 0;                  // Index to keep track of which note is being played
int tempo = 200;                      // Set the tempo in BPM (Beats Per Minute)
int wholenote = (60000 * 4) / tempo;  // Calculate the duration of a whole note in ms
int divider = 0, noteDuration = 0;    // Variables to hold note duration

void setup() {
  wave.sine(10);  // Initialize the sine wave generator with a frequency of 10 Hz
}

void loop() {
  // Calculate the duration of the current note
  divider = melody[noteCounter + 1];
  if (divider > 0) {
    // For regular notes
    noteDuration = wholenote / divider;
  } else if (divider < 0) {
    // For dotted notes (duration increased by 50%)
    noteDuration = wholenote / abs(divider);
    noteDuration *= 1.5;  // Increase the duration by 50% for dotted notes
  }

  // Play the note
  wave.freq(melody[noteCounter]);
  delay(noteDuration * 0.85);  // Play the note for 85% of its duration
  wave.stop();

  // Pause between notes
  delay(noteDuration * 0.15);  // Pause for 15% of the note duration

  // Increment the note counter by 2 (because each note is followed by its duration)
  noteCounter += 2;

  // Reset the counter when reaching the end of the melody
  int totalNotes = sizeof(melody) / sizeof(melody[0]);
  noteCounter = noteCounter % totalNotes;

  // Add a delay between repetitions of the melody
  if (noteCounter == 0) {
    delay(1000);
  }
}