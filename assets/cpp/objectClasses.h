#pragma once

#include "typeParser.h"

#include <string>
#include <cstring>

class SSCamera {
  public:
    int posX = 0;
    int posY = 0;
    float rotation = 0.0f;
    float zoom = 1.0f;
    bool smooth = true;
    Point2D target = { 0, 0 };
    Camera2D camera = { 0 };
    SSCamera(int pX, int pY, float rot, float z, int tX, int tY) {
      posX = pX;
      posY = pY;
      rotation = rot;
      zoom = z;
      target = { tX, tY };
      camera.target = { target.x + 20.0f, target.y + 20.0f };
      camera.offset = { (float)posX, (float)posY };
      camera.rotation = rotation;
      camera.zoom = zoom;
    }
};

class Player {
  public:
    int posX = 0;
    int posY = 0;
    int frameCount = 6;
    int rotation = 0;
    Color tint = WHITE;
    std::string texture = "spud-1";
    std::string textureFull;
    Texture2D player;
    void cache() {
        std::string textureLoc = fileLoc + texture + fileType;
        textureFull = textureLoc;
        player = LoadTexture(textureLoc.c_str());
    };
    void draw() {
      int frameWidth = player.width/frameCount;
      int frameHeight = player.height;

      Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
      Rectangle destRec = { (float)posX, (float)posY, frameWidth*2.0f, frameHeight*2.0f };
      Vector2 playerPosition = { (float)frameWidth, (float)frameHeight };

      DrawTexturePro(player, sourceRec, destRec, playerPosition, (float)rotation, tint);
    };
    void setAllParam(int positionX, int positionY, int screenW, int screenH, int frames, int rotation, Color textureTint, char * textureName) {
      posX = positionX;
      posY = positionY;
      frameCount = frames;
      rotation = rotation;
      tint = textureTint;
      texture = textureName;
    };
  protected:
    char *fileLoc = (char *)"assets/sprites/shuttles/player/";
    char *fileType = (char *)".png";
};

class Satellite {
  public:
    int posX = 0;
    int posY = 0;
    bool collisions = true;
    int frameCount = 6;
    int rotation = 0;
    Color tint = WHITE;
    char *idleTexture = (char *)"satellite-idle";
    char *hoverTexture = (char *)"satellite-hover";
    char *textureFull;
    Texture2D satellite;
  protected:
    char *fileLoc = (char *)"assets/sprites/objects/";
    char *fileType = (char *)".png";
};

class Projectile {
  public:
    int posX = 0;
    int posY = 0;
    bool collisions = true;
    Projectile () {

    }
  protected:
      std::string fileLoc = "assets/sprites/projectiles/";
      std::string fileType = ".png";
};