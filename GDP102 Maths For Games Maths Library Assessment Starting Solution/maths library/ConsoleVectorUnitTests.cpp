#include "ConsoleVectorUnitTests.h"
#include <iostream>

// Run the vector2, vector3 and vector4 unit tests
int ConsoleVectorUnitTests::runTests()
{
	int testsFailedTotal = 0;
	testsRun = 0;
	testsFailed = 0;
	testsSucceeded = 0;
	#ifdef RUN_VECTOR_UNIT_TESTS
	testsFailedTotal += vector2Tests();
	std::cout << std::endl;
	testsFailedTotal += vector3Tests();
	std::cout << std::endl;
	testsFailedTotal += vector4Tests();
	std::cout << std::endl;
	#else
	return -1;
	#endif
	return testsFailedTotal;

}
#ifdef RUN_VECTOR_UNIT_TESTS
//Run the unit tests for vector2
int ConsoleVectorUnitTests::vector2Tests()
{
	std::cout << "Vector 2 tests... " << std::endl;
	Vector2 v1(1, 2);
	bool testb = true;
	char stringTest[] = "test";
	test(testb, stringTest);
	test(testb, "test");
	test(v1, {1,2}, "Vector 2 constructor");

	test(v1[0] = 1 && v1[1] == 2, "Vector 2 [] operator overloading");

	v1[0] = 10;
	v1[1] = 20;
	test(v1,{10,20}, "Vector 2 [] operator assignment overloading");

	Vector2 v2(15, 30);
	Vector2 v3 = v1 + v2;
	test(v3,{25,50}, "Vector 2 + assignment overloading");

	v3 += v1;
	test(v3, { 35,70 }, "Vector 2 += assignment overloading");

	v3 = v2 - Vector2(5,10);
	test(v3,{10,20}, "Vector 2 - assignment overloading");

	v3 -= Vector2(1, 22);
	test(v3,{9,-2}, "Vector 2 -= assignment overloading");

	v3 = v2 * 1.5f;
	test(v3,{ 22.5f,45 }, "Vector 2 * assignment overloading");

	v3 *= 2;
	test(v3, { 45,90 }, "Vector 2 *= assignment overloading");

	v3 = v2 / 1.5f;
	test(v3, { 10.0f,20 }, "Vector 2 / assignment overloading");

	v3 /= 2.5f;
	test(v3, { 4, 8 }, "Vector 2 /= assignment overloading");

	v2 = { 4,5 };
	v3 = { 7,9 };
	test(v3.dot(v2),73, "Vector 2 dot product");

	v3 = { 3,4 };
	test(v3.magnitude(),5, "Vector 2 magnitude");

	v3 = { 5,4 };
	test(v3.magnitudeSqr(),41, "Vector 2 magnitude squared");

	v3.normalise();
	test(v3, { .7809,.6247 }, "Vector 2 normalise");

	v3 = { 5,4 };
	v2 = v3.normalised();
	test(v2, { .7809,.6247 }, "Vector 2 normalised");

	float distance = v2.distanceTo({ 10,11 });
	test(distance, 13.88, "Vector 2 distance to");

	float distanceSqr = v2.distanceToSqr({ 10,12 });
	test(distanceSqr, 214.39, "Vector 2 distance to square");

	if (testsRun == testsSucceeded)
	{
		std::cout << "All Vector 2 tests passed" << std::endl;
	}
	else
	{
		std::cout << testsFailed<< " Vector 2 test failed" << std::endl;
	}
	return testsFailed;
}

