#pragma once

#include "gmock/gmock.h"

#include "../../src/Engine/GameObject/GameObject.h"
#include "../../src/Engine/GraphicsHandler/I_GraphicsHandler.h"
#include "../../src/Engine/Hitbox/I_Hitbox.h"

class MockGameObject : public GameObject {
public:
    MockGameObject() {}

    MOCK_METHOD0(update, void());
    MOCK_METHOD1(draw, void(I_GraphicsHandler& graphics));
    MOCK_CONST_METHOD0(hitbox, const I_Hitbox & ());
    MOCK_METHOD1(notify_collision, void(GameObject&));
    MOCK_METHOD0(Die, void());
    virtual ~MockGameObject() {
        Die();
    }
};
