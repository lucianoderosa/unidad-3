// ejercicio 5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotación de Sprite");


    sf::Texture plataformaTexture;
    if (!plataformaTexture.loadFromFile("plataforma.jpg")) {
        return -1;  
    }


    sf::Sprite plataformaSprite;
    plataformaSprite.setTexture(plataformaTexture);

  
    sf::FloatRect bounds = plataformaSprite.getLocalBounds();
    plataformaSprite.setOrigin(bounds.width / 2, bounds.height / 2);


    plataformaSprite.setPosition(400, 300);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        plataformaSprite.rotate(1.0f);


        window.clear(sf::Color::White);

 
        window.draw(plataformaSprite);

    
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
