#include <Taiyo.h>

Taiyo::Taiyo():WalkingCharacter(sf::Vector2f(72.f,78.f),"img/megaman.png", 4.f, 4.f){
}

void Taiyo::animate(const sf::Time& elapsed){
	m_animationTime += elapsed;
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
}