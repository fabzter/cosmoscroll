#include "GunTower.hpp"
#include "core/Resources.hpp"
#include "utils/Math.hpp"
#include "entities/EntityManager.hpp"
#include "entities/Player.hpp"

#define BASE_OFFSET 28

#define BASE_ID  0
#define CANON_ID 1

GunTower::GunTower():
	m_target(NULL)
{
	Part base(BASE_ID);
	base.setTexture(Resources::getTexture("entities/guntower-base.png"));

	Part turret(CANON_ID);
	const sf::Texture& img_turret = Resources::getTexture("entities/guntower-turret.png");
	turret.setTexture(img_turret);
	turret.setOrigin(img_turret.getSize().x / 2, img_turret.getSize().y / 2);
	addPart(turret, img_turret.getSize().x / 2, img_turret.getSize().y / 2);
	addPart(base, 0, BASE_OFFSET);

	m_weapon.init("laser-pink");
	m_weapon.setOwner(this);
	m_weapon.setPosition(img_turret.getSize().x / 2, img_turret.getSize().y / 2);
}


void GunTower::onUpdate(float frametime)
{
	MultiPartEntity::onUpdate(frametime);

	// Rotate turret toward player
	getPartAt(0).setRotation(180 - math::to_deg(math::angle(m_target->getPosition(), getPosition())));
	m_weapon.shoot(m_target->getCenter());
	m_weapon.onUpdate(frametime);
}


void GunTower::onInit()
{
	m_target = EntityManager::getInstance().GetPlayerShip();

	// Always positionned at bottom
	setY(EntityManager::getInstance().getHeight() - (BASE_OFFSET + 64));
}


GunTower* GunTower::clone() const
{
	return new GunTower(*this);
}
