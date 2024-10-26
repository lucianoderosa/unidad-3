// ejercicio2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


Texture textureWhite;
Texture textureBlack;
Sprite spriteWhite;
Sprite spriteBlack;


int main() {
  
    if (!textureWhite.loadFromFile("chessw.png")) {
        std::cerr << "Error al cargar la textura blanca" << std::endl;
        return -1;
    }

    if (!textureBlack.loadFromFile("chessb.png")) {
        std::cerr << "Error al cargar la textura negra" << std::endl;
        return -1;
    }

  
    spriteWhite.setTexture(textureWhite);
    spriteBlack.setTexture(textureBlack);

   
    RenderWindow App(VideoMode(800, 600), "Tablero de Ajedrez");

  
    while (App.isOpen()) {
       
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
        }

    
        App.clear();

      
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                Sprite& currentSprite = (i + j) % 2 == 0 ? spriteWhite : spriteBlack; 
                currentSprite.setPosition(i * 100, j * 100); 
                App.draw(currentSprite);
            }
        }

        
        App.display();
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
