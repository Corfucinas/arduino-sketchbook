/*

TEMPERATURE SENSOR

  The TMP36 is an easy-to-use temperature sensor that outputs
  a voltage that's proportional to the ambient temperature.

  More information on the sensor is available in the datasheet:
  http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Temp/TMP35_36_37.pdf

Hardware connections:

  Connect the 5V pin to 5 Volts (5V).
  Connect the SIGNAL pin to ANALOG pin 0.
  Connect the GND pin to ground (GND).

*/

int temperature_pin = 0; // Analog input 0 to measure the temperature sensor's
int buzzer_pin = 9; // Alarm pin

// Length must equal the total number of notes and spaces
int song_length = 18;

// Notes is an array of text characters corresponding to notes
// A space represents a rest (no tone)
/*
  note   frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/
char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest

// Beats is an array of values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Rests (spaces) need a length as well.
int beats[] = {1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};

// To make the song play faster, decrease this value.
int tempo = 150;

// Too hot or too cold
int temperature_limit = 25;

void setup() // put your setup code here, to run once:
{

  // The speed is measured in bits per second, also known as
  // "baud rate". 9600 is a very commonly used baud rate,
  // and will transfer about 1000 characters per second.

  Serial.begin(9600);
  pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
  // Declare three floating-point variables
  float voltage, degrees_c, degrees_f;

  // We'll measure the voltage at the analog pin. Normally
  // analogRead(), returns a number from 0 to 1023.
  // getVoltage() returns the true voltage (0 to 5 Volts)
  // present on an analog input pin.

  voltage = get_voltage(temperature_pin);

  // Convert the voltage to degrees Celsius.
  // The formula comes from the temperature sensor datasheet:

  degrees_c = (voltage - 0.5) * 100.0;

  // Convert degrees Celsius to Fahrenheit.

  degrees_f = degrees_c * (9.0 / 5.0) + 32.0;

  // Print these values to the serial monitor.

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degrees_c);
  Serial.print("  deg F: ");
  Serial.println(degrees_f);

  if (degrees_c > temperature_limit) // Specify a temperature to trigger the alarm
  {
    int i, duration;

    for (i = 0; i < song_length; i++) // step through the song's array
    {
      duration = beats[i] * tempo; // length of note or rest in ms

      if (notes[i] == ' ') // Rest note
      {
        delay(duration); // Pause for a moment
      }
      else // otherwise, play the note
      {
        tone(buzzer_pin, sound_alarm(notes[i]), duration);
        delay(duration); // wait for tone to finish
      }
      delay(tempo / 10); // brief pause between notes
      digitalWrite(buzzer_pin, HIGH);
    }
  }
  delay(1000); // delay for one second
}

int sound_alarm(char note)
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.

  int i;
  const int num_notes = 8; // number of stored notes

  // The following arrays hold the note characters and their
  // corresponding frequencies. More notes can be added,
  // but they must be unique.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (i = 0; i < num_notes; i++) // Step through the notes
  {
    if (names[i] == note) // Find the note
    {
      return (frequencies[i]); // Return the frequency
    }
  }
  return (0); // Return 0 if frequency is not found
}

float get_voltage(int pin)
{
  // This function has one input parameter, the analog pin number
  // to read. You might notice that this function does not have
  // "void" in front of it; this is because it returns a floating-
  // point value, which is the true voltage on that pin (0 to 5V).

  return (analogRead(pin) * 0.004882814);

  // This equation converts the 0 to 1023 value that analogRead()
  // returns, into a 0.0 to 5.0 value that is the true voltage
  // being read at that pin.
}
