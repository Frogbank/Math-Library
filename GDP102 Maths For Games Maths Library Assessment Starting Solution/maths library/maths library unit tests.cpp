#include <iostream>
#include "ConsoleVectorUnitTests.h"
#include "ConsoleMatrixUnitTests.h"

int main()
{
    std::cout << "Running Unit Tests\n";

    // Run Vector unit tests
    // If vector unit tests are not enabled then result is -1 and display suitable message
    ConsoleVectorUnitTests vectorUnitTests;
    int vectorUnitTestsFailed = vectorUnitTests.runTests();
    if (vectorUnitTestsFailed == -1)
    {
        std::cout << "Unit tests for vector maths ibrary have not been run\n";
        vectorUnitTestsFailed = 0;
    }

    // Run matrix unit tests
    // If matrix unit tests are not enabled then result is -1 and display suitable message
    ConsoleMatrixUnitTests matrixUnitTests;
    int matrixUnitTestsFailed = matrixUnitTests.runTests();
    if (matrixUnitTestsFailed == -1)
    {
        std::cout << "Unit tests for matrix maths library have not been run\n";
        matrixUnitTestsFailed = 0;
    }

    if ((vectorUnitTestsFailed == 0) && (matrixUnitTestsFailed == 0))
    {
        std::cout << "All unit tests passed" << std::endl;
    }
}
