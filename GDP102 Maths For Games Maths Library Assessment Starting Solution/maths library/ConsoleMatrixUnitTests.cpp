#include "ConsoleMatrixUnitTests.h"
#include <iostream>

// Run the matrix2, matrix3 and matrix4 unit tests
int ConsoleMatrixUnitTests::runTests()
{
	int testsFailedTotal = 0;
	testsRun = 0;
	testsFailed = 0;
	testsSucceeded = 0;
	#ifdef RUN_MATRIX_UNIT_TESTS
	testsFailedTotal += matrix2Tests();
	std::cout << std::endl;
	testsFailedTotal += matrix3Tests();
	std::cout << std::endl;
	testsFailedTotal += matrix4Tests();
	std::cout << std::endl;
	#else
	return -1;
	#endif
	return testsFailedTotal;
}

#ifdef RUN_MATRIX_UNIT_TESTS
// Run the matrix2 unit tests
int ConsoleMatrixUnitTests::matrix2Tests()
{
	testsFailed = 0;
	std::cout << "Matrix 2 tests... " << std::endl;

	Matrix2 m1(1, 2, 3, 4);
	test(m1, { 1,2,3,4 }, "Matrix 2 per element constructor");

	m1.setIdentity();
	test(m1, { 1,0,0,1}, "Matrix 2 Identity");

	Matrix2 m4 = m1;
	test(m4, { 1,0,0,1}, "Matrix 2 Copy Constructor");

	m1 = { 1,2,3,4 };
	test(m1, { 1,2,3,4}, "Matrix 2 Assignment");

	test(m1.transposed(), { 1, 3, 2, 4 }, "Matrix 2 Transpose");

	m1 = { 1,2,3,4 };
	Vector2 v1 = { 1.5f,2.5f };
	test(m1 * v1, { 9, 13 }, "Matrix 2 * Vector");

	Matrix2 m2 = { -0.6f,0.7f, 0.8f,-0.9f };
	test(m1 * m2, { 1.5f, 1.6f, -1.9f, -2.0f }, "Matrix 2 * Matrix2");

	m1.setRotate(1.5);
	test(m1, {0.0707f, -0.997f, 0.997f, 0.0707f}, "Matrix 2 SetRotate");

	m1.setIdentity();
	m1.rotate(1.5);
	test(m1, { 0.0707f, -0.997f, 0.997f, 0.0707f }, "Matrix 2 Rotate");


	m1 = { 1,2,3,4 };
	m1.setScaled(2, 4);
	test(m1, { 2,0,0,4}, "Matrix 2 setScaled");

	m1 = { 1,2,3,4};
	m1.setScaled({ 1, 2});
	test(m1, { 1,0,0,2 }, "Matrix 2 setScaled wih vector");

	m1 = { 1,2,3,4};
	m1.scale(1, 2);
	test(m1, { 1, 2, 6, 8}, "Matrix 2 setScaled");

	m1 = { 1,2,3,4};
	m1.scale({ 1, 2});
	test(m1, { 1, 2, 6, 8}, "Matrix 2 setScaled wih vector");

	if (testsRun == testsSucceeded)
	{
		std::cout << "All Matrix 2 tests passed" << std::endl;
	}
	else
	{
		std::cout << testsFailed<< " Matrix 2 test failed" << std::endl;
	}
	return testsFailed;
}

