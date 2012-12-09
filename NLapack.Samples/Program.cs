using System;
using NLapack.Matrices;

namespace NLapack.Samples
{
    class Program
    {
        private static void SleTest()
        {
            var a = new NRealMatrix(2, 2);
            a[0, 0] = 2;
            a[0, 1] = 4;
            a[1, 0] = 1;
            a[1, 1] = 3;

            var b = new NRealMatrix(2, 2);
            b[0, 0] = 1;
            b[0, 1] = 0;
            b[1, 0] = 0;
            b[1, 1] = 1;

            var lib = new NLapackLib();
            var x = new NRealMatrix();
            lib.SolveSle(a, b, x);

            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(x);
        }

        private static void SvdTest()
        {
            var a = new NRealMatrix(4, 2);
            a[0, 0] = 2;
            a[0, 1] = 4;
            a[1, 0] = 1;
            a[1, 1] = 3;
            a[2, 0] = 0;
            a[2, 1] = 0;
            a[3, 0] = 0;
            a[3, 1] = 0;

            var lib = new NLapackLib();
            var s = new NRealMatrix();
            var u = new NRealMatrix();
            var vt = new NRealMatrix();

            lib.SvdDecomposition(a, s, u, vt);

            Console.WriteLine(a);
            Console.WriteLine(s);
            Console.WriteLine(u);
            Console.WriteLine(vt);
        }

        private static void InverseTest()
        {
            var a = new NRealMatrix(2, 2);
            a[0, 0] = 2;
            a[0, 1] = 4;
            a[1, 0] = 1;
            a[1, 1] = 3;

            Console.WriteLine(a);
            Console.WriteLine(!a);
        }

        


        static void Main(string[] args)
        {
            SleTest();
        }
    }
}
