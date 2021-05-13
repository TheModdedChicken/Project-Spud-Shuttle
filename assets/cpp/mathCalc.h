#pragma once

#include "raylib.h"
#include <cmath>

int findAngle2d(Point2D p1, Point2D p2) {
  double angle = atan2(p2.y - p1.y, p2.x - p1.x) * 180 / PI;

  return angle + 90;
};