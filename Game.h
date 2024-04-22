#pragma once

#include "Common.h"
#include "EntityManager.h"

struct PlayerConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V; float S; };
struct EnemyConfig { int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI; float SMIN, SMAX; };
struct BulletConfig { int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L; float S; };


class Game
{
	sf::RenderWindow	m_window;
	EntityManager		m_entities;
	sf::Font			m_font;
	sf::Text			m_text;
	PlayerConfig		m_playerCfg;
	EnemyConfig			m_enemyCfg;
	BulletConfig		m_bulletCfg;
	int					m_score = 0;
	int					m_currentFrame = 0;
	int					m_framesSinceLastEnemySpawn = -1;
	bool				m_paused = false;
	bool				m_running = true;

	std::shared_ptr<Entity> m_player;

	void init(const std::string& cfgFilePath);
	void setPaused(bool paused);

	void sMovement();
	void sUserInput();
	void sLifespan();
	void sEnemySpawner();
	void sCollision();
	void sRender();

	void spawnPlayer();
	void spawnEnemy();
	void spawnSmallEnemies(std::shared_ptr<Entity> entity);
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& target);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity, const Vec2& target);

public:
	Game(const std::string& cfgFilePath);

	void run();
};