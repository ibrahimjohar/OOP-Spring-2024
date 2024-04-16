#include <SFML/Graphics.hpp>  
#include <vector>             
#include <cstdlib>            
using namespace sf;           
using namespace std;          

int main()
{
    srand(time(NULL));  // Seed random number generator

    RenderWindow window(VideoMode(640, 480), "Shooter Game with Projectiles.");  // Create window
    window.setFramerateLimit(60);  // Set maximum frame rate to 60 frames per second

    // Initialize game objects
    CircleShape projectile;  // Player's projectile
    projectile.setFillColor(Color::Red);  // Set color of the projectile
    projectile.setRadius(5.f);  // Set radius of the projectile

    RectangleShape enemy;  // Enemy shape
    enemy.setFillColor(Color::Magenta);  // Set color of the enemy
    enemy.setSize(Vector2f(50.f, 50.f));  // Set size of the enemy

    CircleShape player;  // Player shape
    player.setFillColor(Color::White);  // Set color of the player
    player.setRadius(50.f);  // Set radius of the player
    player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);  // Position the player at the bottom center of the window
    Vector2f playerCenter;  // Center of the player
    int shootTimer = 0;  // Timer for shooting

    vector<CircleShape> projectiles;  // Collection of projectiles
    projectiles.push_back(CircleShape(projectile));  // Add initial projectile to the collection

    vector<RectangleShape> enemies;  // Collection of enemies
    enemies.push_back(RectangleShape(enemy));  // Add initial enemy to the collection
    int enemySpawnTimer = 0;  // Timer for enemy spawning

    while (window.isOpen())  // Main game loop
    {
        Event event;  // SFML event object
        while (window.pollEvent(event))  // Event handling loop
        {
            if (event.type == Event::Closed)  // Close window event
            {
                window.close();
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)  // Escape key pressed event
            {
                window.close();
            }
        }

        // Update game state

        // Update player
        playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());  // Calculate center of the player
        player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);  // Move player horizontally with mouse

        // Update projectiles
        if (shootTimer < 5)  // Control shooting rate
        {
            shootTimer++;
        }

        if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 5)  // Shoot if timer allows
        {
            projectile.setPosition(playerCenter);  // Set initial position of the projectile
            projectiles.push_back(CircleShape(projectile));  // Add new projectile to the collection

            shootTimer = 0;  // Reset shoot timer
        }

        for (size_t i = 0; i < projectiles.size(); i++)  // Move projectiles and remove if out of bounds
        {
            projectiles[i].move(0.f, -10.f);  // Move projectile upward

            if (projectiles[i].getPosition().y <= 0)  // Check if projectile is out of bounds
            {
                projectiles.erase(projectiles.begin() + i);  // Remove projectile from collection
            }
        }

        // Update enemies
        if (enemySpawnTimer < 20)  // Control enemy spawning rate
        {
            enemySpawnTimer++;
        }

        if (enemySpawnTimer >= 20)  // Spawn enemies at intervals
        {
            enemy.setPosition((rand() % int(window.getSize().x - enemy.getSize().x)), 0.f);  // Randomly position enemy at the top of the window
            enemies.push_back(RectangleShape(enemy));  // Add new enemy to the collection

            enemySpawnTimer = 0;  // Reset enemy spawn timer
        }

        for (size_t i = 0; i < enemies.size(); i++)  // Move enemies and remove if out of bounds
        {
            enemies[i].move(0.f, 5.f);  // Move enemy downward

            if (enemies[i].getPosition().y > window.getSize().y - 20)  // Check if enemy is out of bounds
            {
                enemies.erase(enemies.begin() + i);  // Remove enemy from collection
            }
        }

        // Collision detection
        for (size_t i = 0; i < projectiles.size(); i++)  // Check for collisions between projectiles and enemies
        {
            for (size_t k = 0; k < enemies.size(); k++)
            {
                if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))  // Check if projectile intersects with enemy
                {
                    projectiles.erase(projectiles.begin() + i);  // Remove projectile from collection
                    enemies.erase(enemies.begin() + k);  // Remove enemy from collection
                    break;  // Break inner loop after collision is found
                }
            }
        }

        // Drawing phase
        window.clear();  // Clear the window

        window.draw(player);  // Draw player

        for (size_t i = 0; i < enemies.size(); i++)  // Draw enemies
        {
            window.draw(enemies[i]);
        }

        for (size_t i = 0; i < projectiles.size(); i++)  // Draw projectiles
        {
            window.draw(projectiles[i]);
        }

        window.display();  // Display everything drawn

    }  // End of main game loop

    return 0;  
}
