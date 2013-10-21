#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <string>
#include <list>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "core/Input.hpp"
#include "Entity.hpp"

class ParticleSystem;
class Spaceship;
class Player;
class LevelManager;
#include "Animation.hpp"

/**
 * Gestionnaire de la vie, l'univers et tout le reste
 */
class EntityManager: public sf::Drawable, public sf::Transformable
{
public:
	// background image speed for parallax scrolling
	static const int BACKGROUND_SPEED = 15;
	static const int FOREGROUND_SPEED = 45;

	enum Mode
	{
		MODE_STORY,
		MODE_ARCADE
	};

	/**
	 * @return instance unique
	 */
	static EntityManager& getInstance();

	/**
	 * Initialiser un mode de jeu avant une partie
	 * Initialize a game mode before a game
	 */
	void InitMode(Mode mode);

	Mode GetMode() const;

	/**
	 * Dimensions de l'univers
	 */
	void resize(int width, int height);

	/**
	 * @return largeur de l'univers
	 */
	inline int getWidth() const {return m_width;};

	/**
	 * @return hauteur de l'univers
	 */
	inline int getHeight() const{return m_height;};


	void HandleAction(Input::Action action);

	/**
	 * Mettre à jour les entités
	 * @param frametime: temps de la frame courante
	 */
	void Update(float frametime);

	/**
	 * Ajouter une entité
	 * @param entity: entité à ajouter
	 */
	void addEntity(Entity* entity);

	/**
	 * Supprimer toutes les entités
	 */
	void Clear();

	/**
	 * @return nombre d'entités
	 */
	int Count() const;

	/**
	 * Mettre fin à la partie en cours
	 */
	void TerminateGame();

	/**
	 * Tester si le jeu est terminé
	 * @return true si game over
	 */
	bool IsGameOver();

	/**
	 * Allouer un vaisseau
	 * @param id: type du vaisseau demandé
	 * @return vaisseau
	 */
	Spaceship* CreateSpaceShip(int id) const;

	/**
	 * Obtenir une animation
	 * @param key: identifiant de l'animation
	 */
	const Animation& GetAnimation(const std::string& key) const;

	/**
	 * Charger les définitions XML des animations
	 * @param filename: fichier XML des animations
	 */
	int LoadAnimations(const std::string& filename);

	/**
	 * Charger les défintions XML des vaisseaux
	 * @param filename: fichier XML des vaisseaux
	 */
	int LoadSpaceShips(const std::string& filename);

	/**
	 * Obtenir le vaisseau du joueur
	 */
	Player* GetPlayerShip() const;

	/**
	 * Appliquer un foncteur sur chaque entité
	 * @param functor: foncteur prenant une entité en paramètre
	 */
	template <class T>
	void ApplyToEach(T& functor);

	inline float GetTimer() const { return timer_; }

	inline float GetArcadeRecord() const { return arcade_record_; }

	inline void SetArcadeRecord(float record) { arcade_record_ = record; }

	void UpdateArcadeRecord();

private:
	EntityManager();
	EntityManager(const EntityManager&);
	~EntityManager();

	void SpawnRandomEntity();
	void RegisterUniqueEntity(Entity* entity);

	// inherited
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	 * Spawner les prochains éléments du jeu en mode Arcade
	 * @return true si jeu terminé
	 */
	bool MoreBadGuys_ARCADE();

	/**
	 * Spawner les prochains éléments du jeu en mode Story
	 * @return true si jeu terminé
	 */
	bool MoreBadGuys_STORY();

	/**
	 * Ré-allouer le vaisseau du joueur
	 */
	void RespawnPlayer();

	typedef std::map<int, Spaceship*> SpaceShipMap;
	SpaceShipMap spaceships_defs_;

	typedef std::map<std::string, Animation> AnimationMap;
	AnimationMap animations_;

	typedef std::list<Entity*> EntityList;
	EntityList m_entities;

	std::vector<Entity*> uniques_;

	int m_width;
	int m_height;
	int decor_height_;

	Mode mode_;

	ParticleSystem& particles_;

	Player* m_player;
	bool (EntityManager::*more_bad_guys_)();
	bool game_over_;
	float timer_;
	int arcade_record_;
	LevelManager& levels_;

	int max_droppable_index_;
	int max_droppable_points_;

	struct ParallaxLayer: public sf::Drawable
	{
		float scrolling_speed_;
		const sf::Texture* m_texture;
		sf::Sprite background_;
		sf::Sprite background2_;
		sf::BlendMode blend_mode_;

		ParallaxLayer();
		void OnUpdate(float frametime);
		void SetScrollingTexture(const sf::Texture* image);
		void setColor(const sf::Color& color);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};

	ParallaxLayer layer1_;
	ParallaxLayer layer2_;
};


template <class T>
void EntityManager::ApplyToEach(T& functor)
{
	for (EntityList::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
	{
		functor(**it);
	}
}

#endif // ENTITYMANAGER_HPP
