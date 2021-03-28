#include <iostream>
#include <assert.h>
#include <time.h>
#include <string>
#include "pokemon.h"

void Pokemon::selectAttack(def_attack attack, def_attackSlot attackSlot){
    if(attackSlot == sl_attackSlot1){
        switch(attack){
            case at_tackle:
                this->attack1 = &Pokemon::tackle;
            break;

            case at_blubber:
                this->attack1 = &Pokemon::blubber;
            break;

            case at_kratzer:
                this->attack1 = &Pokemon::kratzer;
            break;

            case at_glut:
                this->attack1 = &Pokemon::glut;
            break;
        }
    }else if(attackSlot == sl_attackSlot2){
        switch(attack){
            case at_tackle:
                this->attack2 = &Pokemon::tackle;
            break;

            case at_blubber:
                this->attack2 = &Pokemon::blubber;
            break;

            case at_kratzer:
                this->attack2 = &Pokemon::kratzer;
            break;

            case at_glut:
                this->attack2 = &Pokemon::glut;
            break;
        }
    }else{
        assert (attackSlot == sl_attackSlot1 || attackSlot == sl_attackSlot2);
    }
}

Pokemon::Pokemon(def_attack attack1, def_attack attack2){
    selectAttack(attack1, sl_attackSlot1);
    selectAttack(attack2, sl_attackSlot2);
}

Pokemon::Pokemon(){}

//überprüfung beheben
int Pokemon::getSkillpointInput(){
    std::string input;
    int eingabe = -1;

    while(eingabe < 0 || eingabe > this->skillPoints){
        std::cin >> input;
        eingabe = std::stoi(input);
        if(eingabe < 0 || eingabe > this->skillPoints){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            Pokemon::skillPoints -= eingabe;
            return eingabe;
        }
    }
    return 0;
}

void Pokemon::setCustomAttacks(){
    int eingabe = -1;
    std::string AttackInput;

    std::cout << "Welche angriffe soll das Pokemon haben?" << std::endl << "  Tackle(1)" << std::endl << "  Kratzer(2)" << std::endl << "  Glut(3)" << std::endl << "  Blubber(4)" << std::endl << "Deine Eingabe: ";
    while(eingabe < 1 || eingabe > 4){
        std::cin >> AttackInput;
        eingabe = std::stoi(AttackInput);
        if(eingabe < 1 || eingabe > 4){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            switch(eingabe){
                case 1:
                    selectAttack(at_tackle, sl_attackSlot1);
                    Pokemon::attack1Name = "Tackle";
                break;

                case 2:
                    selectAttack(at_kratzer, sl_attackSlot1);
                    Pokemon::attack1Name = "Kratzer";
                break;

                case 3:
                    selectAttack(at_glut, sl_attackSlot1);
                    Pokemon::attack1Name = "Glut";
                break;

                case 4:
                    selectAttack(at_blubber, sl_attackSlot1);
                    Pokemon::attack1Name = "Blubber";
                break;

                default:
                    selectAttack(at_tackle, sl_attackSlot1);
                    Pokemon::attack1Name = "Tackle";
            }
            break;
        }
    }
//setzt eingabe zurück
    eingabe = -1;
    AttackInput = "";

    std::cout << "  Tackle(1)" << std::endl << "  Kratzer(2)" << std::endl << "  Glut(3)" << std::endl << "  Blubber(4)" << std::endl << "Deine Eingabe: ";

    while(eingabe < 1 || eingabe > 4){
        std::cin >> AttackInput;
        eingabe = std::stoi(AttackInput);
        if(eingabe < 1 || eingabe > 4){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            switch(eingabe){
                case 1:
                    selectAttack(at_tackle, sl_attackSlot2);
                    Pokemon::attack2Name = "Tackle";
                break;

                case 2:
                    selectAttack(at_kratzer, sl_attackSlot2);
                    Pokemon::attack2Name = "Kratzer";
                break;

                case 3:
                    selectAttack(at_glut, sl_attackSlot2);
                    Pokemon::attack2Name = "Glut";
                break;

                case 4:
                    selectAttack(at_blubber, sl_attackSlot2);
                    Pokemon::attack2Name = "Blubber";
                break;

                default:
                    selectAttack(at_tackle, sl_attackSlot2);
                    Pokemon::attack2Name = "Tackle";
            }
            break;
        }
    }
}

