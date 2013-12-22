#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
private:
	sf::RenderWindow m_window;
	sf::CircleShape m_shape;
	bool m_isRunning;

public:
	Game();
	void start();
	void loop();
	void exit();
};

#endif // GAME_H