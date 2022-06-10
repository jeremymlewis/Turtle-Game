#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Game Objects
	sf::Sprite user;
	sf::Sprite floor;
	sf::Sprite treat;
	sf::Texture floorSkin;
	sf::Texture turtleSkin;
	sf::Texture treatSkin;
	sf::Texture turtleSkinBlue;
	sf::Texture turtleSkinGrey;
	sf::Texture turtleSkinRed;
	sf::Texture turtleSkinYellow;


	//Privte functions
	void celebrate();
	void imageLeft();
	void imageRight();
	void imageLeftWalk();
	void imageRightWalk();
	void imageBlue();
	void imageYellow();
	void imagePurple();
	void imageRed();
	void initVariables();
	void initWindow();
	void initShapes();
public:
	//Constructor
	Game();
	virtual ~Game();

	//Access
	const bool isRunning() const;

	//Functions

	void pollEvents();
	void update();
	void render();

};

