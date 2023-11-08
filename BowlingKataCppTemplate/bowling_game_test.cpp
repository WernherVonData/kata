#include <gtest/gtest.h>

#include <memory>

#include "game.hpp"

class BowlingGameTest : public ::testing::Test {
    public:
    void SetUp() {
        g = std::make_unique<Game>();
    }
    
    void rollMany(const int n, const int pins) {
        for (int i = 0; i < n; ++i) {
            g->roll(pins);
        }
    }

    void rollSpare() {
        g->roll(5);
        g->roll(5);
    }

    void rollStrike() {
        g->roll(10);
    }

    protected:
    std::unique_ptr<Game> g;
};

TEST_F(BowlingGameTest, GutterGame) {
    rollMany(20, 0);
    ASSERT_EQ(0, g->score());
}

TEST_F(BowlingGameTest, AllOnes) {
    rollMany(20, 1);
    ASSERT_EQ(20, g->score());
}

TEST_F(BowlingGameTest, OneSpare) {
    rollSpare();
    g->roll(3);
    rollMany(17, 0);
    ASSERT_EQ(16, g->score());
}

TEST_F(BowlingGameTest, OneStrike) {
    rollStrike();
    g->roll(3);
    g->roll(4);
    rollMany(16, 0);
    ASSERT_EQ(24, g->score());
}

TEST_F(BowlingGameTest, PerfectGame) {
    rollMany(12, 10);
    ASSERT_EQ(300, g->score());
}