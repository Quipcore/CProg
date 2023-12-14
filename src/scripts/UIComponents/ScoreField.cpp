#include "components/uiComponents/ScoreField.h"

ScoreField::ScoreField() {
    this->score = 0;
    this->position = {0,0};
    this->size = {0,0};
    this->text = "";
    this->fontName = "ComicSans/comic.ttf";
    this->font = nullptr;
    this->fontColor = {0,0,0,0};
    this->fontSize = 0;

}

ScoreField::ScoreField(const std::string& leadText) : ScoreField() {
    this->text = leadText;
}

Vector2 ScoreField::getPosition() {
    return position;
}

void ScoreField::setPosition(Vector2 position) {
    this->position = position;
}

Vector2 ScoreField::getSize() {
    return size;
}

void ScoreField::setSize(Vector2 size) {
    this->size = size;
}

std::string ScoreField::getText() {
    return text + ": " + std::to_string(score);
}

void ScoreField::setText(std::string text) {
    this->text = text;
}

void ScoreField::incrementScore() {
    score++;
}

TTF_Font *ScoreField::getFont() {
    return font;
}

void ScoreField::setFont(TTF_Font *font) {
    this->font = font;
}

Color ScoreField::getColor() {
    return fontColor;
}

void ScoreField::setColor(Color color) {
    this->fontColor = color;
}

int ScoreField::getFontSize() {
    return fontSize;
}

void ScoreField::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}

std::string ScoreField::getFontName() {
    return fontName;
}

void ScoreField::setFontName(std::string fontName) {
    this->fontName = fontName;
}