//Konstruktor für cutsom Character
Pokemon::Pokemon(bool custom){
    int eingabe;
    int testSkillPoints = Pokemon::skillPoints;
    if(custom){
        while(Pokemon::skillPoints){
            if(Pokemon::skillPoints == testSkillPoints){
                std::cout << "Alle Werte sind auf 20 gesetzt, du hast noch " << Pokemon::skillPoints << " Skillpunkte " << (char)129 << "brig." << std::endl << "Gib eine Zahl ein um den angezeigten Wert zu erh" << (char)148 << "en." << std::endl;
            }else{
                std::cout << "Verbleibende Skillpunkte " << Pokemon::skillPoints << std::endl;
            }
            std::cout << "Verteidigung: ";
            eingabe = getSkillpointInput();
            Pokemon::def = 20 + eingabe;

            if(Pokemon::skillPoints > 0){
                std::cout << "Verbleibende Skillpunkte " << Pokemon::skillPoints << std::endl << "Angriff: ";
                eingabe = getSkillpointInput();
                Pokemon::ap = 20 + eingabe;
            }else{
                Pokemon::ap = 20;
            }

            if(Pokemon::skillPoints > 0){
                std::cout << "Verbleibende Skillpunkte " << Pokemon::skillPoints << std::endl << "Initiative: ";
                eingabe = getSkillpointInput();
                Pokemon::initiative = 20 + eingabe;
            }else{
                Pokemon::initiative = 20;
            }

            if(Pokemon::skillPoints > 0){
                std::cout << "Verbleibende Skillpunkte " << Pokemon::skillPoints << std::endl << "Lebenspunkte: ";
                eingabe = getSkillpointInput();
                Pokemon::maxhp = 20 + eingabe;
            }else{
                Pokemon::maxhp = 20;
            }
        }
        Pokemon::hp = Pokemon::maxhp;
        Pokemon::status = ef_none;

        std::cout << "Wie soll das Pokemon hei" << (char)225 << "en? ";
        std::cin >> Pokemon::name;
        setCustomAttacks();
    }
}

Pokemon::~Pokemon(){}

void Pokemon::CheckDefense(int thisAp, int &otherDef, int &otherHp, int dmg){
    if(thisAp > otherDef){
        otherHp -= dmg + (thisAp - otherDef);
    }else{
        if(dmg > otherDef){
            dmg -= (otherDef);
            otherHp -= dmg;
        }
    }
}

void Pokemon::tackle(Pokemon& other){
    int dmg = 35;
    int randomNum;
    time_t t;

    srand((unsigned) time(&t));
    randomNum = rand() % 100;

    if(randomNum < 5){
        std::cout << "Attacke hat verfehlt!" << std::endl;
    }else{
        std::cout << Pokemon::name << " setzt Tackle ein." << std::endl;
        CheckDefense(this->ap, other.def, other.hp, dmg);
    }
}

void Pokemon::blubber(Pokemon& other){
    int dmg = 20;
    int randomNum;
    time_t t;

    srand((unsigned) time(&t));
    randomNum = rand() % 3;

    std::cout << Pokemon::name << " setzt Blubber ein." << std::endl;

    if(randomNum == 0){
        other.initiative -= 5;
        std::cout << other.getName() << "s Initiative wurde gesenkt" << std::endl;
    }
    CheckDefense(this->ap, other.def, other.hp, dmg);
};

void Pokemon::kratzer(Pokemon& other){
    int dmg = 40;

    std::cout << Pokemon::name << " setzt Kratzer ein." << std::endl;
    CheckDefense(this->ap, other.def, other.hp, dmg);
};

void Pokemon::glut(Pokemon& other){
    int dmg = 40;
    int randomNum;
    time_t t;

    srand((unsigned) time(&t));
    randomNum = rand() % 10;

    std::cout << Pokemon::name << " setzt Glut ein." << std::endl;

    if(randomNum == 0 && other.status == ef_none){
        other.status = ef_burn;
        other.ap /= 2;
        std::cout << other.getName() << " wurde in brand gesetzt." << std::endl;
    }
    CheckDefense(this->ap, other.def, other.hp, dmg);
};
