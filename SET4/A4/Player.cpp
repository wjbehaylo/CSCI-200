#include <iostream>
#include "Player.h"
using namespace std;



int Player::get_player_num(){
    return mPlayer;
}

void Player::set_player_num(const int PLAYER_NUM){
    mPlayer = PLAYER_NUM;
    return;
}

int Player::get_chips(){
    return mChips;
}

void Player::set_chips(const int NUM_CHIPS){
    mChips = NUM_CHIPS;
    return;
}

void Player::set_pRight(Player* right_player){
    pRight = right_player;
    return;
}
void Player::set_pLeft(Player* left_player){
    pLeft = left_player;
    return;
}

Player* Player::get_pRight(){
    return pRight;
}

Player* Player::get_pLeft(){
    return pLeft;
}

void Player::give_player_chip(const char DIRECTION){
    mChips --; //this decreases the current player's number of chips by one, as they are giving away one chip
    if (DIRECTION == 'R'){ //if we are moving right
        pRight->set_chips(pRight->get_chips()+1); //this line goes to the right player and uses their set_chips function to add one to the number of chips they have
    }
    if (DIRECTION == 'L'){ //if we are moving left
        pLeft->set_chips(pLeft->get_chips()+1); //this line goes to the left player and uses their  set_chips function to add one to the number of chips they have
    }
}

void Player::give_center_chip(){
    mChips--; //decreases current player's number of chips by one
    // LRC.center = LRC.center ++; 
    //the center will be a value in the Game, so we just need to incriment it by one here, this needs to be done with DIE in the actual main.cpp
}