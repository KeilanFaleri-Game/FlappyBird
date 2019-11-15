#include "GamePCH.h"
#include "Ground.h"
#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"


Ground::Ground(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position) : GameObject(pGame, pMesh, pShader, textureID, position)
{
}

Ground::~Ground()
{
}

void Ground::Update(float deltaTime)
{
    m_Position.x -= 0.5f;
    if (m_Position.x <= -10.0f)
    {
        m_Position.x = 100.0f;
    }
}

void Ground::OnCollision(GameObject* pOtherGameObject)
{
}
