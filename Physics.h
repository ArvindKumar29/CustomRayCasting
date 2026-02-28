#pragma once
#include "Vec2.h"
//#include "Line.h"

struct IntersectionResult
{
	bool isIntersecting;
	Vec2 intersectionPoint;
};

class Physics
{
public:
	IntersectionResult IsIntersect(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
	Physics();
};

