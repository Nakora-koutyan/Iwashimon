#pragma once
#include "../Utility/Vector2D.h"
#include "DxLib.h"

#define SCREEN_HEIGHT (480)
#define SCREEN_WIDTH (640)

#define STAGE_WIDTH (2400.0f)
#define STAGE_HEIGHT (900.0f)

class ObjectBase
{
protected:
	Vector2D world_pos;
	Vector2D obj_size;

	int image;
	int reverse_image;

public:
	ObjectBase();
	~ObjectBase();

public:
	virtual void Initialize();
	virtual void Update(float delta_second);
	virtual void Draw(Vector2D target_pos)const;
	virtual void Finalize();

	virtual void OnCollisionEnter(ObjectBase* obj);

public:
	bool CollisionHit(ObjectBase* obj);

public:
	Vector2D GetLocation() const { return world_pos; }
	void SetLocation(Vector2D location);

	Vector2D GetBoxSize()const { return obj_size; }
};