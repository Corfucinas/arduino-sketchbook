//Opens up the powershell and makes your computer speak out a message.

#include "DigiKeyboard.h"

void setup()
{
    pinMode(1, OUTPUT); //LED on Model A
}

void loop()
{
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(100);
    DigiKeyboard.print("powershell");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(300);
    DigiKeyboard.print("Add-Type -AssemblyName System.speech");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    DigiKeyboard.print("$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    //Uncomment these lines to use a female voice
    //DigiKeyboard.print("$speak.SelectVoice('Microsoft Zira Desktop')");
    //DigiKeyboard.sendKeyStroke(KEY_ENTER);
    //DigiKeyboard.delay(500);
    DigiKeyboard.print("$speak.Speak(\"Here's a joke.\")");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    DigiKeyboard.print("exit");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_N);
    digitalWrite(1, HIGH); //turn on led when program finishes
    for (;;)
    {
        /*Stops the digispark from running the script again*/
    }
}
