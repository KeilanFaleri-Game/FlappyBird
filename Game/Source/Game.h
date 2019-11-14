#ifndef __Game_H__
#define __Game_H__

class Ball;
class Camera;
class GameObject;
class ImGuiManager;
class Mesh;
class Background;
class Player;
class Ground;
class PlayerController;

class Game : public fw::GameCore
{
protected:
    ImGuiManager* m_pImGuiManager;

    fw::ShaderProgram* m_pShaderColor;
    fw::ShaderProgram* m_pShaderTexture;
    Mesh* m_pMeshTriangle;
    Mesh* m_pMeshCircle;
    Mesh* m_pMeshBackground;
    Mesh* m_pMeshGround;
    Mesh* m_pMeshTriangle2;

    GLuint m_TextureBall;
    GLuint m_TexturePipe;
    GLuint m_TextureBackground;
    GLuint m_TextureGround;

    Background* m_pBackground;
    Player* m_pPlayer;
    Camera* m_pCamera;
    Ball* m_pPipe[3];
    Ball* m_pPipe2[3];
    Ground* m_pGround;


    PlayerController* m_pController;

public:
    Game(fw::Framework* pFramework);
    virtual ~Game();

    virtual void Init() override;
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    void CheckForCollisions();

    // Getters.
    float GetWorldWidth() { return 100.0f; }
    float GetWorldHeight() { return 100.0f; }
};

#endif //__Game_H__
