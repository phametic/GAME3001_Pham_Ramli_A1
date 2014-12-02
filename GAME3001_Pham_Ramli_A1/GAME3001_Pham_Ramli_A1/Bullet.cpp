#include "Bullet.h"

Bullet::Bullet() 
	
{
	Sprite = new sf::Sprite();
	Texture = new sf::Texture();
	setActive(true);
	bulletSpeed = 25.f;

	if(!Texture->loadFromFile("Assets/Images/Lasers/laserRed03.png"))
	{
		std::cout << "Image cannot be found." << std::endl;
	}
	Sprite->setTexture(*Texture);
}

Bullet::~Bullet() {
	
}

void Bullet::SetPosition(float x, float y) {
	Sprite->setPosition(x, y);
}

void Bullet::update(sf::Time elapsedTime) {
	if(isActive()) {
		velocity.x += bulletSpeed;

		std::cout << "Bullet state: " << isActive() << std::endl;

		if(Sprite->getPosition().x > 700) 
			setActive(false);

		Sprite->move(velocity * elapsedTime.asSeconds());
	}
}

void Bullet::render(sf::RenderWindow &window) {
	if(isActive())
	window.draw(*Sprite);
}

int Bullet::getDamage() {
	return 1;
}
