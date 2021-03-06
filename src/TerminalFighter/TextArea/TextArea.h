#include <string>

#include <SDL_ttf.h>

#include "I_TextArea.h"

class TextArea : public I_TextArea {
public:
    TextArea(std::string, SDL_Color, int, int, int, int, std::string, int);
    ~TextArea();
    void draw(SDL_Renderer& renderer);
    void set_color(SDL_Color color);
private:
    std::string text_str_;
    SDL_Color color_;
    SDL_Rect message_rect_;
    TTF_Font* font_;
};
