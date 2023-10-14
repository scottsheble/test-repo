/********************************************************
    CSCI 240        Program 3       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 10/13/23

    Purpose: This program demonstrates generating three 
    sets of random numbers.

    Created by scott sheble on 10/01/23.
*********************************************************/
#include <iostream>
#include <cstdlib>

// Symbolic Constants: Monster type
const int GOBLIN = 0;
const int OGRE = 1;
const int DRAGON = 2;
// Symbolic Constants: Attack critical type
const int CRITICAL_FAILURE = 1;
const int CRITICAL_SUCCESS = 20;
// Symbolic Constants: Player health & armor
const int PLAYER_MAX_HP_MIN = 50;
const int PLAYER_MAX_HP_MAX = 150;
const int PLAYER_AC_MIN = 1;
const int PLAYER_AC_MAX = 4;
// Symbolic Constants: Monster health & armor
const int MONSTER_HP[3] = {30, 75, 345};
const int MONSTER_AC[3] = {1, 2, 5};
const std::string MONSTER_NAMES[3] = {"Goblin", "Ogre", "Dragon"};

// 8-sided dice roll
int rollD8() {
    return rand() % 8 + 1;
}

// 20-sided dice roll
int rollD20() {
    return rand() % 20 + 1;
}

// Player's attack function, if branching determining the console output dependent on critical success/failure.
int playerAttack(int armor_class, int& player_health) {
    int attack_roll = rollD8();
    if (attack_roll > armor_class) {
        int damage_roll = rollD20();
        if (damage_roll == CRITICAL_FAILURE) {
            std::cout << "Critical failure! The player swings wildly, loses balance, and bumps their head on a wall. -1 HP." << std::endl;
            player_health--;
        } else if (damage_roll == CRITICAL_SUCCESS) {
            std::cout << "The attack hits! Natural 20! The player expertly attacks the monster's exposed weaknesses, dealing -25 HP to it!" << std::endl;
            return 25;
        } else {
            return damage_roll;
        }
    }
    return 0;
}

// Monster's attack function, if branching determining the console output dependent on critical success/failure.
int monsterAttack(int armor_class, int& monster_health) {
    int attack_roll = rollD8();
    if (attack_roll > armor_class) {
        int damage_roll = rollD20();
        if (damage_roll == CRITICAL_FAILURE) {
            std::cout << "Critical failure! The monster recklessly attacks, slips, and bumps their head on the floor. -1 HP." << std::endl;
            monster_health--;
        } else if (damage_roll == CRITICAL_SUCCESS) {
            std::cout << "The attack hits! Natural 20! The monster's combat prowess becomes the stuff of nightmares, savagely rending the player, dealing -25 HP to them!" << std::endl;
            return 25;
        } else {
            return damage_roll;
        }
    }
    return 0;
}

int main() {
    srand(14);
    int player_max_health = rand() % (PLAYER_MAX_HP_MAX - PLAYER_MAX_HP_MIN + 1) + PLAYER_MAX_HP_MIN;
    int player_health = player_max_health;
    int player_armor_class = rand() % (PLAYER_AC_MAX - PLAYER_AC_MIN + 1) + PLAYER_AC_MIN;
    int monster_type = rand() % 3;
    std::cout << std::endl;
    std::cout << "The player's maximum HP is " << player_health << std::endl;
    std::cout << "The player's armor class is " << player_armor_class << std::endl;
    std::cout << std::endl;

    std::cout << "  You encounter a " << MONSTER_NAMES[monster_type] << ". This should be easy enough!" << std::endl;

    int monster_health = MONSTER_HP[monster_type];
    int monster_armor_class = MONSTER_AC[monster_type];
    std::cout << "The monster's maximum HP is " << monster_health << std::endl;
    std::cout << "The monster's armor class is " << monster_armor_class << std::endl;
    std::cout << std::endl;

    int counter = 0;

    while (player_health > 0) {
        int player_damage = playerAttack(monster_armor_class, player_health);
        if (player_damage > 0) {
            monster_health -= player_damage;
        }
        std::cout << "The attack hits! The player damages for -" << player_damage << "HP to the monster. Monster's current HP: " << monster_health << std::endl;

        if (monster_health <= 0) {
            counter++;
            std::cout << "The monster has been slain! The adrenaline rush from the victory restores their HP to full!" << std::endl;
            std::cout << std::endl;
            std::cout << "-----------------------------------------------------------" << std::endl;
            std::cout << std::endl;

            // Generate next monster.
            monster_type = rand() % 3;
            std::cout << "You encounter a  " << MONSTER_NAMES[monster_type] << ". This should be easy enough!" << std::endl;
            monster_health = MONSTER_HP[monster_type];
            monster_armor_class = MONSTER_AC[monster_type];
        } else {
            int monster_damage = monsterAttack(player_armor_class, player_health);
            if (monster_damage > 0) {
                player_health -= monster_damage;
            }
            std::cout << "The attack hits! The monster damages for -" << monster_damage << "HP to the player. Player's current HP: " << player_health << "\n" << std::endl;
        }
    }

    std::cout << "Gasping for breath and realizing their mother wasn't wrong when they suggested they just stay on the farm and live a quiet life, the player passes away!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------";
    std::cout << std::endl;
    std::cout << "Monster kill streak: " << counter << std::endl;

    return 0;
}
