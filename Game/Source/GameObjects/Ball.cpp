#include "GamePCH.h"

#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Ball.h"
#include "Game.h"

using namespace fw;

Ball::Ball(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position)
: GameObject( pGame, pMesh, pShader, textureID, position )
{
}
    
Ball::~Ball()
{
}

void Ball::Update(float deltaTime, int random)
{
    m_Position.x -= 0.5f;
    if (m_Position.x <= -40.0f)
    {
        m_Position.x = 100.0f;
        m_Position.y = random;
    }
}

void Ball::OnCollision(GameObject* pOtherGameObject)
{

}
