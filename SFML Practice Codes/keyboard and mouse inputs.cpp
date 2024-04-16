#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 400), "Keyboard and Mouse Inputs", Style::Default);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			// METHOD ONE to deal with key presses within "Events"

			/*if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				window.close();
			}*/ 

			// 
		}

		// METHOD TWO to deal with key presses 

		/*if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}*/

		// METHOD to deal with mouse click

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			window.close();
		}


		//Update

		//Draw
		window.clear();


		//Draw everything
		window.display();

	}
	return 0;
}
