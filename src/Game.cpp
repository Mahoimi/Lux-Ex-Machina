#include <Game.h>

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
	float dx = 4.f;
	float dy = 4.f;

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::P){
					m_isRunning = !m_isRunning;
				}
			}

			if (event.type == sf::Event::Closed){
				exit();
			}
		}

		if (m_isRunning){
			m_window.clear();
			m_character.m_sprite.move(dx,dy);
			if (m_character.m_sprite.getPosition().x < 0 ||m_character.m_sprite.getPosition().x > m_window.getSize().x - m_character.m_sprite.getSize().x){
				dx *= -1;
			}
			if (m_character.m_sprite.getPosition().y < 0 ||m_character.m_sprite.getPosition().y > m_window.getSize().y - m_character.m_sprite.getSize().y){
				dy *= -1;
			}
			m_window.draw(m_character.m_sprite);
			m_window.display();
		}
	}
}

void Game::exit(){
	m_window.close();
	m_isRunning = false;
}