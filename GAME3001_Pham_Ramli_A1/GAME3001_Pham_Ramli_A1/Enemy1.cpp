#include "Enemy1.h"

Enemy1::Enemy1(sf::Vector2f position) 
{
	enemyPosition = position;
	setHealth(2);
	enemyMoveSpeed = 10.f;
	setActive(true);

	Sprite = new sf::Sprite();
	Texture = new sf::Texture();

	if(!Texture->loadFromFile("Assets/Images/Enemies/enemyGreen1.png"))
	{
		cout << "Image cannot be found." << endl;
	}

	Sprite->setTexture(*Texture);
	//Sprite.setScale(0.7f, 0.7f);
	Sprite->setPosition(enemyPosition);
}

Enemy1::~Enemy1() {

}

void Enemy1::update(sf::Time elapsedTime) {

	if(Sprite->getPosition().y < 150) 
	{
		velocity.y += enemyMoveSpeed / 6;
	} else 
	{
		velocity.y += enemyMoveSpeed;
	}

	cout << "Enemy state: " << isActive() << endl;

	if(Sprite->getPosition().y > 1000 || getHealth() <= 0) {
		setActive(false);
		cout << "Not active." << endl;
	}

	Sprite->move(velocity * elapsedTime.asSeconds());
}

void Enemy1::render(sf::RenderWindow &window) {
	if(isActive())
	window.draw(*Sprite);
}

int Enemy1::getDamage() {
	return 1;
}

void Enemy1::OnHit(int damage) {
	reduceHealth(damage);

	if(getHealth() <= 0) 
	{
		setActive(false);
		cout << "Not active." << endl;
	}
}