#include <Taiyo.h>
#include <iostream>

Taiyo::Taiyo():
	WalkingCharacter(sf::Vector2f(72.f,78.f), sf::IntRect(320, 15, 36, 39), "img/megaman.png", 4.f, 20.f){

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

void Taiyo::physics(){
	if (m_sprite.getPosition().y < 800.f || m_movingState == MovingState::JUMPING){
		if (!m_hasJumped && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_totalHeight < 200.f){
			m_totalHeight += -m_dy;
			std::cout << m_totalHeight << std::endl;
		}
		else {
			m_hasJumped = true;
			m_dy += m_gravity;
		}
		m_sprite.move(0,m_dy);

		if (m_dy > 0){
			if (m_movingState != MovingState::FALLING) m_movingState=MovingState::FALLING;

			if (m_sprite.getPosition().y + m_dy >= 800.f){
				m_dy = 0.f;
				m_movingState=MovingState::IDLE;
				m_sprite.setPosition(m_sprite.getPosition().x, 800.f);
				m_totalHeight = 0.f;
				m_hasJumped = false;
			}
		}
	}
}

void Taiyo::animate(const sf::Time& elapsed){
	m_animationTime += elapsed;

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