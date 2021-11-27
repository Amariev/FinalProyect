#ifndef TILE_H_
#define TILE_H_

enum TileType { BLANK = 0, STONE };

class Tile : public Stable
{
  TileType type;

  public:
    Tile();
    virtual ~Tile();

    virtual bool collision(Entity *);

    TileType getTileType();
    Tile * getTilePointer(short);
    Tile getTile(short);
};

#endif
