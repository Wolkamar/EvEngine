#include "Game.h"

Game::Game(const std::string& cfgFilePath)
{
	init(cfgFilePath);
}

void Game::init(const std::string& cfgFilePath)
{
	srand(time(NULL));

	std::ifstream fin(cfgFilePath);
	std::string lineHead;

	fin >> lineHead;

	if (lineHead != "Window") std::cerr << "Unable to read Window parameters";

	int wWidth, wHeight, frameLimit;
	bool fullScreen;

	fin >> wWidth >> wHeight >> frameLimit >> fullScreen;

	if (fullScreen)
	{
		m_window.create(sf::VideoMode(wWidth, wHeight), "Assignment 2", sf::Style::Fullscreen);
	}
	else
	{
		m_window.create(sf::VideoMode(wWidth, wHeight), "Assignment 2");
	}

	m_window.setFramerateLimit(frameLimit);

	fin >> lineHead;

	if (lineHead != "Font") std::cerr << "Unable to read Font parameters";

	std::string fontPath;
	int fontSize, fontR, fontG, fontB;

	fin >> fontPath >> fontSize >> fontR >> fontG >> fontB;

	m_font = sf::Font();
	m_font.loadFromFile(fontPath);

	m_text = sf::Text("Score: 0", m_font, fontSize);
	m_text.setFillColor(sf::Color(fontR, fontB, fontB));

	fin >> lineHead;

	if (lineHead != "Player") std::cerr << "Unable to read Player parameters";

	fin >> m_playerCfg.SR >> m_playerCfg.CR >> m_playerCfg.S >> m_playerCfg.FR
		>> m_playerCfg.FG >> m_playerCfg.FB >> m_playerCfg.OR >> m_playerCfg.OG
		>> m_playerCfg.OB >> m_playerCfg.OT >> m_playerCfg.V;

	fin >> lineHead;

	if (lineHead != "Enemy") std::cerr << "Unable to read Enemy parameters";

	fin >> m_enemyCfg.SR >> m_enemyCfg.CR >> m_enemyCfg.SMIN >> m_enemyCfg.SMAX
		>> m_enemyCfg.OR >> m_enemyCfg.OG >> m_enemyCfg.OB >> m_enemyCfg.OT
		>> m_enemyCfg.VMIN >> m_enemyCfg.VMAX >> m_enemyCfg.L >> m_enemyCfg.SI;

	fin >> lineHead;

	if (lineHead != "Bullet") std::cerr << "Unable to read Bullet parameters";

	fin >> m_bulletCfg.SR >> m_bulletCfg.CR >> m_bulletCfg.S >> m_bulletCfg.FR
		>> m_bulletCfg.FG >> m_bulletCfg.FB >> m_bulletCfg.OR >> m_bulletCfg.OG
		>> m_bulletCfg.OB >> m_bulletCfg.OT >> m_bulletCfg.V >> m_bulletCfg.L;

	spawnPlayer();
}

void Game::run()
{
	while (m_running)
	{
		m_entities.update();

		sUserInput();

		if (!m_paused)
		{
			sEnemySpawner();
			sCollision();
			sMovement();
			sLifespan();

			m_currentFrame++;
		}

		sRender();
	}
}

void Game::setPaused(bool paused)
{
	m_paused = paused;
}
void Game::togglePaused()
{
	m_paused = !m_paused;
}

void Game::exit()
{
	m_running = false;
}

