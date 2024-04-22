#include "Game.h"

void Game::init() {}

void Game::sMovement() {}
void Game::sUserInput() {}
void Game::sRender() {}
void Game::sEnemySpawner() {}
void Game::sCollision() {}

void Game::update() {}

// future collision check
/*
	bool collision(CCollider& collider)
	{
		Vec2 diff = collider.transform.pos - transform.pos;
		return (pow(diff.x, 2) + pow(diff.y, 2)) < pow(radius + collider.radius, 2);
	}
*/

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
	lifespan = ?
	size = ?
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