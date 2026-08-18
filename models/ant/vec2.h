#ifndef VEC2_H
#define VEC2_H

#include <math.h>

typedef struct {
	float x, y;
} Vec2;

// Constructors
static inline Vec2 vec2_make(float x, float y) {
	Vec2 v = {x, y};
	return v;
}

// Basic Arithmetic
static inline Vec2 vec2_add(Vec2 a, Vec2 b) {
	return vec2_make(a.x + b.x, a.y + b.y);
}

static inline Vec2 vec2_sub(Vec2 a, Vec2 b) {
	return vec2_make(a.x - b.x, a.y - b.y);
}

static inline Vec2 vec2_scale(Vec2 a, float s) {
	return vec2_make(a.x * s, a.y * s);
}

// Products
static inline float vec2_dot(Vec2 a, Vec2 b) {
	return a.x * b.x + a.y * b.y;
}

static inline float vec2_cross_2d(Vec2 a, Vec2 b) {
	return a.x * b.y - a.y * b.x;
}

// Magnitudes & Distances
static inline float vec2_length_sq(Vec2 a) {
	return vec2_dot(a, a);
}

static inline float vec2_length(Vec2 a) {
	return sqrtf(vec2_length_sq(a));
}

static inline float vec2_distance_sq(Vec2 a, Vec2 b) {
	return vec2_length_sq(vec2_sub(a, b));
}

static inline float vec2_distance(Vec2 a, Vec2 b) {
	return vec2_length(vec2_sub(a, b));
}

// Normalization & Clamping
static inline Vec2 vec2_normalize(Vec2 a) {
	float len = vec2_length(a);
	if (len < 1e-6f) {
		return vec2_make(0.0f, 0.0f);
	}
	return vec2_scale(a, 1.0f / len);
}

static inline Vec2 vec2_clamp_length(Vec2 v, float max_len) {
	float len_sq = vec2_length_sq(v);
	if (len_sq > max_len * max_len) {
		return vec2_scale(vec2_normalize(v), max_len);
	}
	return v;
}

// Rotations & Perpendiculars
static inline Vec2 vec2_perp(Vec2 v) {
	return vec2_make(-v.y, v.x);
}

static inline Vec2 vec2_rotate(Vec2 v, float angle_rad) {
	float cos_a = cosf(angle_rad);
	float sin_a = sinf(angle_rad);
	return vec2_make(v.x * cos_a - v.y * sin_a, v.x * sin_a + v.y * cos_a);
}

// Angle Conversions
static inline Vec2 vec2_from_angle(float angle_rad) {
	return vec2_make(cosf(angle_rad), sinf(angle_rad));
}

static inline float vec2_to_angle(Vec2 v) {
	return atan2f(v.y, v.x);
}

// Coordinates & Interpolation
static inline Vec2 vec2_lerp(Vec2 a, Vec2 b, float t) {
	return vec2_add(a, vec2_scale(vec2_sub(b, a), t));
}

static inline Vec2 vec2_local_to_world(Vec2 local_offset, Vec2 heading) {
	Vec2 right = vec2_perp(heading);
	return vec2_add(vec2_scale(heading, local_offset.y),
					vec2_scale(right, local_offset.x));
}

#endif