#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 400), "Shape(s) 1", Style::Default);
	window.setFramerateLimit(60);

	CircleShape circle(50.f);
	circle.setPosition(Vector2f(0.f, 0.f));

	RectangleShape rectangle(Vector2f(50.f, 100.f));
	rectangle.setPosition(Vector2f(400.f, 200.f));

	circle.setFillColor(Color(255, 240, 200, 255));
	rectangle.setFillColor(Color(154, 255, 235, 100));
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		//Update
		circle.move(0.5f, 0.1f);
		rectangle.move(-0.5f, -0.1f);

		//Draw
		window.clear();


		//Draw everything
		window.draw(circle);
		window.draw(rectangle);

		window.display();

	}

}
