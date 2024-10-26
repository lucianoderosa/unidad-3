// ejercicio7.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Puntos Rojos en las Esquinas y Punto Azul en el Centro");

    Color red(255, 0, 0); 
    Vector2f corners[4] = {
        {0, 0},
        {800 - 10, 0},
        {0, 600 - 10},
        {800 - 10, 600 - 10}
    };

 
    Texture bluePointTexture;
    Sprite bluePointSprite;

   
    if (!bluePointTexture.loadFromFile("puntoazul.png")) {
        std::cerr << "Error al cargar la imagen del punto azul." << std::endl;
        return -1; 
    }

    bluePointSprite.setTexture(bluePointTexture);

 
    float spriteWidth = bluePointTexture.getSize().x;
    float spriteHeight = bluePointTexture.getSize().y;
    bluePointSprite.setPosition((800 - spriteWidth) / 2, (600 - spriteHeight) / 2); 

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

      
        for (const auto& corner : corners) {
            CircleShape point(5);
            point.setFillColor(red);
            point.setPosition(corner);
            window.draw(point);
        }

        window.draw(bluePointSprite);

        window.display();
    }

    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
