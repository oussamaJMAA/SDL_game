#include "col_mvt.h"

 int collide(Hero *player, Hero *monster)
 {
    if ((player->x >= monster->x + monster->w)
    || (player->x + player->w <= monster->x)
    || (player->y >= monster->y + monster->h)
    || (player->y + player->h <= monster->y)
    )
        return 0;

    else
        return 1;
}

 int col_et(Hero *player, Etoile *etoile)
 {
    if ((player->x >= etoile->x + etoile->w))return 0;
    else if (player->x + player->w <= etoile->x)return 0;
    else if (player->y >= etoile->y + etoile->h)return 0;
    else if (player->y + player->h <= etoile->y)

    
        return 0;

    
        else return 1;

}
