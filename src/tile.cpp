#include "../include/basic.h"

Tile::Tile()
{
  this->type = TileType::STONE;
}

Tile::~Tile()
{
  ;
}

// TileType Tile::getTile(short tileCode_)
// {
//   Tile tile;
//   tile.type = TileType(tileCode_);

//   switch(TileType(tileCode_))
//   {
//     case TileType::BLANK:
//     {
//       this->ID = 0;
//       this->symbol = "  ";
//       this->interaction = Interaction::NONE;
//       this->collidable = true;
//       this->interactable = false;
//       break;
//     }
//     case TileType::STONE:
//     {
//       this->ID = 1;
//       this->symbol = ":3";
//       this->interaction = Interaction::STOP;
//       this->collidable = false;
//       this->interactable = false;
//     }
//     default: break;
//   }

//   return tile;
// }

Tile * Tile::getTilePointer(short tileCode_)
{
  Tile * tile = new Tile;
  tile->type = TileType(tileCode_);

  switch(TileType(tileCode_))
  {
    case TileType::BLANK:
    {
      tile->ID = 0;
      tile->symbol = "  ";
      tile->interaction = Interaction::NONE;
      tile->collidable = true;
      tile->interactable = false;
      break;
    }
    case TileType::STONE:
    {
      tile->ID = 1;
      tile->symbol = ":3";
      tile->interaction = Interaction::STOP;
      tile->collidable = false;
      tile->interactable = false;
    }
    default: break;
  }

  return tile;
}

bool Tile::collision(Entity *)
{
  ;
}