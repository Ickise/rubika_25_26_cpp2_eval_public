#include "Alien.h"

#include "AlienLaser.h"
#include "ConsoleRenderer.h"
#include "PlayField.h"
#include "Random.h"

#include <algorithm>
#include <string>

Alien::Alien() 
{
	m_objType = new char[64];
	strcpy(m_objType, "AlienShip");
	sprite = RS_Alien;
}

Alien::~Alien()
{
	delete m_objType;
}

int Alien::DecreaseHealth(int damage)
{
	health -= damage;
	health = std::max(health, 0.f);
	return static_cast<int>(health);
}

void Alien::Update(PlayField& world)
{
	pos.x += direction * velocity;
	// Border check
	if (pos.x < 0 || pos.x >= world.bounds.x - 1)
	{
		direction = -direction;
		pos.y += 1;
	}

	// Border check vertical:
	if (pos.y >= world.bounds.y - 1)
	{
		// kill player
		GameObject* player = world.GetPlayerObject();
		if (pos.IntCmp(player->pos))
		{
			world.RemoveObject(player);
		}
	}

	floatRand fireRate(0, 1);
	if (fireRate(rGen) < 0.5 && world.AlienLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new AlienLaser);
		newLaser.pos = pos;
		world.SpawnLaser(&newLaser);
	}
}