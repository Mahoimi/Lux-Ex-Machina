#include <Taiyo.h>
#include <iostream>

Taiyo::Taiyo():
	WalkingCharacter(sf::Vector2f(72.f,78.f), sf::IntRect(320, 15, 36, 39), "img/megaman.png", 10.f, 20.f){
		m_sprite.setScale(2.f,2.f);
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
	// TODO : Replace m_sprite.getPosition().y < 800.f by !checkGround()
	if (m_sprite.getPosition().y < 510.f || m_movingState == MovingState::JUMPING){
		if (!m_hasJumped && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_totalHeight < 200.f){
			m_totalHeight += -m_dy;
		}
		else {
			m_hasJumped = true;
			if (m_dy + m_gravity < m_maxFallingSpeed){
				m_dy += m_gravity;
			}
		}
		m_sprite.move(0,m_dy);

		if (m_dy > 0){
			if (m_movingState != MovingState::FALLING) setMovingState(MovingState::FALLING);

			if (m_sprite.getPosition().y + m_dy >= 510.f){
				m_dy = 0.f;
				setMovingState(MovingState::IDLE);
				m_sprite.setPosition(m_sprite.getPosition().x, 510.f);
				m_totalHeight = 0.f;
				m_hasJumped = false;
			}
		}
	}
	if (m_movingState == MovingState::RUNNING && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		setMovingState(MovingState::IDLE);
	}
}

void Taiyo::animate(const sf::Time& elapsed){
	m_animationTime += elapsed;

	inputControl();
	physics();

	int animDelay = 100;

	// Displaying action
	switch (m_movingState){
		case MovingState::IDLE:
			// std::cout << "IDLE" << std::endl;
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
		case MovingState::RUNNING:
			// std::cout << "RUNNING" << std::endl;
			if (m_animationTime.asMilliseconds() < animDelay){
				m_sprite.setTextureRect(sf::IntRect(104,104,32,38));
			}
			else if (m_animationTime.asMilliseconds() < 2*animDelay && m_animationTime.asMilliseconds() >= animDelay){
				m_sprite.setTextureRect(sf::IntRect(136,104,21,38));
			}
			else if (m_animationTime.asMilliseconds() < 3*animDelay && m_animationTime.asMilliseconds() >= 2*animDelay){
				m_sprite.setTextureRect(sf::IntRect(157,104,24,38));
			}
			else if (m_animationTime.asMilliseconds() < 4*animDelay && m_animationTime.asMilliseconds() >= 3*animDelay){
				m_sprite.setTextureRect(sf::IntRect(181,104,31,38));
			}
			else if (m_animationTime.asMilliseconds() < 5*animDelay && m_animationTime.asMilliseconds() >= 4*animDelay){
				m_sprite.setTextureRect(sf::IntRect(212,104,34,38));
			}
			else if (m_animationTime.asMilliseconds() < 6*animDelay && m_animationTime.asMilliseconds() >= 5*animDelay){
				m_sprite.setTextureRect(sf::IntRect(246,104,27,38));
			}
			else if (m_animationTime.asMilliseconds() < 7*animDelay && m_animationTime.asMilliseconds() >= 6*animDelay){
				m_sprite.setTextureRect(sf::IntRect(273,104,25,38));
			}
			else if (m_animationTime.asMilliseconds() < 8*animDelay && m_animationTime.asMilliseconds() >= 7*animDelay){
				m_sprite.setTextureRect(sf::IntRect(298,104,25,38));
			}
			else if (m_animationTime.asMilliseconds() < 9*animDelay && m_animationTime.asMilliseconds() >= 8*animDelay){
				m_sprite.setTextureRect(sf::IntRect(323,104,33,38));
			}
			else if (m_animationTime.asMilliseconds() < 10*animDelay && m_animationTime.asMilliseconds() >= 9*animDelay){
				m_sprite.setTextureRect(sf::IntRect(356,104,35,38));
			}
			else if (m_animationTime.asMilliseconds() < 11*animDelay && m_animationTime.asMilliseconds() >= 10*animDelay){
				m_sprite.setTextureRect(sf::IntRect(391,104,29,38));
			}
			else if (m_animationTime.asMilliseconds() >= 11*animDelay){
				m_sprite.setTextureRect(sf::IntRect(136,104,21,38));
				m_animationTime = sf::milliseconds(animDelay);
			}
			break;
		case MovingState::JUMPING:
			// std::cout << "JUMPING" << std::endl;
			break;
		case MovingState::FALLING:
			// std::cout << "FALLING" << std::endl;
			break;
	}
}