#include "Game.hh"
#include "TransformComponent.hh"
#include "SpriteComponent.hh"
#include "KeyboardControlComponent.hh"
#include "AudioListenerComponent.hh"

EntityManager manager;
AssetManager* Game::assetManager{new AssetManager(&manager)};
SDL_Renderer* Game::renderer;
SDL_Event Game::event;


Game::Game()
{

}

Game::~Game()
{

}

void Game::Initialize(unsigned int windowWidth, unsigned int windowHeight)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cerr << "[Error]: SDL Initialazing filed..." << std::endl;
    return;
  }

  window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);

  if(!window)
  {
    std::cerr << "[Error]: Error creating SDL window" << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if(!renderer)
  {
    std::cerr << "[Error]: Error creating SDL Renderer" << std::endl;
    return;
  }

  //Initialize SDL_mixer
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
  {
      printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
      return;
  }

  LoadLevel(0);
  isRunning = true;
  return;
}

bool Game::IsRunning() const
{
  return isRunning;
}

void Game::ProcessInput()
{
  SDL_PollEvent(&event);
  switch (event.type)
  {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      if(event.key.keysym.sym == SDLK_ESCAPE)
      {
        isRunning = false;
      }
      break;
    default: break;
  }
}

void Game::Update()
{
  int timeToWait{FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame)};
  if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
  {
    SDL_Delay(timeToWait);
  }

  float deltaTime{(SDL_GetTicks() - ticksLastFrame) / 1000.f};
  deltaTime = deltaTime > 0.05f ? 0.05f : deltaTime;
  ticksLastFrame = SDL_GetTicks();
  manager.Update(deltaTime);
}

void Game::Render()
{
  
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);
  if(manager.HasNoEntities()) return;
  manager.Render();
  SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::LoadLevel(int level)
{
  /*Load assets*/
  assetManager->AddTexture("red-image", std::string("./assets/images/red.png").c_str());
  assetManager->AddTexture("oldguy-image", std::string("./assets/images/oldguy.png").c_str());

  /*creating antities*/
  /*Entity& redEntity(manager.AddEntity("red"));
  redEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 313, 685, 1);
  redEntity.AddComponent<SpriteComponent>("red-image");*/

  Entity& oldguyEntity(manager.AddEntity("oldguy"));
  oldguyEntity.AddComponent<TransformComponent>(240, 106, 0, 0, 13.5, 13.5, 4);
  oldguyEntity.AddComponent<SpriteComponent>("oldguy-image", 6, 60, true, false);
  oldguyEntity.AddComponent<KeyboardControlComponent>(200.f);
  oldguyEntity.AddComponent<AudioListenerComponent>();
}
