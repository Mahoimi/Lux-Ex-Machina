#include <Taiyo.h>
#include <iostream>

Taiyo::Taiyo():WalkingCharacter(sf::Vector2f(72.f,78.f), sf::IntRect(320, 15, 36, 39), "img/megaman.png", 4.f, 10.f){
}

void Taiyo::inputControl(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			moveRight();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		jump();
	}
}

void Taiyo::jump(){
	if (m_movingState == MovingState::IDLE){
		m_movingState = MovingState::JUMPING;
		m_fallingSpeed = - m_jumpingHeight;
	}
}

void Taiyo::animate(const sf::Time& elapsed){
	m_animationTime += elapsed;

	// Character action
	inputControl();
	physics();

	// Displaying action
	switch (m_movingState){
		case MovingState::IDLE:
			if (m_animationTime.asMilliseconds() < 6100 && m_animationTime.asMilliseconds() >= 6000){
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
		// etc...
	}
}