#include "glumanda.h"

Glumanda::Glumanda() : Pokemon(at_kratzer, at_glut){
    attack1Name = "Kratzer";
    attack2Name = "Glut";
    name = "Glumanda";
    maxhp = 37;
    hp = maxhp;
    def = 25;
    ap = 26;
    initiative = 29;
    status = ef_none;
}

Glumanda::~Glumanda(){}
