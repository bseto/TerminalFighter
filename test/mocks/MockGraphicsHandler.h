#pragma once

#include "gmock/gmock.h"

#include "../../src/Engine/GraphicsHandler/I_GraphicsHandler.h"

class MockGraphicsHandler : public I_GraphicsHandler {
public:
    MockGraphicsHandler() {}

    MOCK_METHOD1(init, void(const std::vector<std::string>&));
    MOCK_METHOD1(create_default_rect, SDL_Rect (SDL_Texture*));
    MOCK_METHOD1(create_default_rect, SDL_Rect (SDL_Surface*));
    MOCK_METHOD7(draw, void(SDL_Texture*, SDL_Rect, SDL_Rect, GraphicPriority, bool, double, SDL_Point*));
    MOCK_METHOD8(draw, void(SDL_Texture*, SDL_Rect, int, int, GraphicPriority, bool, double, SDL_Point*));
    MOCK_METHOD8(draw, void(SDL_Surface*, SDL_Rect, int, int, GraphicPriority, bool, double, SDL_Point*));

    MOCK_METHOD1(load_image, SDL_Texture * (std::string));
    MOCK_METHOD0(update_screen, void());
};
