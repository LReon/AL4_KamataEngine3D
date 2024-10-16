
#pragma once
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES
#include "Matrix4x4.h"
#include "Vector3.h"

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
