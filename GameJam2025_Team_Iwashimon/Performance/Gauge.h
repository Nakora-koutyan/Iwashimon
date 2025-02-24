#pragma once
#include "../Utility/Vector2D.h"

class Gauge
{
private:

public:
	Gauge();
	~Gauge();
	
public:
	//‰Šú‰»ˆ—
	void Initialize();
	//XVˆ—
	void Update(float delta_second);
	//•`‰æ
	void Draw()const;
	//I—¹ˆ—
	void Finalize();


	
};

