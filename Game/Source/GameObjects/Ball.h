#ifndef __Ball_H__
#define __Ball_H__

#include "GameObject.h"

class Game;

class Ball : public GameObject
{

protected:


public:
    Ball(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position);
    ~Ball();

    virtual void Update(float deltaTime, int random);
    
    virtual void OnCollision(GameObject* pOtherGameObject);
};

#endif //__Ball_H__
