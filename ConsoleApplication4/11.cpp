#include <windows.h>

// Declaración de la función de ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd) {
    // Crear la ventana
    const char CLASS_NAME[] = "MiVentanaClase";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Ventana de 800x600",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    // Bucle de mensajes
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Procesar los mensajes de la ventana
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Dibujar puntos rojos en las esquinas
        SetPixel(hdc, 0, 0, RGB(255, 0, 0));                 // Esquina superior izquierda
        SetPixel(hdc, 799, 0, RGB(255, 0, 0));               // Esquina superior derecha
        SetPixel(hdc, 0, 599, RGB(255, 0, 0));               // Esquina inferior izquierda
        SetPixel(hdc, 799, 599, RGB(255, 0, 0));             // Esquina inferior derecha

        EndPaint(hwnd, &ps);
    } break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
