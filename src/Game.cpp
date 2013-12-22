#include <Game.h>
#include <iostream>

Game::Game():m_window(sf::VideoMode(1600, 900), "Lux Ex Machina"),m_character(sf::Vector2f(72.f,78.f),"img/megaman.png"),m_isRunning(false){
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
	bool rightKeyPressed = false;
	bool leftKeyPressed = false;

	while (m_window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		sf::Event event;

		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Right){
					rightKeyPressed = true;
				}
				if (event.key.code == sf::Keyboard::Left){
					leftKeyPressed = true;
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::P){
					m_isRunning = !m_isRunning;
				}
				if (event.key.code == sf::Keyboard::Right){
					rightKeyPressed = false;
				}
				if (event.key.code == sf::Keyboard::Left){
					leftKeyPressed = false;
				}
			}

			if (event.type == sf::Event::Closed){
				exit();
			}
		}

		if (m_isRunning){
			m_window.clear();
			if (leftKeyPressed || rightKeyPressed){
				if (leftKeyPressed && !rightKeyPressed){
					m_character.moveLeft();
				}
				if (rightKeyPressed && !leftKeyPressed){
					m_character.moveRight();
				}
			}
			m_character.animate(elapsed);
			m_window.draw(m_character.m_sprite);
			m_window.display();
		}
	}
}

void Game::exit(){
	m_window.close();
	m_isRunning = false;
}