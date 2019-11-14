#include "GamePCH.h"
#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "Background.h"

Background::Background(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position) : GameObject(pGame, pMesh, pShader, textureID, position)
{
}

Background::~Background()
{
}

void Background::Update(float deltaTime)
{
    m_Position.x -= 0.3f;
    if (m_Position.x <= -100.0f)
    {
        m_Position.x = 0.0f;
    }
}
