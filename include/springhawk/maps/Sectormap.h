#pragma once

#include "Map.h"

namespace springhawk{
    class SectorMap : public Map{
        bool isOutOfBounds(Vector2 &position) override;
        Vector2 getValidPos() override;
        int operator[](Vector2 vector2) override;
        int getWidth() override;
        int getHeight() override;

    };
}
