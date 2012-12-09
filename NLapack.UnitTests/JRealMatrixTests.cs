using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using NLapack.Matrices;

namespace NLapack.UnitTests
{
    [TestClass]
    public class JRealMatrixTests
    {
        public const double Epsilon = 1e-5;

        [TestMethod]
        public void ZeroTest()
        {
            const int maxN = 10;
            for (int r = 2; r < maxN; r++)
            {
                for (int c = 2; c < maxN; c++)
                {
                    var matrix = new NRealMatrix(r, c);
                    matrix.Zero();

                    for (int i = 0; i < matrix.Rows; i++)
                    {
                        for (int j = 0; j < matrix.Columns; j++)
                        {
                            Assert.AreEqual(Math.Abs(matrix[i, j]), 0, Epsilon);
                        }
                    }
                }
            }
        }

        [TestMethod]
        public void InverseTest()
        {
            const int maxN = 10;
            var random = new Random();
            for (int n = 2; n < maxN; n++)
            {
                var matrix = new NRealMatrix(n, n);
                var unit = new NRealMatrix(n, n);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        matrix[i, j] = random.NextDouble();
                        unit[i, j] = (i == j) ? 1 : 0;
                    }
                }

                var result = matrix * unit;

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Assert.AreEqual(matrix[i, j], result[i, j], Epsilon);
                    }
                }

                result = unit * matrix;

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Assert.AreEqual(matrix[i, j], result[i, j], Epsilon);
                    }
                }
            }
        }


        [TestMethod]
        public void MultiplicationTest()
        {
            var matrix = new NRealMatrix(2, 2);
            matrix[0, 0] = 1;
            matrix[0, 1] = 2;
            matrix[1, 0] = 3;
            matrix[1, 1] = 4;

            var inverse = !matrix;

            var sameMatrix = !inverse;

            for (int i = 0; i < matrix.Rows; i++)
            {
                for (int j = 0; j < matrix.Columns; j++)
                {
                    Assert.AreEqual(sameMatrix[i, j], matrix[i, j], Epsilon);
                }
            }
        }

        [TestMethod]
        public void MultiplicationAndInverseTest()
        {
            var matrix = new NRealMatrix(2, 2);
            matrix[0, 0] = 1;
            matrix[0, 1] = 2;
            matrix[1, 0] = 3;
            matrix[1, 1] = 4;

            var unitMatrix = new NRealMatrix(2, 2);
            //unitMatrix.one();
            unitMatrix[0, 0] = 1;
            unitMatrix[0, 1] = 0;
            unitMatrix[1, 0] = 0;
            unitMatrix[1, 1] = 1;

            var inverse = !matrix;

            var result = matrix * inverse;

            for (int i = 0; i < matrix.Rows; i++)
            {
                for (int j = 0; j < matrix.Columns; j++)
                {
                    Assert.AreEqual(unitMatrix[i, j], result[i, j], Epsilon);
                }
            }
        }

        [TestMethod]
        public void MatrixNormTest()
        {
            const int maxN = 10;
            for (int n = 2; n < maxN; n++)
            {
                var unit = new NRealMatrix(n, n);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        unit[i, j] = (i == j) ? 1 : 0;
                    }
                }

                double norm = (double)unit;
                Assert.AreEqual(1, norm, Epsilon);
            }
        }

        [TestMethod]
        public void SolveSle()
        {
            const int maxN = 10;

            for (int n = 2; n < maxN; n++)
            {
                var random = new Random();

                double mult = random.NextDouble();

                var a = new NRealMatrix(n, n);
                var b = new NRealMatrix(n, n);
                var unit = new NRealMatrix(n, n);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        var value = random.NextDouble();
                        a[i, j] = value;
                        b[i, j] = value * mult;
                        unit[i, j] = (i == j) ? 1 : 0;
                    }
                }

                var x = new NRealMatrix(n, n);

                var lib = new NLapackLib();

                lib.SolveSle(a, b, x);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Assert.AreEqual(x[i, j], unit[i, j] * mult, Epsilon);
                    }
                }
            }
        }

    }
}
