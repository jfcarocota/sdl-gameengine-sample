#include "Game.hh"

SDL_Renderer* Game::renderer;
EntityManager manager;

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

  isRunning = true;
}

bool Game::IsRunning() const
{
  return isRunning;
}

void Game::ProcessInput()
{
  SDL_Event event;
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
}

void Game::Render()
{
  
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);
  
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

}
