=====HOW TO CREATE A SIMPLE APPLICATION=====
1. Create a new console application (File->New Project->Visual C#->Windows->Console Application)
2. Add reference to NLapack.dll (
	There are two ways:
	a. Using NuGet (most useful)
	If you are familiar with NuGet (if not, reading http://docs.nuget.org/ may be 
	very useful) you can simply install NLapack package (https://nuget.org/packages/NLapack). 
	b. Manual
	1) Right click on References->Add Reference->Browse
	2) Build the project
	3) Copy blas_win32.*, lapack_win32.* unmanaged libraries to the output binary folder (e.g. Debug or Release) 
3. Paste following code to Program.cs and run the project:
using System;
using NLapack;
using NLapack.Matrices;
 
namespace nlapackTestHello
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = new NRealMatrix(3, 3);
            A[0, 0] = 2; A[0, 1] = 5; A[0, 2] = 3;
            A[1, 0] = 1; A[1, 1] = 5; A[1, 2] = 7;
            A[2, 0] = 8; A[2, 1] = 2; A[2, 2] = 3;
 
            var B = new NRealMatrix(3, 3);
 
            //generate upper triangular matrix 
            B.Fill((i, j) => i <= j ? i + j + 1 : 0);
            Console.WriteLine(B);
 
            var lib = new NLapackLib();
 
            var X = new NRealMatrix();
            //solve A * X = B
            lib.SolveSle(A, B, X);
 
            Console.WriteLine(X);
        }
    }
}