// Run the matrix3 unit tests
int ConsoleMatrixUnitTests::matrix3Tests()
{
	testsFailed = 0;
	std::cout << "Matrix 3 tests... " << std::endl;
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	test(m1, { 1,2,3,4,5,6,7,8,9 }, "Matrix 3 per element constructor");
	
	m1.setIdentity();
	test(m1, { 1,0,0,0,1,0,0,0,1 }, "Matrix 3 Identity");
	
	Matrix3 m4 = m1;
	test(m4, { 1,0,0,0,1,0,0,0,1 }, "Matrix 3 Copy Constructor");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	test(m1, { 1,2,3,4,5,6,7,8,9 }, "Matrix 3 Assignment");

	test(m1.transposed(), { 1,4,7,2,5,8,3,6,9 }, "Matrix 3 Transpose");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	Vector3 v1 = { 1,1.5,2.5 };
	test(m1 * v1, { 24.5f, 29.5f, 34.5f }, "Matrix 3 * Vector");

	Matrix3 m2 = { 0.1f,0.2f,0.3f,0.4f,-0.5f,-0.6f,-0.7f, 0.8f,-0.9f };
	test(m1 * m2, { 3, 3.6f, 4.2f, -5.8f, -6.5f, -7.2f, -3.8f, -4.6f, -5.4f, }, "Matrix3 * Matrix3");
	
	m1.setEuler(0.4f, 0.7f, 3.4f);
	test(m1, { -0.74f, 0.20f, 0.64f, -0.48f, -0.83f, -0.30f, 0.47f, -0.53f, 0.70f }, "Matrix 3 Euler");
	
	m1 = { 1,2,3,4,5,6,7,8,9 };
	m1.translate(10, 10);
	test(m1, { 1,2,3,4,5,6,17,18,9 }, "Matrix 3 translate");
	

	m1 = { 0,0,0,0,0,0,0,0,0 };
	m1.setRotateX(1.5f);
	test(m1, { 1, 0, 0, 0, 0.0707f, -1.0, 0, 1.0f, 0.0707f }, "Matrix 3 setRotateX");
	
	m1.setRotateY(0.7f);
	test(m1, { 0.764842f, 0, 0.644218f, 0, 1, 0, -0.644218f, 0, 0.764842f }, "Matrix 3 setRotateY");
	
	m1.setRotateZ(0.3f);
	test(m1, { 0.955337f, -0.29552f, 0, 0.29552f, 0.955337f, 0, 0, 0, 1 }, "Matrix 3 setRotateZ");


	m1.setIdentity();
	m1.rotateX(1.5f);
	test(m1, { 1, 0, 0, 0, 0.0707f, -1.0, 0, 1.0f, 0.0707f }, "Matrix 3 RotateX");
	
	m1.setIdentity();
	m1.rotateY(0.7f);
	test(m1, { 0.764842f, 0, 0.644218f, 0, 1, 0, -0.644218f, 0, 0.764842f }, "Matrix 3 RotateY");
	
	m1.setIdentity();
	m1.rotateZ(0.3f);
	test(m1, { 0.955337f, -0.29552f, 0, 0.29552f, 0.955337f, 0, 0, 0, 1 }, "Matrix 3 RotateZ");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	m1.setScaled(1, 2, 3);
	test(m1, { 1,0,0,0,2,0,0,0,3 }, "Matrix 3 setScaled");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	m1.setScaled({1, 2, 3});
	test(m1, { 1,0,0,0,2,0,0,0,3 }, "Matrix 3 setScaled wih vector");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	m1.scale(1, 2, 3);
	test(m1, { 1, 2, 3, 8, 10, 12, 21, 24, 27 }, "Matrix 3 setScaled");

	m1 = { 1,2,3,4,5,6,7,8,9 };
	m1.scale({ 1, 2, 3 });
	test(m1, { 1, 2, 3, 8, 10, 12, 21, 24, 27 }, "Matrix 3 setScaled wih vector");
	if (testsRun == testsSucceeded)
	{
		std::cout << "All Matrix3 tests passed" << std::endl;
	}
	else
	{
		std::cout << testsFailed << " Matrix3 test failed" << std::endl;
	}
	return testsFailed;
}

