#ifndef LUX_GAME_H
#define LUX_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"
#include "Tilemap.h"

namespace Lux {
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
}

#endif // LUX_GAME_H