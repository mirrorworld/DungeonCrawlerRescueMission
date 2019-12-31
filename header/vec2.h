#ifndef __VEC2_H_INCLUDED__
#define __VEC2_H_INCLUDED__
#pragma once

#include <algorithm>

struct Vec2 {
    int x, y;

    Vec2 operator+(const Vec2 other) const;
    Vec2 operator-(const Vec2 other) const;
    Vec2 operator*(const float other) const;

    void operator+=(const Vec2 other);

    bool operator!=(const Vec2 other);
};

struct AABB {
    Vec2 topLeft, bottomRight;

    bool collidesWith(
        const AABB other, const bool expand=false) const;

    AABB getUnion(const AABB other) const;
};

#endif