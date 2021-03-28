#include "schiggy.h"

Schiggy::Schiggy() : Pokemon(at_tackle, at_blubber){
    attack1Name = "Tackle";
    attack2Name = "Blubber";
    name = "Schiggy";
    maxhp = 38;
    hp = maxhp;
    def = 29;
    ap = 26;
    initiative = 25;
    status = ef_none;
}

Schiggy::~Schiggy(){}
