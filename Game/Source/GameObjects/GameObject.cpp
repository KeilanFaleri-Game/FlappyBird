#include "GamePCH.h"

#include "Base/Mesh.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Camera.h"
#include "GameObjects/GameObject.h"

using namespace fw;

GameObject::GameObject(Game* pGame, Mesh* pMesh, ShaderProgram* pShader, GLuint textureID, fw::vec2 position)
: m_pGame( pGame )
, m_pMesh( pMesh )
, m_pShader( pShader )
, m_TextureID( textureID )
, m_Position( position )
, m_Radius( 2 )
{
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(Camera* pCamera)
{
	if( m_pMesh != 0 )
        m_pMesh->Draw( pCamera, m_pShader, m_Position, m_TextureID );
}

bool GameObject::IsColliding(GameObject* pOtherGameObject)
{

    if (pOtherGameObject->GetPosition().x + 3.6 >= m_Position.x  &&
        pOtherGameObject->GetPosition().x - 3.6 <= m_Position.x + 12 &&
        pOtherGameObject->GetPosition().y - 3.6 <= m_Position.y + 50 &&
        pOtherGameObject->GetPosition().y + 3.6 >= m_Position.y)
    {
        return true;
    }

    return false;
}

void GameObject::OnCollision(GameObject* pOtherGameObject)
{
    m_Position = vec2(30, 50);

}