//Run the unit tests for vector3
int ConsoleVectorUnitTests::vector3Tests()
{
	std::cout << "Vector 3 tests... " << std::endl;
	Vector3 v1(1, 2, 3);
	test(v1, { 1,2,3 }, "Vector 3 constructor");

	test(v1[0] == 1 && v1[1] == 2 && v1[2] == 3 , "Vector 3 [] operator overloading");

	v1[0] = 10;
	v1[1] = 20;
	v1[2] = 30;
	test(v1, { 10,20, 30 }, "Vector 3 [] operator assignment overloading");

	Vector3 v2(1, 5, 3);
	Vector3 v3 = v1 + v2;
	test(v3, { 11,25,33  }, "Vector 3 + assignment overloading");

	v3 += v1;
	test(v3, { 21, 45, 63}, "Vector 3 += assignment overloading");

	v3 = v2 - Vector3(5, 10, 15);
	test(v3, { -4, -5, -12 }, "Vector 3 - assignment overloading");

	v3 -= Vector3(1, 22, 15.5);
	test(v3, { -5,-27, -27.5 }, "Vector 3 -= assignment overloading");

	v3 = v2 * 1.5f;
	test(v3, { 1.5, 7.5, 4.5 }, "Vector 3 * assignment overloading");

	v3 *= 2;
	test(v3, { 3, 15 ,9}, "Vector 3 *= assignment overloading");

	v3 = v2 / 1.5f;
	test(v3, { 0.6667,3.3333, 2 }, "Vector 2 / assignment overloading");

	v3 /= 2.5f;
	test(v3, { .26666, 1.3333, 0.8 }, "Vector 2 /= assignment overloading");

	v2 = { 3, 4, 5 };
	v3 = { 7, 9, 11 };
	test(v3.dot(v2), 112, "Vector 3 dot product");

	test(v2.cross(v3), {-1 ,2, -1}, "Vector 3 cross product");

	v3 = { 3, 4, 7 };
	test(v3.magnitude(), 8.602, "Vector 3 magnitude");

	v3 = { 2, 5,4 };
	test(v3.magnitudeSqr(), 45, "Vector 3 magnitude squared");

	v3.normalise();
	test(v3, { 0.298, 0.745, 0.596}, "Vector 3 normalise");

	v3 = { 5,4, 2 };
	v2 = v3.normalised();

	test(v2, { .745,.5962, 0.298 }, "Vector 3 normalised");

	float distance = v2.distanceTo({ 10,11,12 });
	test(distance, 18.188, "Vector 3 distance to");
	float distanceSqr = v2.distanceToSqr({ 10,12,-20 });
	test(distanceSqr, 627.708, "Vector 3 distance to square");

	if (testsRun == testsSucceeded)
	{
		std::cout << "All Vector 3 tests passed" << std::endl;
	}
	else
	{
		std::cout << testsFailed << " Vector 3 test failed" << std::endl;
	}
	return testsFailed;

}

//Run the unit tests for vector4
int ConsoleVectorUnitTests::vector4Tests()
{
	std::cout << "Vector 4 tests... " << std::endl;
	Vector4 v1(1, 2, 3, 4);
	test(v1, { 1,2,3, 4 }, "Vector 4 constructor");

	test(v1[0] == 1 && v1[1] == 2 && v1[2] == 3 && v1[3] == 4, "Vector 4 [] operator overloading");
	v1[0] = 10;
	v1[1] = 20;
	v1[2] = 30;
	v1[3] = 40;
	test(v1, { 10,20, 30, 40 }, "Vector 4 [] operator assignment overloading");

	Vector4 v2(6, 1, 5, 3);
	Vector4 v3 = v1 + v2;
	test(v3, { 16,21,35, 43  }, "Vector 4 + assignment overloading");

	v3 += v1;
	test(v3, { 26, 41, 65,83}, "Vector 4 += assignment overloading");

	v3 = v2 - Vector4(5, 10, 15, 6.8);
	test(v3, { 1, -9, -10, -3.8 }, "Vector 4 - assignment overloading");

	v3 -= Vector4(1, 22, 15.5, 5.4);
	test(v3, { 0,-31, -25.5 , -9.2 }, "Vector 4 -= assignment overloading");

	v3 = v2 * 3.7f;
	test(v3, { 22.2, 3.7, 18.5, 11.1 }, "Vector 4 * assignment overloading");

	v3 *= 2.3;
	test(v3, { 51.06, 8.51 ,42.55, 25.53}, "Vector 4 *= assignment overloading");

	v3 = v2 / 1.5f;
	test(v3, { 4,0.6667, 3.3333,2 }, "Vector 4 / assignment overloading");

	v3 /= 2.5f;
	test(v3, {1.6, .26666, 1.3333, 0.8 }, "Vector 4 /= assignment overloading");

	v2 = { 3, 4, -5, 1.4 };
	v3 = { -7.7, 7, 9, 11 };
	test(v3.dot(v2), -24.7, "Vector 4 dot product");


	v2 = { 3, 4, 5, 0 };
	v3 = { 7, 9, 11, 0 };

	test(v2.cross(v3), { -1 ,2, -1, 0 }, "Vector 4 cross product");

	v3 = { 3, -4.1, 7.3, 11 };
	test(v3.magnitude(), 14.1457, "Vector 4 magnitude");

	v3 = { 2, -5,4, -11.3 };
	test(v3.magnitudeSqr(), 172.69, "Vector 4 magnitude squared");

	v3.normalise();
	test(v3, { 0.152,-0.38,0.304,-0.86}, "Vector 4 normalise");

	v3 = { 5,4, -2.5, 7.3 };
	v2 = v3.normalised();
	test(v2, { .499,.399, -0.249, 0.728 }, "Vector 4 normalised");

	float distance = v2.distanceTo({ 10,-11.1,12.3, -35 });
	test(distance, 40.7, "Vector 4 distance to");

	float distanceSqr = v2.distanceToSqr({ 10,-1.2,22.3,5.3 });
	test(distanceSqr, 622.207, "Vector 4 distance to square");

	if (testsRun == testsSucceeded)
	{
		std::cout << "All Vector 4 tests passed" << std::endl;
	}
	return testsFailed;
}

