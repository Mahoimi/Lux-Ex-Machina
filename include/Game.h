#ifndef GAME_H
#define GAME_H

#include <GameObject.h>
#include <Tilemap.h>
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
private:
	GameObject m_taiyo;
	sf::RenderWindow m_window;
	//TileMap m_map[5];
	bool m_isRunning;

public:
	Game();
	void start();
	void loop();
	void exit();
};

#endif // GAME_H