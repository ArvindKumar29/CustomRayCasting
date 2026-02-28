#include "Physics.h"

IntersectionResult Physics::IsIntersect(Vec2 a, Vec2 b, Vec2 c, Vec2 d) {
	Vec2 r = b - a;
	Vec2 s = d - c;
	float rxs = r.x * s.y - r.y * s.x;
	Vec2 cma = c - a;
	float t = (cma.x * s.y - cma.y * s.x) / rxs;
	float u = (cma.x * r.y - cma.y * r.x) / rxs;
	if (rxs != 0 && t >= 0 && t <= 1 && u >= 0 && u <= 1) {
		Vec2 intersectionPoint = a + r * t;
		return { true, intersectionPoint };
	}
	else {
		return { false, Vec2(0, 0) };
	}
}

Physics::Physics() {
}
