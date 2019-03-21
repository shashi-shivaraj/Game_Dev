#include <string>
#include <SDL.h>

class FrameGenerator {
public:
  FrameGenerator();
  ~FrameGenerator(); //to satisfy rule of three
  FrameGenerator(const FrameGenerator&) = delete; //copy constructor operation invalid
  FrameGenerator& operator=(const FrameGenerator&) = delete; //copy assignment constructor operation invalid
  void makeFrame();
  unsigned int getFrameCount() const { return frameCount; }
private:
  SDL_Renderer* const rend;
  SDL_Window* const window;
  const int WIDTH;
  const int HEIGHT;
  const std::string USERNAME;
  const int MAX_FRAMES;
  int frameCount;
};
