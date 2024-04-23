class CSpecialWeapon
{
public:
	const int cooldown = 180;	// number of frames to cool down
	int cooldownRemaining = 0; // remaining number of frames to cool down
	int framesSinceLastShot = 0;	// frames since last bullets spawn
	int fireDelay = 5; // frames between bullets spawn
	int numberOfShots = 3; // how many times it should spawn bullets

	bool fired = false;

	CSpecialWeapon() {}
};