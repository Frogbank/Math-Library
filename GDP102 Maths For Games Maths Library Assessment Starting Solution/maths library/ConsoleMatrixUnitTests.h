#pragma once

#define RUN_MATRIX_UNIT_TESTS // Comment this back in to run the matrix unit tests

#ifdef RUN_MATRIX_UNIT_TESTS
#include "vector.h"
#include "matrix.h"
#include <vector>
#endif
class ConsoleMatrixUnitTests
{
	int testsRun = 0;
	int testsFailed = 0;
	int testsSucceeded = 0;
public:
	int runTests();

#ifdef RUN_MATRIX_UNIT_TESTS
	int matrix2Tests();
	int matrix3Tests();
	int matrix4Tests();
	bool testEquivalence(float , float);
	bool testEquivalence(const Matrix2&, std::vector<float> m2);
	bool testEquivalence(const Matrix3&, std::vector<float> m2);
	bool testEquivalence(const Matrix4&, std::vector<float> m2);
	void test(const Vector2& test, std::vector<float> answer, const char* testName);
	void test(const Vector3& test, std::vector<float> answer, const char* testName);
	void test(const Vector4& test, std::vector<float> answer, const char* testName);
	bool testEquivalence(const Vector2&, std::vector<float> m2);
	bool testEquivalence(const Vector3&, std::vector<float> m2);
	bool testEquivalence(const Vector4&, std::vector<float> m2);
	void test(float test, float answer, const char* testName);
	void test(const Matrix2& test, std::vector<float> answer, const char* testName);
	void test(const Matrix3& test, std::vector<float> answer, const char* testName);
	void test(const Matrix4& test, std::vector<float> answer, const char* testName);
#endif

};

