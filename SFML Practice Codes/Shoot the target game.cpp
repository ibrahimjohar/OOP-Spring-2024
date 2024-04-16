#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "Shoot The Target Game.");
	window.setFramerateLimit(60);

	CircleShape hoop;
	int dir = 0;
	hoop.setRadius(50.f);
	hoop.setFillColor(Color::Black);
	hoop.setOutlineThickness(5.f);
	hoop.setOutlineColor(Color::Blue);
	hoop.setPosition(Vector2f(0, 10.f));

	CircleShape ball;
	bool isShot = false;
	ball.setRadius(20.f);
	ball.setFillColor(Color::Blue);
	ball.setOutlineThickness(5.f);
	ball.setOutlineColor(Color::Cyan);
	ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius() * 3));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}

		//Update hoop
		if (hoop.getPosition().x <= 0)
		{
			dir = 1;
		}
		else if (hoop.getPosition().x + hoop.getRadius() >= window.getSize().x)
		{
			dir = 0;
		}


		if (dir == 0)
		{
			hoop.move(-5.f, 0);
		}
		else
		{
			hoop.move(5.f, 0);
		}

		
		//Update ball
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isShot = true;
		}

		
		if (!isShot)
		{
			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
		}
		else
		{
			ball.move(0, -5);
		}
		

		//Collision Ball
		if (ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
		{
			//Reset ball
			isShot = false;
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
		}



		//Draw
		window.clear(Color::Red);

		
		window.draw(hoop);
		window.draw(ball);
		window.display();
	}

	return 0;
}
