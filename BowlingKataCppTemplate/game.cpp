#include "game.hpp"

void Game::roll(int pins) {
    rolls_[current_roll_++] = pins;
}

int Game::score() {
    int score = 0;
    for (int frame = 0, frame_index = 0; frame < 10; ++frame) {
        if (isStrike(frame_index)) {
            score += 10 + strikeBonus(frame_index);
            ++frame_index;
        } else if (isSpare(frame_index)) {
            score += 10 + spareBonus(frame_index);
            frame_index+=2;
        } else {
            score += sumOfPinsInFrame(frame_index);
            frame_index+=2;
        }
    }
    return score;
}

bool Game::isSpare(const int frame_index) {
    return rolls_[frame_index] + rolls_[frame_index+1] == 10;
}

int Game::spareBonus(const int frame_index) {
    return rolls_[frame_index+2];
}

bool Game::isStrike(const int frame_index) {
    return rolls_[frame_index] == 10;
}

int Game::strikeBonus(const int frame_index) {
    return rolls_[frame_index+1] + rolls_[frame_index+2];
}

int Game::sumOfPinsInFrame(const int frame_index) {
    return rolls_[frame_index] + rolls_[frame_index+1];
}