void Game::sMovement()
{
	Vec2 playerVelocity(0, 0);

	if (m_player->cInput->right) playerVelocity.x += 1.f;
	if (m_player->cInput->left) playerVelocity.x -= 1.f;
	if (m_player->cInput->up) playerVelocity.y -= 1.f;
	if (m_player->cInput->down) playerVelocity.y += 1.f;

	playerVelocity.normalize();

	playerVelocity *= m_playerCfg.S;

	if (m_player->cTransform->pos.x + playerVelocity.x - m_player->cCollider->radius <= 0 ||
		m_player->cTransform->pos.x + playerVelocity.x + m_player->cCollider->radius >= m_window.getSize().x)
	{
		playerVelocity.x *= -1.f;
	}
	if (m_player->cTransform->pos.y + playerVelocity.y - m_player->cCollider->radius <= 0 ||
		m_player->cTransform->pos.y + playerVelocity.y + m_player->cCollider->radius >= m_window.getSize().y)
	{
		playerVelocity.y *= -1.f;
	}

	m_player->cTransform->velocity = playerVelocity;

	for (auto& e : m_entities.getEntities())
	{
		e->cTransform->pos += e->cTransform->velocity;
	}
}
void Game::sUserInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->up = true;
				break;
			case sf::Keyboard::A:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->left = true;
				break;
			case sf::Keyboard::S:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->down = true;
				break;
			case sf::Keyboard::D:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->right = true;
				break;
			case sf::Keyboard::P:
				togglePaused();
				break;
			case sf::Keyboard::Escape:
				exit();
				break;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->up = false;
				break;
			case sf::Keyboard::A:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->left = false;
				break;
			case sf::Keyboard::S:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->down = false;
				break;
			case sf::Keyboard::D:
				for (auto& p : m_entities.getEntities("Player")) p->cInput->right = false;
				break;
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Left:
				for (auto& p : m_entities.getEntities("Player"))
				{
					spawnBullet(p, Vec2(event.mouseButton.x, event.mouseButton.y));
				}
				break;
			case sf::Mouse::Right:
				for (auto& p : m_entities.getEntities("Player"))
				{
					spawnSpecialWeapon(p);
				}
				break;
			}
		}
	}
}
void Game::sLifespan()
{
	for (auto& e : m_entities.getEntities())
	{
		if (!e->cLifespan) continue;

		if (e->cLifespan->remaining > 0)
		{
			e->cLifespan->remaining--;

			const float alpha = 255.f * ((float)e->cLifespan->remaining / (float)e->cLifespan->total);

			sf::Color fillColor = e->cShape->circle.getFillColor();
			fillColor.a = alpha;
			e->cShape->circle.setFillColor(fillColor);

			sf::Color outlineColor = e->cShape->circle.getOutlineColor();
			outlineColor.a = alpha;
			e->cShape->circle.setOutlineColor(outlineColor);
		}
		else
		{
			e->kill();
		}
	}

	for (auto& p : m_entities.getEntities("Player"))
	{
		if (p->cSpecialWeapon->fired && p->cSpecialWeapon->cooldownRemaining > 0)
		{
			p->cSpecialWeapon->cooldownRemaining--;
		}
		else
		{
			p->cSpecialWeapon->fired = false;
		}
	}
}
void Game::sEnemySpawner()
{
	if (++m_framesSinceLastEnemySpawn >= m_enemyCfg.SI)
	{
		spawnEnemy();

		m_framesSinceLastEnemySpawn = 0;
	}
}

void Game::sCollision()
{
	for (auto& p : m_entities.getEntities("Player"))
	{
		for (auto& e : m_entities.getEntities("Enemy"))
		{
			if (Utils::areCollide(p, e))
			{
				resetPlayerPos();
			}
		}
		for (auto& se : m_entities.getEntities("SmallEnemy"))
		{
			if (Utils::areCollide(p, se))
			{
				resetPlayerPos();
			}
		}
	}

	for (auto& b : m_entities.getEntities("Bullet"))
	{
		for (auto& e : m_entities.getEntities("Enemy"))
		{
			if (Utils::areCollide(b, e))
			{
				m_player->cScore->score += e->cScore->score;
				spawnSmallEnemies(e);
				e->kill();
				b->kill();
			}
		}
		for (auto& se : m_entities.getEntities("SmallEnemy"))
		{
			if (Utils::areCollide(b, se))
			{
				m_player->cScore->score += se->cScore->score;
				se->kill();
				b->kill();
			}
		}
	}

	for (auto& e : m_entities.getEntities())
	{
		if (e->cTransform->pos.x - e->cCollider->radius <= 0 ||
			e->cTransform->pos.x + e->cCollider->radius >= m_window.getSize().x)
		{
			e->cTransform->velocity.x *= -1.f;
		}
		if (e->cTransform->pos.y - e->cCollider->radius <= 0 ||
			e->cTransform->pos.y + e->cCollider->radius >= m_window.getSize().y)
		{
			e->cTransform->velocity.y *= -1.f;
		}
	}
}

void Game::sRender()
{
	m_window.clear();

	for (auto& e : m_entities.getEntities())
	{
		e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);

		e->cTransform->angle += 3.f;
		e->cShape->circle.setRotation(e->cTransform->angle);

		m_window.draw(e->cShape->circle);
	}

	std::stringstream scoreString;
	scoreString << "Score: " << m_player->cScore->score;
	m_text.setString(scoreString.str());
	m_window.draw(m_text);

	m_window.display();
}

