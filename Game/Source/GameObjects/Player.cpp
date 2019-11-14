#include "GamePCH.h"

#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Player.h"
#include "GameObjects/PlayerController.h"

using namespace fw;

Player::Player(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, GLuint textureID, fw::vec2 position, int playerNum, PlayerController* pController)
: GameObject( pGame, pMesh, pShader, textureID, position )
, m_PlayerNumber( playerNum )
, m_pController( pController )
{
    time = 0.0f;
}
    
Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    //GameObject::Update( deltaTime, pFramework );

    float speed = 30;
    vec2 dir( 0, 0 );

    if (m_pController->m_Up && time <= 0.5f)
    {
        dir.y = 2;
        time += deltaTime;
    }
    else if (!(m_pController->m_Up) && time >= 0.5f)
    {
        time = 0.0f;
    }
    else
    {
        dir.y = -1;
    }

    if (m_Position.y <= 10)
    {
        m_Position = vec2(30, 50);
    }

    m_Position += dir * speed * deltaTime;

    // Get the world width and height
    float worldWidth = m_pGame->GetWorldWidth();
    float worldHeight = m_pGame->GetWorldHeight();

    Clamp( m_Position.x, 0.0f, worldWidth );
    Clamp( m_Position.y, 0.0f, worldHeight );
}
