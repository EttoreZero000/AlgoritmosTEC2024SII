#ifndef CONTROLADORACCIONES_H
#define CONTROLADORACCIONES_H

#include "controladorAcciones.cpp"

int DetectControllerInput(const XINPUT_STATE& state);
int DetectKeyboardInput();
bool HasSignificantChange(const XINPUT_STATE& oldState, const XINPUT_STATE& newState);
int controladorInput();
extern bool isButtonAHeld;
#endif // CONTROLADORACCIONES_H