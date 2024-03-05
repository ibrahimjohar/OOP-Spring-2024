/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Write a program that uses composition to implement a game engine. A game engine is madeup of several components.
*                    For example:
*                    a) Graphics rendering engine
*                    b) Input handler
*                    c) Physics engine
*                    You don’t have to write the logic for how these individual components work.
*/

#include <iostream>
using namespace std;

class GraphicsRenderEngine
{
    public:
        void Render()
        {
            cout << "Rendering graphics now!\n";
        }

        ~GraphicsRenderEngine()//destructor
        {
            cout << "GraphicsRenderEngine class has been deleted.\n";
        }
};

class InputHandler
{
    public:
        void HandleInput()
        {
            cout << "Handling input right now!\n";
        }

        ~InputHandler()//destructor
        {
            cout << "InputHandler class has been deleted.\n";
        }
};

class PhysicsEngine
{
    public:
        void SimulatePhysics()
        {
            cout << "Simulating physics of the game world!\n";
        }

        ~PhysicsEngine()//destructor
        {
            cout << "PhysicsEngine class has been deleted.\n";
        }
};

class EnhanceFighter
{
    public:
        void FighterPowerUp()
        {
            cout << "Fighter's power has been intensified! Get Ready to Play now!\n";
        }

        ~EnhanceFighter()//destructor
        {
            cout << "EnahnceFighter class has been deleted.\n";
        }
};

class GameEngine
{
    private:
        GraphicsRenderEngine graphics;
        InputHandler inputHandler;
        PhysicsEngine physicsEngine;
        EnhanceFighter fighter;
    public:
        void runGame()
        {
            inputHandler.HandleInput();
            physicsEngine.SimulatePhysics();
            graphics.Render();
            fighter.FighterPowerUp();
        }

        ~GameEngine()//destructor
        {
            cout << "\nAdministrator has ended the game.\n";
        }
};

int main()
{
    GameEngine *fighterGame = new GameEngine;
    fighterGame->runGame();

    delete fighterGame; //when the dynamically allocated pointer is deleted the instances of the other classes are also deleted
                        //due to their existence solely being inside the GameEngine class, 
                        //a demonstration of "Composition" is also seen when their respective destructors output deletion statements.

    return 0;
}