#include "typeParser.h"

class SSCamera {
  public:
    int posX = 0;
    int posY = 0;
    int rotation = 0;
    bool smooth = true;
};

class Player {
  public:
    int posX = 0;
    int posY = 0;
    int frameCount = 6;
    int rotation = 0;
    Color tint = WHITE;
    char *texture = (char *)"spud-1";
    char *textureFull;
    Texture2D player;
    void cache() {
      const char * textureComb[3] = {
        fileLoc,
        texture,
        fileType
      };
      char * out;
      const char *textureLoc = combineChar(out, textureComb);
      textureFull = (char *)textureLoc;
      player = LoadTexture(textureLoc);
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
    char *fileLoc = (char *)"assets/sprites/projectiles/";
    char *fileType = (char *)".png";
};