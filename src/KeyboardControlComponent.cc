#include "KeyboardControlComponent.hh"

KeyboardControlComponent::KeyboardControlComponent()
{
}

KeyboardControlComponent::KeyboardControlComponent(std::string upKey, std::string downKey, std::string leftKey, std::string rightKey, std::string shootKey)
{
  
}


KeyboardControlComponent::~KeyboardControlComponent()
{
}

std::string KeyboardControlComponent::GetSDLKeyStringCode(std::string key)
{
  if(key.compare("up") == 0) return "";
  if(key.compare("down") == 0) return "";
  if(key.compare("left") == 0) return "";
  if(key.compare("right") == 0) return "";
}