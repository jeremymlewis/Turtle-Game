#include "Game.h"
#include <chrono>
#include <thread>

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1080;
	this->window = new sf::RenderWindow(this->videoMode, "Turtle Game!");
    this->window->setFramerateLimit(360);
}


void Game::celebrate()
{
    imageYellow();
    render();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    imageBlue();
    render();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    imagePurple();
    render();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    imageRed();
    render();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    imageLeft();
}

void Game::imageLeft()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreenLeft.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imageRight()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreenRight.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imageLeftWalk()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreenLW.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imageRightWalk()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreenRW.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}
void Game::imageBlue()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("SkyLeft.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imageYellow()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("YellowLeft.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imagePurple()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("PurpleLeft.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::imageRed()
{
    sf::Image image;
    sf::IntRect area;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreyLeft.png");
    this->turtleSkin.loadFromImage(image, area);
    this->user.setTexture(this->turtleSkin);
}

void Game::initShapes()
{

    //this->t
    sf::Image image;
    sf::Image treatImage;
    sf::Image floorImage;
    sf::IntRect area;
    sf::IntRect floorArea;
    floorArea.height = 720;
    floorArea.width = 1080;
    area.height = 360;
    area.width = 360;
    image.loadFromFile("GreenLeft.png");
    treatImage.loadFromFile("GrayRight.png");
    floorImage.loadFromFile("wide-floor.png");
    this->turtleSkin.loadFromImage(image, area);
    this->treatSkin.loadFromImage(treatImage, area);
    this->floorSkin.loadFromImage(floorImage, floorArea);

    this->treat.setPosition(500.f, 10.f);
    this->treat.setTexture(this->treatSkin);
    this->floor.setPosition(0.f, 0.f);

    this->floor.setTexture(this->floorSkin);
    this->user.setPosition(10.f, 390.f);
    //this->user.setColor(sf::Color::Green);
    this->user.setTexture(this->turtleSkin);
    //this->user.setSize(sf::Vector2f(100.f, 100.f));
    //this->user.setFillColor(sf::Color::Green);
    //this->user.setOutlineColor(sf::Color::White);
    //this->user.setOutlineThickness(1.f);

}

//Constuctor
Game::Game() {
	this->initVariables();
	this->initWindow();
    this->initShapes();
}

Game::~Game() {
	delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape) {
                imageRed();
                render();
            }
            if (this->event.key.code == sf::Keyboard::Left) {
                imageLeftWalk();
                render();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                imageLeft();
                render();
                std::this_thread::sleep_for(std::chrono::milliseconds(40));
                if (user.getPosition().x < -54) {
                    user.setPosition(864.f, user.getPosition().y);
                }
                this->user.move(-18.f, 0);
            }
            if (this->event.key.code == sf::Keyboard::Right) {
                imageRightWalk();
                render();
                std::this_thread::sleep_for(std::chrono::milliseconds(160));

                imageRight();
                render();
                std::this_thread::sleep_for(std::chrono::milliseconds(40));
                if (user.getPosition().x > 864) {
                    user.setPosition(-54.f, user.getPosition().y);
                }
                this->user.move(18.f, 0);
                
            }
            if (this->event.key.code == sf::Keyboard::Up) {
                this->user.move(0, -10.f);
            }
            if (this->event.key.code == sf::Keyboard::Down) {
                this->user.move(0, 10.f);
            }
            break;
        }
    }
}

//Functions
void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    /*
        This renders the window
    */

    this->window->clear(sf::Color::White);

    //Draw the game objects
    this->window->draw(this->floor);
    //this->window->draw(this->treat);
    this->window->draw(this->user);

    this->window->display();
}
