#pragma once

#include "GameObject.h"

class Game;

class Ground : public GameObject
{

protected:


public:
    Ground(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position);
    ~Ground();

    virtual void Update(float deltaTime);

    virtual void OnCollision(GameObject* pOtherGameObject);
};

