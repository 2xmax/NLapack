using System;
using NLapack;
using NLapack.Matrices;

namespace nlapackTestHello
{
    class Program
    {
        static void Main(string[] args)
        {
            //new TestClass().Test();
            /*var A = new NRealMatrix(3, 3);
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

            double norm = (double)(A * X * !B);
            //!B is inverse matrix of B
            Console.WriteLine(X);
            Console.WriteLine("1 - norm of identity matrix = " + norm);*/

            var matrix = new NRealMatrix(3, 3);
            
            var A = new NRealMatrix(3, 3);
            var B = new NRealMatrix(3, 3);
            
            
            double norm = (double) matrix;

            NRealMatrix C = A*!B;
        }
    }
}
