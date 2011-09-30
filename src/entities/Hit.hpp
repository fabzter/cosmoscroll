#ifndef HIT_HPP
#define HIT_HPP

#include "Entity.hpp"

/**
 * Bullet entity, emitted by Weapon class
 */
class Hit: public Entity
{
public:
	/**
	 * @param team: équipe du projectile
	 * @param position: position initiale (x, y)
	 * @param angle: angle de la trajectoire
	 * @param image: image du projectile
	 * @param speed: vitesse du projectile (pixels / seconde)
	 * @param damage: dégâts infligés lors d'une collision
	 */
	Hit(Entity::Team team, const sf::Vector2f& position, float angle,
		const sf::Image* image, int speed, int damage);

	// inherited
	Hit* Clone() const;

	// inherited
	void Update(float frametime);

	// inherited
	void GetCollideRect(sf::FloatRect& rect) const;

	// inherited
	void OnCollide(Entity& entity);

	// inherited
	void TakeDamage(int);

private:
	sf::Vector2f speed_;
};

#endif // HIT_HPP
