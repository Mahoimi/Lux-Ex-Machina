#ifndef GAME_H
#define GAME_H

#include <FlyingTaiyo.h>
#include <SFML/Graphics.hpp>

class Game {
private:
	sf::RenderWindow m_window;
	FlyingTaiyo m_character;
	bool m_isRunning;

public:
	Game();
	void start();
	void loop();
	void exit();
};

#endif // GAME_H