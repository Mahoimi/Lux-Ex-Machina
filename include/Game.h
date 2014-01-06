#ifndef GAME_H
#define GAME_H

#include <Taiyo.h>
#include <Tilemap.h>
#include <SFML/Graphics.hpp>

class Game {
private:
	sf::RenderWindow m_window;
	Taiyo m_character;
	TileMap m_map[5];
	bool m_isRunning;

public:
	Game();
	void start();
	void loop();
	void exit();
};

#endif // GAME_H