#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Example Work", Style::Default);
    window.setFramerateLimit(60);
    
    CircleShape shape(50.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //update
        shape.move(0.3f, 0.f);

        //draw
        window.clear(Color::Blue);
        
        //draw everything
        window.draw(shape);

        window.display();
    }

    return 0;
}
