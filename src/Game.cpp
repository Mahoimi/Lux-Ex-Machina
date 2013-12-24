#include <Game.h>
#include <iostream>

Game::Game():m_window(sf::VideoMode(1600, 900), "Lux Ex Machina"),m_isRunning(false){
	m_window.setVerticalSyncEnabled(true);
}

void Game::start(){
	if(!m_isRunning){
		m_isRunning=true;
		loop();
	}
}

void Game::loop(){
	sf::Clock clock;

	while (m_window.isOpen()) {
		sf::Time elapsed = clock.restart();
		sf::Event event;

		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				exit();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			exit();
		}

		if (m_isRunning) {
			m_window.clear();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					m_character.moveLeft();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					m_character.moveRight();
				}
			}
			m_character.animate(elapsed);
			m_window.draw(m_character.getSprite());
			m_window.display();
		}
	}
}

void Game::exit(){
	m_window.close();
	m_isRunning = false;
}