// Run the matrix4 unit tests
int ConsoleMatrixUnitTests::matrix4Tests()
{
	testsFailed = 0;
	std::cout << "Matrix 4 tests... " << std::endl;

	Matrix4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16);
	test(m1, { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 }, "Matrix 4 per element constructor");

	m1.setIdentity();
	test(m1, { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 }, "Matrix 4 Identity");

	Matrix4 m4 = m1;
	test(m4, { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 }, "Matrix 4 Copy Constructor");

	m1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	test(m1, { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 }, "Matrix 4 Assignment");

	test(m1.transposed(), { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16}, "Matrix 4 Transpose");


	m1.setIdentity();

	m1 = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 1 };
	Vector4 v1 = { 1,1.5f,2.5f, 1 };
	test(m1 * v1, { 15.5f, 39.5f, 63.5f, 72.5f }, "Matrix 4 * Vector");

	Matrix4 m2(10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 0, 0, 0, 1);
	test(m1 * m2, { 80, 216, 352, 383, 40, 112, 184, 211, 85, 189, 293, 217, 4, 8, 12, 1 }, "Matrix4 * Matrix4");

	m1.setIdentity();
	m1.setEuler(0.4f, 0.7f, 3.4f);
	test(m1, { -0.74f, 0.20f, 0.64f, 0, -0.48f, -0.83f, -0.30f, 0, 0.47f, -0.53f, 0.70f, 0, 0, 0, 0, 1}, "Matrix 4 Euler");
	
	m1.setIdentity();
	m1.translate(100, 10,-12);
	test(m1, { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 100, 10, -12, 1 },  "Matrix 4 translate");

	m1.setRotateX(1.5f);
	test(m1, {	1, 0, 0, 0, 0, 0.0707372f, -0.997495f, 0, 0, 0.997495f, 0.0707372f, 0, 0, 0, 0, 1 }, "Matrix 4 setRotateX");

	m1.setRotateY(0.7f);
	test(m1, { 0.764842f, 0, 0.644218f, 0, 0, 1, 0, 0, -0.644218f, 0, 0.764842f, 0, 0, 0, 0, 1 }, "Matrix 4 setRotateY");

	m1.setRotateZ(0.3f);
	test(m1, { 0.955337f, -0.29552f, 0, 0, 0.29552f, 0.955337f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, "Matrix 4 setRotateZ");


	m1.setIdentity();
	m1.rotateX(1.5f);
	test(m1, { 1, 0, 0, 0, 0, 0.0707372f, -0.997495f, 0, 0, 0.997495f, 0.0707372f, 0, 0, 0, 0, 1 }, "Matrix 4 rotateX");

	m1.setIdentity();
	m1.rotateY(0.7f);
	test(m1, { 0.764842f, 0, 0.644218f, 0, 0, 1, 0, 0, -0.644218f, 0, 0.764842f, 0, 0, 0, 0, 1 }, "Matrix 4 rotateY");

	m1.rotateZ(0.3f);
	m1.setRotateZ(0.3f);
	test(m1, { 0.955337f, -0.29552f, 0, 0, 0.29552f, 0.955337f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, "Matrix 4 rotateZ");

	m1.setScaled(-11, 21,- 3);
	test(m1, { -11, 0, 0, 0, 0, 21, 0, 0, 0, 0, -3, 0, 0, 0, 0, 1, }, "Matrix 4 setScaled");


	m1.setScaled({ 11, 21, 31 });
	test(m1, { 11, 0, 0, 0, 0, 21, 0, 0, 0, 0, 31, 0, 0, 0, 0, 1}, "Matrix 4 setScaled wih vector");

	m1 = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 1 };
	m1.scale(-1, 2, 33);
	test(m1, { -1, -5, -9, -13, 4, 12, 20, 28, 99, 231, 363, 495, 4, 8, 12, 1 }, "Matrix 4 setScaled");

	m1 = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 1 };
	m1.scale({ 10, -2.5f, 3.7f });
	test(m1, { 10, 50, 90, 130, -5, -15, -25, -35, 11.1f, 25.9f, 40.7f, 55.5f, 4, 8, 12, 1 }, "Matrix 4 setScaled wih vector");

	if (testsRun == testsSucceeded)
	{
		std::cout << "All Matrix 4 tests passed" << std::endl;
	}
	else
	{
		std::cout << testsFailed << " Matrix4 test failed" << std::endl;
	}
	return testsFailed;
}

