#ifndef CPROG_PROJECT_UICOMPONENT_H
#define CPROG_PROJECT_UICOMPONENT_H

#include <SDL2/SDL_ttf.h>
#include "springhawk/Vector2.h"
#include "springhawk/Color.h"

class UIComponent {
public:
    UIComponent() = default;
    virtual ~UIComponent() = default;

    virtual Vector2 getPosition() = 0;
    virtual void setPosition(Vector2 position) = 0;

    virtual Vector2 getSize() = 0;
    virtual void setSize(Vector2 size) = 0;

    virtual std::string getText() = 0;
    virtual void setText(std::string text) = 0;

    virtual TTF_Font* getFont() = 0;
    virtual void setFont(TTF_Font* font) = 0;

    virtual Color getColor() = 0;
    virtual void setColor(Color color) = 0;

    virtual int getFontSize() = 0;
    virtual void setFontSize(int fontSize) = 0;

    virtual std::string getFontName() = 0;
    virtual void setFontName(std::string fontName) = 0;

protected:
    Vector2 position;
    Vector2 size;
    std::string text;
    std::string fontName;
    TTF_Font* font;
    Color fontColor;
    int fontSize;
};


#endif //CPROG_PROJECT_UICOMPONENT_H
