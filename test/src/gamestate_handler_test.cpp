#include <map>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "gamestate_handler.h"
#include "mocks/mock_gamestate.h"

using ::testing::_;
using ::testing::InSequence;
using ::testing::Return;

class GraphicsHandlerTest : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

TEST(GameStateHandlerTest, runs_gamestate){
    MockGameState* mock_mainmenu = new MockGameState();
    EXPECT_CALL(*mock_mainmenu, run(_))
        .WillOnce(Return(gamestates::EXIT));

    std::map<gamestates::GameStateName, I_GameState*> gamestates;
    gamestates.insert(std::pair<gamestates::GameStateName, I_GameState*>(gamestates::MAIN_MENU, mock_mainmenu));
    
    GameStateHandler gs_handler = GameStateHandler(&gamestates);
    gs_handler.start(gamestates::MAIN_MENU);

    delete mock_mainmenu;
}

TEST(GameStateHandlerTest, runs_next_gamestate) {
    InSequence dummy;

    MockGameState* mock_opening = new MockGameState();
    MockGameState* mock_mainmenu = new MockGameState();

    EXPECT_CALL(*mock_opening, run(_))
        .WillOnce(Return(gamestates::MAIN_MENU));
    EXPECT_CALL(*mock_mainmenu, run(_))
        .WillOnce(Return(gamestates::EXIT));    
    
    std::map<gamestates::GameStateName, I_GameState*> gamestates;
    gamestates.insert(std::pair<gamestates::GameStateName, I_GameState*>(gamestates::OPENING_CUTSCENE, mock_opening));
    gamestates.insert(std::pair<gamestates::GameStateName, I_GameState*>(gamestates::MAIN_MENU, mock_mainmenu));
    
    GameStateHandler gs_handler = GameStateHandler(&gamestates);
    gs_handler.start(gamestates::OPENING_CUTSCENE);

    delete mock_opening;
    delete mock_mainmenu;
}

