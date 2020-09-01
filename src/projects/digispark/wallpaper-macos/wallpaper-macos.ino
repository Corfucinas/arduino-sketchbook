// Launches Spotlight to launch Terminal.app, download a picture, and sets it as a wallpaper.

#include "DigiKeyboard.h"

void setup()
{
    pinMode(1, OUTPUT); //LED on Model A
}

void loop()
{
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("Terminal");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.print("curl https://tr3.cbsistatic.com/hub/i/2014/05/15/f8964afd-bd82-4e0e-bcbe-e927363dcdc1/3b858e39e2cf183b878f54cad0073a67/codedoge.jpg > /Users/Shared/wallpaper.jpg");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.print("osascript -e 'tell application \"Finder\" to set desktop picture to POSIX file \"/Users/Shared/wallpaper.jpg\"'");
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    digitalWrite(1, HIGH); //turn on led when program finishes
    for (;;)
    {
        /*Stops the digispark from running the script again*/
    }
}
