#include "PlayField.h"

#include "GameObject.h"
#include "Input.h"

PlayField::PlayField(const Vector2D& iBounds)
{
    bounds = iBounds;
    controllerInput = new RndInput();
}

void PlayField::Update()
{
    // Update list of active objects in the world
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Update(*this);
    }
}

GameObject* PlayField::GetPlayerObject()
{
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObject* in) { return (strcmp(in->m_objType, "PlayerShip") == 0); });
    if (it != gameObjects.end())
        return (*it);
    else
        return nullptr;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
    if (strcmp(newObj->m_objType, "AlienLaser") == 0)
        AlienLasers--;

    else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
        PlayerLasers--;

    AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
    if (strcmp(newObj->m_objType, "AlienLaser") == 0)
        AlienLasers++;

    else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
        PlayerLasers++;

    RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
    gameObjects.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
    auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* in) { return (in == newObj); });
    delete *it;
    gameObjects.erase(it);
}