// Spam ALT+F4 and CTRL+W forcing all active windows and browsers to close

#include "DigiKeyboard.h"

void setup()
{
    pinMode(1, OUTPUT); //LED on Model A
}

void loop()
{
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
}
