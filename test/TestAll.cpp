#include <gtest/gtest.h>
#include "CollisionDetectorTest.cpp"
#include "GameObjectTest.cpp"
#include "GameStateHandlertest.cpp"
#include "HitboxTest.cpp"
#include "KeyboardListenerTest.cpp"
#include "MissileLauncherTest.cpp"
#include "UniverseTest.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
