#include "GamePCH.h"

#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/Background.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Camera.h"
#include "GameObjects/Player.h"
#include "GameObjects/Ground.h"
#include "GameObjects/PlayerController.h"

using namespace fw;

Game::Game(Framework* pFramework)
: GameCore( pFramework )
{
    m_pImGuiManager = nullptr;

    m_pShaderColor = nullptr;
    m_pShaderTexture = nullptr;
    m_pMeshTriangle = nullptr;
    m_pMeshCircle = nullptr;
    m_pBackground = nullptr;
    m_TextureBall = 0;

    m_pPlayer = nullptr;
    m_pCamera = nullptr;

    m_pController = new PlayerController();
}

Game::~Game()
{
    delete m_pController;

    delete m_pPlayer;
    delete m_pCamera;
    delete[] m_pPipe;
    delete m_pBackground;
    delete m_pGround;
    delete[] m_pPipe2;

    glDeleteTextures( 1, &m_TextureBall );

    delete m_pMeshTriangle;
    delete m_pMeshCircle;
    delete m_pMeshBackground;
    delete m_pMeshGround;
    delete m_pMeshTriangle2;

    delete m_pShaderColor;
    delete m_pShaderTexture;

    delete m_pImGuiManager;
}

void Game::Init()
{
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    m_pImGuiManager = new ImGuiManager();
    m_pImGuiManager->Init();

    // Turn on v-sync.
    wglSwapInterval( 1 );

    // Create our shaders.
    m_pShaderColor = new ShaderProgram( "Data/Shaders/basic.vert", "Data/Shaders/basic.frag" );
    m_pShaderTexture = new ShaderProgram( "Data/Shaders/texture.vert", "Data/Shaders/texture.frag" );

    // Create our meshes.
    m_pMeshTriangle = new Mesh();
    m_pMeshTriangle->GenerateTriangle();

    m_pMeshCircle = new Mesh();
    m_pMeshCircle->GenerateCircle();

    m_pMeshBackground = new Mesh();
    m_pMeshBackground->GenerateBackGround();

    m_pMeshGround = new Mesh();
    m_pMeshGround->GenerateGround();

    m_pMeshTriangle2 = new Mesh();
    m_pMeshTriangle2->GenerateTriangle2();

    // Load our textures.
    m_TextureBall = LoadTexture( "Data/Textures/Bird.png" );
    m_TexturePipe = LoadTexture("Data/Textures/Pipe.png");
    m_TextureBackground = LoadTexture("Data/Textures/bg.png");
    m_TextureGround = LoadTexture("Data/Textures/Ground.png");

    // Create our GameObjects.
    m_pPlayer = new Player( this, m_pMeshCircle, m_pShaderTexture, m_TextureBall, vec2( 30, 50 ), 0, m_pController );
    m_pCamera = new Camera( this, vec2( 50, 50 ), vec2( 1/(GetWorldWidth()/2), 1/(GetWorldHeight()/2) ) );
    for (int i = 0; i < 3; i++)
    {
        m_pPipe[i] = new Ball(this, m_pMeshTriangle, m_pShaderTexture, m_TexturePipe, vec2(75 + i*50, -5));
        m_pPipe2[i] = new Ball(this, m_pMeshTriangle2, m_pShaderTexture, m_TexturePipe, vec2(75 + i*50, 65));
    }
    m_pGround = new Ground(this, m_pMeshGround, m_pShaderTexture, m_TextureGround, vec2(0, 0));
    m_pBackground = new Background(this, m_pMeshBackground, m_pShaderTexture, m_TextureBackground, vec2(0, 0));
}

void Game::OnEvent(Event* pEvent)
{
    m_pController->OnEvent( pEvent );
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame( (float)m_pFramework->GetWindowWidth(), (float)m_pFramework->GetWindowHeight(), deltaTime );

    int random = rand() % 30 - 20;

    if( m_pFramework->IsKeyDown( VK_F1 ) )
        wglSwapInterval( 0 );
    if( m_pFramework->IsKeyDown( VK_F2 ) )
        wglSwapInterval( 1 );

    m_pBackground->Update(deltaTime);
    m_pPlayer->Update( deltaTime );
    m_pCamera->Update( deltaTime );
    for (int i = 0; i < 3; i++)
    {
        m_pPipe[i]->Update(deltaTime, random);
        m_pPipe2[i]->Update(deltaTime, 70 + random);
    }
    m_pGround->Update(deltaTime);

    CheckForCollisions();
}

void Game::Draw()
{
    // Setup the values we will clear to, then actually clear the color and depth buffers.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f ); // dark blue
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Draw our game objects.
    m_pBackground->Draw(m_pCamera);
    m_pPlayer->Draw( m_pCamera );
    for (int i = 0; i < 4; i++)
    {
        m_pPipe[i]->Draw(m_pCamera);
        m_pPipe2[i]->Draw(m_pCamera);
    }
    m_pGround->Draw(m_pCamera);

    m_pImGuiManager->EndFrame();
}

void Game::CheckForCollisions()
{
    for (int i = 0; i < 4; i++)
    {
        if (m_pPipe[i]->IsColliding(m_pPlayer))
        {
            m_pPlayer->OnCollision(m_pPipe[i]);
            m_pPipe[i]->OnCollision(m_pPlayer);
        }
        if (m_pPipe2[i]->IsColliding(m_pPlayer))
        {
            m_pPlayer->OnCollision(m_pPipe2[i]);
            m_pPipe2[i]->OnCollision(m_pPlayer);
        }
    }
}
