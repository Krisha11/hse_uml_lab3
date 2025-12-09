#include <gtest/gtest.h>
#include "PhoneLine.h"
#include <thread>
#include <chrono>
#include <string>

class PhoneLineTest : public ::testing::Test {
protected:
    PhoneLine* p;
    
    void SetUp() override {
        p = new PhoneLine();
    }
    
    void TearDown() override {
        delete p;
        p = nullptr;
    }
};


/*
O = {
0 null,
1 soundDialTone,
2 I,
3 disconnectedLine,
4 continues,
5 slowBusyTone,
6 findConnection,
7 PlayMessage
}

0	onHook
1	offHook
2	validNumber
3	invalidNumber
4	I
*/


// 1/1 4/2 3/7 2/5
TEST_F(PhoneLineTest, TestCase34) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
}

// 1/1 4/2 4/2 0/3 0/0
TEST_F(PhoneLineTest, TestCase33) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 4/2 4/2 2/6 2/4
TEST_F(PhoneLineTest, TestCase32) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->validNumber(), "continues");
}

// 1/1 4/2 4/2 3/7 2/5
TEST_F(PhoneLineTest, TestCase31) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
}

// 1/1 1/0 4/2 4/2 2/6
TEST_F(PhoneLineTest, TestCase29) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->validNumber(), "findConnection");
}

// 1/1 4/2 2/6 2/4
TEST_F(PhoneLineTest, TestCase28) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->validNumber(), "continues");
}

// 1/1 4/2 0/3 0/0
TEST_F(PhoneLineTest, TestCase26) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 3/7 4/2 2/5
TEST_F(PhoneLineTest, TestCase25) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
}

// 1/1 3/7 3/5 2/5
TEST_F(PhoneLineTest, TestCase24) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->invalidNumber(), "slowBusyTone");
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
}

// 1/1 3/7 0/3 0/0
TEST_F(PhoneLineTest, TestCase23) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 2/6 4/2 2/4
TEST_F(PhoneLineTest, TestCase22) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->validNumber(), "continues");
}

// 1/1 2/6 3/4 2/4
TEST_F(PhoneLineTest, TestCase21) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->invalidNumber(), "continues");
    EXPECT_EQ(p->validNumber(), "continues");
}

// 1/1 2/6 0/3 0/0
TEST_F(PhoneLineTest, TestCase20) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 4/2 0/0
TEST_F(PhoneLineTest, TestCase19) {
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
}

// 3/0 0/0
TEST_F(PhoneLineTest, TestCase18) {
}

// 1/1 4/2 4/2 4/2 2/5
TEST_F(PhoneLineTest, TestCase17) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(351));
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
}

// 1/1 4/2 4/2 4/2
TEST_F(PhoneLineTest, TestCase16) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(351));
}

// 1/1 4/2 4/2 3/7
TEST_F(PhoneLineTest, TestCase15) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
}

// 1/1 4/2 4/2 2/6
TEST_F(PhoneLineTest, TestCase14) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->validNumber(), "findConnection");
}

// 1/1 4/2 4/2 1/0
TEST_F(PhoneLineTest, TestCase13) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
}

// 1/1 4/2 4/2 0/3
TEST_F(PhoneLineTest, TestCase12) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(251));
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 4/2 3/7
TEST_F(PhoneLineTest, TestCase11) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
}

// 1/1 4/2 2/6
TEST_F(PhoneLineTest, TestCase10) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->validNumber(), "findConnection");
}

// 1/1 4/2 1/0
TEST_F(PhoneLineTest, TestCase9) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
}

// 1/1 4/2 0/3
TEST_F(PhoneLineTest, TestCase8) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    std::this_thread::sleep_for(std::chrono::milliseconds(151));
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 3/7
TEST_F(PhoneLineTest, TestCase7) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
}

// 1/1 1/0 2/6
TEST_F(PhoneLineTest, TestCase6) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
}

// 1/1 3/7 1/0 2/5 3/5 4/2
TEST_F(PhoneLineTest, TestCase5) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->validNumber(), "slowBusyTone");
    EXPECT_EQ(p->invalidNumber(), "slowBusyTone");
}

// 1/1 3/7 0/3
TEST_F(PhoneLineTest, TestCase4) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->invalidNumber(), "PlayMessage");
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 1/1 2/6 1/0 2/4 3/4 4/2
TEST_F(PhoneLineTest, TestCase3) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->validNumber(), "continues");
    EXPECT_EQ(p->invalidNumber(), "continues");
}

// 1/1 2/6 0/3
TEST_F(PhoneLineTest, TestCase2) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->validNumber(), "findConnection");
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

// 0/0 1/1 0/3 2/0 3/0 4/2
TEST_F(PhoneLineTest, TestCase1) {
    EXPECT_EQ(p->offHook(), "soundDialTone");
    EXPECT_EQ(p->onHook(), "disconnectedLine");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
