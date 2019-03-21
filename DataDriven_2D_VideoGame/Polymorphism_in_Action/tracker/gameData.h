#ifndef GAMEDATA__H
#define GAMEDATA__H
#include <string>
#include <map>
#include "vector2f.h"
#include "parseXML.h"

class Gamedata {
public:
  static Gamedata& getInstance();
  ~Gamedata(); //rule of three -user defined destructor
  void displayData() const;

  bool getXmlBool(const std::string&) const;
  const std::string& getXmlStr(const std::string&) const;
  float getXmlFloat(const std::string&) const;
  int getXmlInt(const std::string&) const;
  float getRandInRange(int min, int max) const;
  float getRandFloat(float min, float max) const;
  bool  checkTag(const std::string&)const;

  Gamedata(const Gamedata&) = delete; //rule of three - user defined copy constructor
  Gamedata& operator=(const Gamedata&) = delete;//rule of three - user defined copy assignment

private:
  ParseXML parser;
  const map<std::string, std::string> gameData;

  Gamedata(const std::string& fn = "xmlSpec/game.xml");
};
#endif
