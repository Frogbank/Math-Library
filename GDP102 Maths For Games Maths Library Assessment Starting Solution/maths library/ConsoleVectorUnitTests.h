#pragma once

#define RUN_VECTOR_UNIT_TESTS // Comment this back in to run the matrix unit tests
#ifdef RUN_VECTOR_UNIT_TESTS
#include "vector.h"
#endif
class ConsoleVectorUnitTests
{
	int testsRun = 0;
	int testsFailed = 0;
	int testsSucceeded = 0;
public:
	int runTests();
	#ifdef RUN_VECTOR_UNIT_TESTS
	int vector2Tests();
	int vector3Tests();
	int vector4Tests();
	static bool testEquivalence(float , float);
	static bool testEquivalence(const Vector2&, const const Vector2&);
	static bool testEquivalence(const Vector3&, const const Vector3&);
	static bool testEquivalence(const Vector4&, const const Vector4&);
	void test(bool result, const char* testName);
	void test(float test, float answer, const  char* testName);
	void test(Vector2 test, Vector2 answer, const  char* testName);
	void test(Vector3 test, Vector3 answer, const  char* testName);
	void test(Vector4 test, Vector4 answer, const  char* testName);
	#endif
};

