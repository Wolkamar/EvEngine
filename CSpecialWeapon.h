class CSpecialWeapon
{
public:
	const int cooldown = 180;	// number of frames to cool down
	int cooldownRemaining = 0;
	int fireDelay = 10; // frames between bullets spawn
	int fireDelayRemaining = 0;
	int numberOfShots = 3; // how many times it should spawn bullets
	int numberOfShotsRemaining = 0;

	bool firing = false;
	bool canFire = true;

	CSpecialWeapon() {}
};