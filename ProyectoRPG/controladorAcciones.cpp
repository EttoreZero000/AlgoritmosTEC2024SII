#include "controladorAcciones.h"
#include <xinput.h>
#include <iostream>
#include <windows.h>
#include <conio.h> // Para leer teclas del teclado

#pragma comment(lib, "xinput9_1_0.lib")

const int keyDownArrow = 80;
const int keyUpArrow = 72;
const int keyRightArrow = 77;
const int keyLeftArrow = 75;
const int keyEnter = 13;
const int keyBackspace = 8;
const int keyZ = 122;
const int keyX = 120;  

bool isButtonAHeld = false; // Bandera para el estado del botón A

// Función que detecta la entrada solo del controlador
int DetectControllerInput(const XINPUT_STATE& state) {
    // Detectar si se presiona la cruceta abajo o el joystick hacia abajo
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || 
        state.Gamepad.sThumbRY < -32000 || 
        state.Gamepad.sThumbLY < -8000) {
        return 1; // Acción hacia abajo
    }

    // Detectar si se presiona la cruceta arriba o el joystick hacia arriba
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || 
        state.Gamepad.sThumbRY > 8000 || 
        state.Gamepad.sThumbLY > 8000) {
        return 2; // Acción hacia arriba
    }

    // Detectar si se presiona la cruceta a la izquierda o el joystick hacia la izquierda
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT || 
        state.Gamepad.sThumbLX < -8000 ||
        state.Gamepad.sThumbRX < -8000) {
        return 3; // Acción hacia la izquierda
    }

    // Detectar si se presiona la cruceta a la derecha o el joystick hacia la derecha
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT || 
        state.Gamepad.sThumbLX > 8000 ||
        state.Gamepad.sThumbRX > 8000) {
        return 4; // Acción hacia la derecha
    }

    // Detectar si se presiona el botón A
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
        if (!isButtonAHeld) { // Solo devuelve acción si A no estaba ya presionado
            isButtonAHeld = true; // Marca que A está presionado
            return 5; // Acción botón A
        }
    } else {
        isButtonAHeld = false; // Restablecer la bandera cuando se suelta A
    }

    // Detectar si se presiona el botón B
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
        return 6; // Acción botón B
    }

    // Detectar si se presiona el botón X
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) {
        return 7; // Acción botón X
    }

    // Detectar si se presiona el botón Y
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
        return 8; // Acción botón Y
    }

    // Detectar si se presiona el botón Start
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) {
        return 9; // Acción botón Start
    }

    // Detectar si se presiona el botón Back (Select)
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) {
        return 10; // Acción botón Back (Select)
    }

    // Detectar si se presiona el botón izquierdo (LB)
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) {
        return 11; // Acción botón LB
    }

    // Detectar si se presiona el botón derecho (RB)
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {
        return 12; // Acción botón RB
    }

    // Detectar si se presiona el gatillo izquierdo (LT)
    if (state.Gamepad.bLeftTrigger > 30) { // Umbral de sensibilidad
        return 13; // Acción gatillo izquierdo
    }

    // Detectar si se presiona el gatillo derecho (RT)
    if (state.Gamepad.bRightTrigger > 30) { // Umbral de sensibilidad
        return 14; // Acción gatillo derecho
    }

    return 0; // No se detectó una acción relevante
}

// Función que detecta la entrada solo del teclado
int DetectKeyboardInput() {
    if (_kbhit()) { // Si una tecla fue presionada
        int key = _getch(); // Captura la tecla presionada

        if (key == keyDownArrow) {
            return 1; // Acción hacia abajo
        }
        if (key == keyUpArrow) {
            return 2; // Acción hacia arriba
        }
        if (key == keyEnter || key == keyZ){
            return 5;
        }
    }

    return 0; // No se detectó una acción relevante
}

// Ver si se realizó un cambio en el mando
bool HasSignificantChange(const XINPUT_STATE& oldState, const XINPUT_STATE& newState) {
    const int JOYSTICK_THRESHOLD = 1000; // Umbral para cambio significativo en el joystick

    return (abs(oldState.Gamepad.sThumbLX - newState.Gamepad.sThumbLX) > JOYSTICK_THRESHOLD ||
            abs(oldState.Gamepad.sThumbLY - newState.Gamepad.sThumbLY) > JOYSTICK_THRESHOLD ||
            abs(oldState.Gamepad.sThumbRX - newState.Gamepad.sThumbRX) > JOYSTICK_THRESHOLD ||
            abs(oldState.Gamepad.sThumbRY - newState.Gamepad.sThumbRY) > JOYSTICK_THRESHOLD ||
            oldState.Gamepad.bLeftTrigger != newState.Gamepad.bLeftTrigger ||
            oldState.Gamepad.bRightTrigger != newState.Gamepad.bRightTrigger ||
            oldState.Gamepad.wButtons != newState.Gamepad.wButtons);
}

// Función central de controlador de inputs, siempre devuelve un int.
int controladorInput() {
    XINPUT_STATE previousState;
    ZeroMemory(&previousState, sizeof(XINPUT_STATE));

    XINPUT_STATE state;
    ZeroMemory(&state, sizeof(XINPUT_STATE));
    bool controllerConnected = (XInputGetState(0, &state) == ERROR_SUCCESS);
    if (controllerConnected) {
        // Si el controlador está conectado, verificar cambios en su estado
        //if (HasSignificantChange(previousState, state)) {
            //previousState = state; // Actualiza el estado anterior
            // Detecta la entrada del controlador
            int accion = DetectControllerInput(state);
            if (accion > 0) {
                return accion;
            //} 
        }
    }
    // Siempre detectar la entrada del teclado
    int accionTeclado = DetectKeyboardInput();
    if (accionTeclado > 0) {
        return accionTeclado;
    }

    return 0;
}
