#pragma once
#include <iostream>

class Vec3f {
private:
	float v[3];
public:
	Vec3f();
	Vec3f(float x, float y, float z);

	float &operator[](int index);
	float operator[](int index) const;

	Vec3f operator*(float scale) const;
	Vec3f operator/(float scale) const;
	Vec3f operator+(const Vec3f &other) const;
	Vec3f operator-(const Vec3f &other) const;
	Vec3f operator-() const;

	const Vec3f &operator*=(float scale);
	const Vec3f &operator/=(float scale);
	const Vec3f &operator+=(const Vec3f &other);
	const Vec3f &operator-=(const Vec3f &other);

	float magnitude() const;
	float magnitudeSquared() const;
	Vec3f normalize() const;
	float dot(const Vec3f &other) const;
	Vec3f cross(const Vec3f &other) const;
};

Vec3f operator*(float scale, const Vec3f &v);
std::ostream &operator<<(std::ostream &output, const Vec3f &v);