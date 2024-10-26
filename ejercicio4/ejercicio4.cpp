// ejercicio4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>

int main() {
   
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plataformas con Texturas");

  
    sf::Texture plataformaTexture;
    if (!plataformaTexture.loadFromFile("plataforma.jpg")) {
        return -1; 
    }


    sf::RectangleShape plataforma1(sf::Vector2f(30, 50));
    plataforma1.setPosition(50, 550); 
    plataforma1.setTexture(&plataformaTexture);  

    sf::RectangleShape plataforma2(sf::Vector2f(30, 100));
    plataforma2.setPosition(100, 500);  
    plataforma2.setTexture(&plataformaTexture);

    sf::RectangleShape plataforma3(sf::Vector2f(30, 150));
    plataforma3.setPosition(150, 450); 
    plataforma3.setTexture(&plataformaTexture);

    sf::RectangleShape plataforma4(sf::Vector2f(30, 200));
    plataforma4.setPosition(200, 400);  
    plataforma4.setTexture(&plataformaTexture);

    sf::RectangleShape plataforma5(sf::Vector2f(30, 250));
    plataforma5.setPosition(250, 350);  
    plataforma5.setTexture(&plataformaTexture);

    sf::RectangleShape plataforma6(sf::Vector2f(30, 300));
    plataforma6.setPosition(300, 300);  
    plataforma6.setTexture(&plataformaTexture);

    sf::RectangleShape plataforma7(sf::Vector2f(30, 350));
    plataforma7.setPosition(350, 250);  
    plataforma7.setTexture(&plataformaTexture);

    
    sf::RectangleShape plataformaHorizontal(sf::Vector2f(200, 30));  
    plataformaHorizontal.setPosition(400, 250);  
    plataformaHorizontal.setTexture(&plataformaTexture);

 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

     
        window.clear(sf::Color::White);

     
        window.draw(plataforma1);
        window.draw(plataforma2);
        window.draw(plataforma3);
        window.draw(plataforma4);
        window.draw(plataforma5);
        window.draw(plataforma6);
        window.draw(plataforma7);

    
        window.draw(plataformaHorizontal);

    
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