void Game::spawnPlayer()
{
	auto entity = m_entities.addEntity("Player");

	sf::Color fillColor(m_playerCfg.FR, m_playerCfg.FG, m_playerCfg.FB);
	sf::Color outlineColor(m_playerCfg.OR, m_playerCfg.OG, m_playerCfg.OB);

	entity->cTransform = std::make_shared<CTransform>();

	entity->cShape = std::make_shared<CShape>(m_playerCfg.SR, m_playerCfg.V, fillColor, outlineColor, m_playerCfg.OT);

	entity->cCollider = std::make_shared<CCollider>(m_playerCfg.CR);

	entity->cInput = std::make_shared<CInput>();

	entity->cScore = std::make_shared<CScore>();

	entity->cSpecialWeapon= std::make_shared<CSpecialWeapon>();

	m_player = entity;

	resetPlayerPos();
}
void Game::resetPlayerPos()
{
	m_player->cTransform->pos = Vec2(m_window.getSize().x / 2, m_window.getSize().y / 2);
}
void Game::spawnEnemy()
{
	auto entity = m_entities.addEntity("Enemy");

	const int collisionRadius = m_enemyCfg.CR;
	const float randX = Utils::random(collisionRadius, m_window.getSize().x - collisionRadius);
	const float randY = Utils::random(collisionRadius, m_window.getSize().y - collisionRadius);

	const float randSpeed = Utils::random(m_enemyCfg.SMIN, m_enemyCfg.SMAX);

	Vec2 position = Vec2(randX, randY);

	Vec2 velocity = Vec2(1.f, 0.f);

	velocity.rotateByDegrees(Utils::random(0, 359));

	velocity *= randSpeed;

	entity->cTransform = std::make_shared<CTransform>(position, velocity);

	const int randFillR = Utils::random(0, 255);
	const int randFillG = Utils::random(0, 255);
	const int randFillB = Utils::random(0, 255);

	sf::Color fillColor(randFillR, randFillG, randFillB);

	const int outlineR = m_enemyCfg.OR;
	const int outlineG = m_enemyCfg.OG;
	const int outlineB = m_enemyCfg.OB;

	sf::Color outlineColor(outlineR, outlineG, outlineB);

	const int vertices = Utils::random(m_enemyCfg.VMIN, m_enemyCfg.VMAX);

	entity->cShape = std::make_shared<CShape>(m_enemyCfg.SR, vertices, fillColor, outlineColor, m_enemyCfg.OT);

	entity->cCollider = std::make_shared<CCollider>(collisionRadius);

	entity->cScore = std::make_shared<CScore>(vertices * 100);
}
void Game::spawnSmallEnemies(std::shared_ptr<Entity> entity)
{
	int vertices = entity->cShape->circle.getPointCount();

	sf::Color fillColor = entity->cShape->circle.getFillColor();
	sf::Color outlineColor = entity->cShape->circle.getOutlineColor();

	const int collisionRadius = m_enemyCfg.CR;

	const float x = entity->cTransform->pos.x;
	const float y = entity->cTransform->pos.y;

	const float velX = entity->cTransform->velocity.x;
	const float velY = entity->cTransform->velocity.y;

	const int score = entity->cScore->score * 2;

	Vec2 velocity = Vec2(velX, velY);

	for (size_t i = 0; i < vertices; i++)
	{
		auto smallEntity = m_entities.addEntity("SmallEnemy");

		float degrees = (float)i * (360.f / (float)vertices);

		smallEntity->cTransform = std::make_shared<CTransform>(Vec2(x, y), velocity.rotatedByDegrees(degrees));

		smallEntity->cShape = std::make_shared<CShape>(m_enemyCfg.SR / 2, vertices, fillColor, outlineColor, m_enemyCfg.OT);

		smallEntity->cCollider = std::make_shared<CCollider>(collisionRadius / 2);

		smallEntity->cScore = std::make_shared<CScore>(score);

		smallEntity->cLifespan = std::make_shared<CLifespan>(m_enemyCfg.L);
	}
}
void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& target)
{
	Vec2 direction = (target - m_player->cTransform->pos).normalized();
	Vec2 velocity = direction * m_bulletCfg.S;
	Vec2 position = entity->cTransform->pos + direction * entity->cCollider->radius;

	auto bulletEntity = m_entities.addEntity("Bullet");

	const int collisionRadius = m_bulletCfg.CR;

	bulletEntity->cTransform = std::make_shared<CTransform>(position, velocity);

	const int randFillR = m_bulletCfg.FR;
	const int randFillG = m_bulletCfg.FG;
	const int randFillB = m_bulletCfg.FB;

	sf::Color fillColor(randFillR, randFillG, randFillB);

	const int outlineR = m_bulletCfg.OR;
	const int outlineG = m_bulletCfg.OG;
	const int outlineB = m_bulletCfg.OB;

	sf::Color outlineColor(outlineR, outlineG, outlineB);

	const int vertices = entity->cShape->circle.getPointCount();

	bulletEntity->cShape = std::make_shared<CShape>(m_bulletCfg.SR, vertices, fillColor, outlineColor, m_bulletCfg.OT);

	bulletEntity->cCollider = std::make_shared<CCollider>(collisionRadius);

	bulletEntity->cLifespan = std::make_shared<CLifespan>(m_bulletCfg.L);
}
void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{
	if (entity->cSpecialWeapon->fired) return;

	std::cout << "fire\n";

	entity->cSpecialWeapon->fired = true;
	entity->cSpecialWeapon->cooldownRemaining = entity->cSpecialWeapon->cooldown;
}

