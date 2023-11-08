#include <array>

class Game {
    public:
    void roll(int pins);
    int score();

    private:
    bool isSpare(const int frame_index);
    int spareBonus(const int frame_index);
    bool isStrike(const int frame_index);
    int strikeBonus(const int frame_index);
    int sumOfPinsInFrame(const int frame_index);

    private:
    std::array<int, 21> rolls_;
    int current_roll_ = 0;
};