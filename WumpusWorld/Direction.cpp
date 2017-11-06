#include "stdafx.h"
#include "Direction.h"

using namespace Direction;

struct Position GetAhead(struct Position pos, Flags f)
{
	switch (f) {
	case North:
		return { 0, -1 };
	case South:
		return { 0, 1 };
	case West:
		return { 1, 0 };
	case East:
		return { -1, 0 };
	default:
		return { 0, 0 };
	}
}

Flags TurnRight(Flags f)
{
	switch (f) {
	case North:
		return West;
	case South:
		return East;
	case West:
		return South;
	case East:
		return North;
	default: return static_cast<Flags>(0);
	}
}

Flags TurnLeft(Flags f)
{
	switch (f) {
	case North:
		return East;
	case South:
		return West;
	case West:
		return North;
	case East:
		return South;
	default: return static_cast<Flags>(0);
	}
}