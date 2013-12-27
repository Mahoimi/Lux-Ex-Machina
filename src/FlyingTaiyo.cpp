#include <FlyingTaiyo.h>
#include <iostream>

FlyingTaiyo::FlyingTaiyo():
	FlyingCharacter(sf::Vector2f(72.f,78.f), sf::IntRect(320, 15, 36, 39), "img/megaman.png", 1.f){
		m_sprite.setScale(2.f,2.f);
}

void FlyingTaiyo::inputControl(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			flyLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			flyRight();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			flyUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			flyDown();
		}
	}
}

void FlyingTaiyo::physics(){
	if (m_dx == 0 && m_dy == 0) setMovingState(MovingState::IDLE);
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (m_dx > 0){
			m_dx -= m_flyingSpeed;
		}
		else if (m_dx < 0){
			m_dx += m_flyingSpeed;
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (m_dy > 0){
			m_dy -= m_flyingSpeed;
		}
		else if (m_dy < 0){
			m_dy += m_flyingSpeed;
		}
	}
	m_sprite.move(m_dx, m_dy);
}

void FlyingTaiyo::animate(const sf::Time& elapsed){
	m_animationTime += elapsed;

	inputControl();
	physics();

	int animDelay = 100;

	// Displaying action
	switch (m_movingState){
		case MovingState::IDLE:
			std::cout << "IDLE" << std::endl;
			if (m_animationTime.asMilliseconds() < 6000){
				m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
			}
			else if (m_animationTime.asMilliseconds() < 6100 && m_animationTime.asMilliseconds() >= 6000){
				m_sprite.setTextureRect(sf::IntRect(354,15,36,39));
			}
			else if (m_animationTime.asMilliseconds() < 6200 && m_animationTime.asMilliseconds() >= 6100){
				m_sprite.setTextureRect(sf::IntRect(388,15,36,39));
			}
			else if (m_animationTime.asMilliseconds() >= 6200){
				m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
				m_animationTime = sf::milliseconds(0);
			}
			break;
		case MovingState::FLYING:
			std::cout << "FLYING" << std::endl;
			break;
	}
}