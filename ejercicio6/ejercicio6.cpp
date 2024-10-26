// ejercicio6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow App(sf::VideoMode(800, 600), "Colores");

   
    Texture textureB;
    Texture textureR;
    Texture textureY;
    Texture textureG;

    textureB.loadFromFile("cuad_blue.png");
    textureR.loadFromFile("cuad_red.png");
    textureY.loadFromFile("cuad_yellow.png");
    textureG.loadFromFile("cuad_grey.png");

  
    Sprite spriteB(textureB);
    Sprite spriteR(textureR);
    Sprite spriteY(textureY);
    Sprite spriteG(textureG);

  
    Vector2u windowSize = App.getSize();

   
    float targetWidth = windowSize.x / 2.0f; 
    float targetHeight = windowSize.y / 2.0f; 

 
    spriteR.setScale(targetWidth / textureR.getSize().x, targetHeight / textureR.getSize().y);  
    spriteY.setScale(targetWidth / textureY.getSize().x, targetHeight / textureY.getSize().y);  
    spriteB.setScale(targetWidth / textureB.getSize().x, targetHeight / textureB.getSize().y);  
    spriteG.setScale(targetWidth / textureG.getSize().x, targetHeight / textureG.getSize().y);  

   
    spriteR.setPosition(0, 0);                            
    spriteY.setPosition(targetWidth, 0);                   
    spriteB.setPosition(0, targetHeight);                 
    spriteG.setPosition(targetWidth, targetHeight);        

    while (App.isOpen())
    {
        Event event;
        while (App.pollEvent(event))
        {
            if (event.type == Event::Closed)
                App.close();
        }

        App.clear();

   
        App.draw(spriteR);  
        App.draw(spriteY);  
        App.draw(spriteB); 
        App.draw(spriteG);  

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
