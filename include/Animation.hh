#pragma once

class Animation
{
public:
  unsigned int index{0};
  unsigned int numFrames{0};
  unsigned int animationSpeed{1};

  Animation();
  Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
  ~Animation();
};
