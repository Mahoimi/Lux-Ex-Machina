#include <Character.h>
#include <iostream>

Character::Character(const sf::Vector2f& size, const std::string& texturePath):m_sprite(size),m_texturePath(texturePath){
	if (!m_texture.loadFromFile(m_texturePath)){
		m_sprite.setFillColor(sf::Color::White);
		std::cout << "nope" << std::endl;
	}
	else{
		m_sprite.setTexture(&m_texture);
		m_sprite.setTextureRect(sf::IntRect(320, 15, 36, 39));
	}
}

void Character::animate(){
	// For each MovingState, ActionState ... we'll change the IntRect to display the correct version of the character
	// m_sprite.setTextureRect()
}