//order
/*
	0. Save the configuration file reading until later, after Entities implemented
	1. Implement the Vec2 class, which you will use for all Components
	2. Implement the basic functionality in the EntityManager class
		Implement the EntityManager's addEntity() and update() functions so you can start testing the Game class quickly.
		Don't worry about the update() function which deletes dead entities until later when you get more game mechanics working.
	3. Implement basics of the Game class:
		a. Construct a player Entity using the spawnPlayer () function
		b. Implement basic drawing of entities using the Game::sRender() function
		c. Construct some enemies using the spawnEnemy () function
		d. Construct a bullet using the spawnBullet() function
	4. Implement Player Movement in Game:: sUserInput and Game:: sMovement
	5. Implement the EntityManager: :update () function so it deletes dead entities
	6. Implement the EntityManager:: getEntities(tag) functionality
	7. Implement collisions in sCollision and entity.destroy() if it's dead
	8. Implement the rest of the game's functionality, including config file reading
*/

//rules
//player 
/*
	start and respawn in center
	WASD controls
	only in window bounds
	shoot to mouse position on LMB click
	has Special Ability
*/
//Special Ability
/*
	on RMB click, shoot multiple bullets — three from each player edge,
	plus 2 seconds of invulnerability,
	plus killing area with size of 3 player radiuses in these 2 seconds

	special weapon
	unique graphics
	new component
	cooldown timer
*/

//enemies
/*
	rand spawn position (in screen bounds)
	rand vertices number in range
	rand color
	rand speed in range

	bounce of window edges (like in Assignment 1)

	large enemies spawn shards with same color and same shape:
	amount = edges number
	directions = edges
	angles = 360/edges number
*/

//score
/*
	enemies spawn with CScore component with value of 100N
	N = edges number
	small enemies get double of this value
	add score to player when it kills an enemy
	top left of the screen
*/

//render
/*
	all entities have slow rotation

	color
	alpha = ratio of how long entity left to live
*/

//misc
/*
	P - pause
	ESC - close the game
*/

//cfg values
/*
	window size

	font of score

	shape and speed of the Player

	speed, size and lifespan of Bullets

	Enemies:
	spawn frequency
	vertices range (min and max)
	shape radius
	speed range (min and max)

Syntax:

Window W H FL FS									Width	Height	FrameLimit	FullScreen
Font F S R G B										File	Size	Color(RGB)
Player SR CR S FR FG FB OR OG OB OT V				SRad	CRad	Speed		Fill(RGB)	Out(RGB)	OutThick	Vertices
Enemy SR CR SMIN SMAX OR OG OB OT VMIN VMAX L SI	SRad	CRad	SpeedMX		Out(RGB)	OutThick	VerticesMX	Lifespan	SpawnInterval
Bullet SR CR S FR FG FB OR OG OB OT V L				SRad	CRad	Speed		Fill(RGB)	Out(RGB)	OutThick	Vertices	Lifespan

*/