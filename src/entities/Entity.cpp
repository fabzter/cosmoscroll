#include "Entity.hpp"
#include "core/Collisions.hpp"


Entity::Entity():
	m_killed(false),
	m_team(NEUTRAL)
{

}


bool Entity::isDead() const
{
	return m_killed;
}


void Entity::kill()
{
	m_killed = true;
	onDestroy();
}


Entity::Team Entity::getTeam() const
{
	return m_team;
}


void Entity::setTeam(Team team)
{
	m_team = team;
}


sf::Vector2f Entity::getCenter() const
{
	sf::Vector2f pos = getPosition() - getOrigin();
	pos.x += getTextureRect().width / 2;
	pos.y += getTextureRect().height / 2;
	return pos;
}


void Entity::setTexture(const sf::Texture& texture)
{
	sf::Sprite::setTexture(texture);
	Collisions::registerTexture(&texture);
}
