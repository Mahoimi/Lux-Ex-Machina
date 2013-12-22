#include <Game.h>

Game::Game():m_window(sf::VideoMode(1600, 900), "Lux Ex Machina"),m_shape(100.f),m_isRunning(false){
	m_window.setVerticalSyncEnabled(true);
	m_shape.setFillColor(sf::Color::Red);
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
			m_shape.move(dx,dy);
			if (m_shape.getPosition().x < 0 ||m_shape.getPosition().x > m_window.getSize().x - m_shape.getRadius()*2){
				dx *= -1;
			}
			if (m_shape.getPosition().y < 0 ||m_shape.getPosition().y > m_window.getSize().y - m_shape.getRadius()*2){
				dy *= -1;
			}
			m_window.draw(m_shape);
			m_window.display();
		}
	}
}

void Game::exit(){
	m_window.close();
	m_isRunning = false;
}