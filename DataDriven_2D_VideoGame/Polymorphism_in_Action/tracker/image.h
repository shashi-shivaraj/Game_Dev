#ifndef IMAGE__H
#define IMAGE__H

#include <iostream>
#include <string>
#include <SDL.h>

class Image {
public:
  Image() = delete; //default contructor probibited
  Image(SDL_Surface*);
  Image(const Image&); //user defined copy constructor
  Image& operator=(const Image&);//user defined copy assignment
  ~Image(); //user defined destructor - as per rule of three 


  void regenerateTexture();
  void draw(int x, int y) const;
  void draw(int x, int y, float scale) const;
  void draw(int sx, int sy, int dx, int dy) const;

  inline int getWidth()  const { return surface->w; }
  inline int getHeight() const { return surface->h; }
  SDL_Surface* getSurface() const { return surface; }
  Image* crop(SDL_Rect)const;
private:
  SDL_Renderer * renderer;
  SDL_Surface * surface;
  SDL_Texture * texture; //class Image makes texture so only it should delete it 
  SDL_Rect view;
};

#endif
