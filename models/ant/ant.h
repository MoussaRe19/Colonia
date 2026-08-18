
#ifndef ANT_H
#define ANT_H

#include "vec2.h"

// Primary operational states.
typedef enum {
	ANT_STATE_SEARCHING, // Undirected exploration (random walk)
	ANT_STATE_PURSUING,  // Heading toward direct perceived goal/trail
	ANT_STATE_RETURNING, // Carrying resource back to nest (deposits trail)
	ANT_STATE_AT_HOME,   // Transitioning/resting at nest
	ANT_STATE_COUNT
} AntState;

// Intrinsic Physical & Identity State
typedef struct {
	int  id;  // Unique agent identifier
	Vec2 pos; // Continuous 2D world position
	Vec2 vel; // Velocity vector (single source of truth for speed and heading)
	AntState state; // Current behavioral state machine node
	float    radius; // Physical bounding radius for spatial overlap checks
} Ant;

// Helper string conversion for logging and debugging
static inline const char* ant_state_name(AntState s) {
	switch (s) {
	case ANT_STATE_SEARCHING:
		return "SEARCHING";
	case ANT_STATE_PURSUING:
		return "PURSUING";
	case ANT_STATE_RETURNING:
		return "RETURNING";
	case ANT_STATE_AT_HOME:
		return "AT_HOME";
	default:
		return "UNKNOWN";
	}
}

#endif // ANT_H