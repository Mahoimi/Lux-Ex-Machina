#ifndef GAME_H
#define GAME_H

#include <GameObject.h>
#include <Tilemap.h>
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
private:
	GameObject m_taiyo;
	GameObject* m_maps[5];
	sf::RenderWindow m_window;
	bool m_isRunning;

public:
	Game();
	~Game();
	void start();
	void loop();
	void exit();
};

#endif // GAME_H