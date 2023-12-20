//
// Created by felix on 2023-12-13.
//

#ifndef CPROG_PROJECT_SCOREFIELD_H
#define CPROG_PROJECT_SCOREFIELD_H


#include <string>
#include "UIComponent.h"
#include "springhawk/Vector2.h"
#include "springhawk/Color.h"

class ScoreField : public UIComponent{

public:
    ~ScoreField() override = default;
    explicit ScoreField(const std::string& leadText);

    Vector2 getPosition() override;
    void setPosition(Vector2 position) override;

    Vector2 getSize() override;
    void setSize(Vector2 size) override;

    std::string getText() override;
    void setText(std::string text) override;

    TTF_Font* getFont() override;
    void setFont(TTF_Font* font) override;

    Color getColor() override;
    void setColor(Color color) override;

    int getFontSize() override;
    void setFontSize(int fontSize) override;

    std::string getFontName() override;
    void setFontName(std::string fontName) override;

    void incrementScore();

    void setScore(int score);

private:
    ScoreField();
    int score;

};


#endif //CPROG_PROJECT_SCOREFIELD_H