// test equivalence of two floating point with reasonable accuracy
bool ConsoleMatrixUnitTests::testEquivalence(float f1, float f2)
{
	return (abs(f2 - f1) < 0.01f);
}

// test equivalence of two matrix2 with reasonable accuracy, note: second matrix is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Matrix2& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 4; i++)
	{
		if (!testEquivalence(*md1,md2[i]))
		{
			return false;
		}
		md1++;
	}
	return true;
}

// test equivalence of two matrix3 with reasonable accuracy, note: second matrix is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Matrix3& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 9; i++)
	{
		float f1 = *md1;
		float f2 = md2[i];
		if (!testEquivalence(f1,f2))
		{
			return false;
		}
		md1++;
	}
	return true;
}

// test equivalence of two matrix4 with reasonable accuracy, note: second matrix is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Matrix4& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 16; i++) 
	{
		if (!testEquivalence(*md1, md2[i]))
		{
			return false;
		}
		md1++;

	}
	return true;
}

// test equivalence of two vector2 with reasonable accuracy, note: second vector is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Vector2& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 2; i++)
	{
		if (!testEquivalence(*md1, md2[i]))
		{
			return false;
		}
		md1++;
	}
	return true;
}

// test equivalence of two vector3 with reasonable accuracy, note: second vector is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Vector3& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 3; i++)
	{
		if (!testEquivalence(*md1, md2[i]))
		{
			return false;
		}
		md1++;
	}
	return true;
}

// test equivalence of two vector4 with reasonable accuracy, note: second vector is stored as a stl vector
bool ConsoleMatrixUnitTests::testEquivalence(const Vector4& m1, std::vector<float> md2)
{
	float* md1 = (float*)&m1;
	for (int i = 0; i < 4; i++)
	{
		if (!testEquivalence(*md1, md2[i]))
		{
			return false;
		}
		md1++;

	}
	return true;
}

// display success message and update scores if result is true
void  ConsoleMatrixUnitTests::test(float test, float answer, const char* testName)
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

// display success message and update scores if two matrix2 are equivalent
void  ConsoleMatrixUnitTests::test(const Matrix2& test, std::vector<float> answer, const char* testName)
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
		std::cout << "Failed: " << "incorrect result: ";
		float* ptr = (float*)&test;
		for (int i = 0; i < 4; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}

// display success message and update scores if two matrix3 are equivalent
void  ConsoleMatrixUnitTests::test(const Matrix3& test, std::vector<float> answer, const char* testName)
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
		std::cout << "Failed: " << "incorrect result: ";
		float* ptr = (float*)&test;
		for (int i = 0; i < 9; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}

// display success message and update scores if two matrix4 are equivalent
void  ConsoleMatrixUnitTests::test(const Matrix4& test, std::vector<float> answer, const char* testName)
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
		std::cout << "Failed: " << "incorrect result: ";
		float* ptr = (float*)&test;
		for (int i = 0; i < 16; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}

// display success message and update scores if two vector2 are equivalent
void  ConsoleMatrixUnitTests::test(const Vector2& test, std::vector<float> answer, const char* testName)
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
		float* ptr = (float*)&test;
		for (int i = 0; i < 2; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}

// display success message and update scores if two vector3 are equivalent
void  ConsoleMatrixUnitTests::test(const Vector3& test, std::vector<float> answer, const char* testName)
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
		std::cout << "Failed: " << "incorrect result: ";
		float* ptr = (float*)&test;
		for (int i = 0; i < 3; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}

// display success message and update scores if two vector4 are equivalent
void  ConsoleMatrixUnitTests::test(const Vector4& test, std::vector<float> answer, const char* testName)
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
		std::cout << "Failed: " << "incorrect result: ";
		float* ptr = (float*)&test;
		for (int i = 0; i < 4; i++)
		{
			std::cout << *ptr++ << ", ";
		}
	}
	std::cout << testName << std::endl;
}
#endif