// test equivalence of two floating point with reasonable accuracy
bool ConsoleVectorUnitTests::testEquivalence(float f1, float f2)
{
	return (abs(f2 - f1) < 0.001);
}

// test equivalence of two vector2 with reasonable accuracy
bool ConsoleVectorUnitTests::testEquivalence(const Vector2& v1,const Vector2& v2)
{
	Vector2 delta = v2 - v1;
	return (abs(delta.x) < 0.001 && abs(delta.y) < 0.001);
}

// test equivalence of two vector3 with reasonable accuracy
bool ConsoleVectorUnitTests::testEquivalence(const Vector3& v1,const Vector3& v2)
{
	Vector3 delta = v2 - v1;
	return (abs(delta.x) < 0.001 && abs(delta.y) < 0.001 && abs(delta.z) < 0.001);
}

// test equivalence of two vector4 with reasonable accuracy
bool ConsoleVectorUnitTests::testEquivalence(const Vector4& v1,const Vector4& v2)
{
	Vector4 delta = v2 - v1;
	return (abs(delta.x) < 0.001 && abs(delta.y) < 0.001 && abs(delta.z) < 0.001 && abs(delta.w) < 0.001);
}

// display success message and update scores if result is true
void  ConsoleVectorUnitTests::test(bool result, const char* testName)
{
	testsRun++;
	if (result)
	{
		testsSucceeded++;
		std::cout << "Success: ";
	}
	else
	{
		testsFailed++;
		std::cout << "Failed: ";
	}
	std::cout << testName << std::endl;
}

// display message and update scores if test and answer are equivalent
void  ConsoleVectorUnitTests::test(float test, float answer, const  char* testName)
{
	testsRun++;
	if (testEquivalence(test, answer))
	{
		testsSucceeded++;
		std::cout << "Success: ";
	}
	else
	{
		testsFailed++;
		std::cout << "Failed: " << "incorrect result: " << test << " : ";
	}
	std::cout << testName << std::endl;
}

// display message and update scores if test and answer are equivalent
void  ConsoleVectorUnitTests::test(Vector2 test, Vector2 answer, const  char* testName)
{
	testsRun++;
	if (testEquivalence(test, answer))
	{
		testsSucceeded++;
		std::cout << "Success: ";
	}
	else
	{
		testsFailed++;
		std::cout << "Failed: " << "incorrect result: " << test << " : ";
	}
	std::cout << testName << std::endl;
}

// display message and update scores if test and answer are equivalent
void  ConsoleVectorUnitTests::test(Vector3 test, Vector3 answer, const  char* testName)
{
	testsRun++;
	if (testEquivalence(test, answer))
	{
		testsSucceeded++;
		std::cout << "Success: ";
	}
	else
	{
		testsFailed++;
		std::cout << "Failed: " << "incorrect result: " << test << " : ";
	}
	std::cout << testName << std::endl;
}

// display message and update scores if test and answer are equivalent
void  ConsoleVectorUnitTests::test(Vector4 test, Vector4 answer, const  char* testName)
{
	testsRun++;
	if (testEquivalence(test, answer))
	{
		testsSucceeded++;
		std::cout << "Success: ";
	}
	else
	{
		testsFailed++;
		std::cout << "Failed: " << "incorrect result: " << test << " : ";
	}
	std::cout << testName << std::endl;
}
#endif