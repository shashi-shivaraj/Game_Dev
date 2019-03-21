#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"

class Engine {
public:
  Engine ();
  ~Engine (); //user defined destructor - so rule of three applies
  void play();
  void switchSprite();

  Engine(const Engine&) = delete; //copy constructor operation invalid
  Engine& operator=(const Engine&) = delete; //copy assignment operation invalid

private:
  const RenderContext& rc;
  const IoMod& io;
  Clock& clock;

  SDL_Renderer * const renderer;
  World world;
  Viewport& viewport;

  Drawable* star;
  Drawable* spinningStar;
  int currentSprite;

  bool makeVideo;

  void draw() const;
  void update(Uint32);


  void printScales() const;
  void checkForCollisions();
};
