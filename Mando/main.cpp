#include <xinput.h>
#include <iostream>
#include <windows.h>

// Enlaza con la biblioteca XInput
#pragma comment(lib, "xinput9_1_0.lib")

// Función para mostrar el estado del controlador
void DisplayControllerState(const XINPUT_STATE& state) {
    std::cout << "Controller state changed:" << std::endl;

    // Botones principales
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) std::cout << "Button A pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B) std::cout << "Button B pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X) std::cout << "Button X pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) std::cout << "Button Y pressed" << std::endl;

    // Botones adicionales
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) std::cout << "Select (Back) pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_START) std::cout << "Start pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) std::cout << "L1 (Left Shoulder) pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) std::cout << "R1 (Right Shoulder) pressed" << std::endl;

    // Joysticks
    std::cout << "Left Joystick X: " << state.Gamepad.sThumbLX << " Y: " << state.Gamepad.sThumbLY << std::endl;
    std::cout << "Right Joystick X: " << state.Gamepad.sThumbRX << " Y: " << state.Gamepad.sThumbRY << std::endl;

    // Cruceta
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) std::cout << "D-Pad Up pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) std::cout << "D-Pad Down pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) std::cout << "D-Pad Left pressed" << std::endl;
    if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) std::cout << "D-Pad Right pressed" << std::endl;

    // Gatillos
    std::cout << "Left Trigger: " << static_cast<int>(state.Gamepad.bLeftTrigger) << std::endl;
    std::cout << "Right Trigger: " << static_cast<int>(state.Gamepad.bRightTrigger) << std::endl;
}

// Función para comparar el estado del mando con un umbral de cambio
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

int main() {
    XINPUT_STATE previousState;
    ZeroMemory(&previousState, sizeof(XINPUT_STATE));

    while (true) {
        XINPUT_STATE state;
        ZeroMemory(&state, sizeof(XINPUT_STATE));

        // Obtiene el estado del controlador número 0
        if (XInputGetState(0, &state) == ERROR_SUCCESS) {
            // Si el estado ha cambiado significativamente desde la última comprobación
            if (HasSignificantChange(previousState, state)) {
                DisplayControllerState(state); // Muestra el estado del controlador
                previousState = state; // Actualiza el estado anterior
            }
        } else {
            std::cout << "Controller is not connected." << std::endl;
        }

        Sleep(100); // Espera 100 ms entre comprobaciones
    }

    return 0;
}
