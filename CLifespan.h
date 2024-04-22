class CLifespan
{
public:
	int total		= 0;	//initial number of frames
	int remaining	= 0;	//number of frames left to live

	CLifespan(int total)
		: total(total), remaining(total) {}
};