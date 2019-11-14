#pragma once
#ifndef __Background_H__
#define __Background_H__

#include "GameObject.h"

class Mesh;

class Background : public GameObject
{
protected:


public:
    Background(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position);
    ~Background();

    virtual void Update(float deltaTime);
};

#endif //__Player_H__
