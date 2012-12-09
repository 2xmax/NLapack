using System;
using MLapack;
using NLapack.Matrices;

namespace NLapack
{

    public class TestClass
    {

        public void GetAtSetAtTest()
        {
            var mat = new MCJRMatrix();

            const int size = 5000;

            mat.allocate(size, size);

            var random = new Random();


            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    double value = random.NextDouble();
                    mat.setAt(i, j, value);
                }
            }
        }

        public void TestMult()
        {
            var lib = new MLapackLib();

            var mat1 = new MCJRMatrix(2, 3);
            mat1.setAt(0, 0, 1);
            mat1.setAt(0, 1, 2);
            mat1.setAt(0, 2, 3);

            mat1.setAt(1, 0, 4);
            mat1.setAt(1, 1, 5);
            mat1.setAt(1, 2, 6);

            var mat2 = new MCJRMatrix(3, 2);

            mat2.setAt(0, 0, 1);
            mat2.setAt(0, 1, 2);

            mat2.setAt(1, 0, 3);
            mat2.setAt(1, 1, 4);

            mat2.setAt(2, 0, 5);
            mat2.setAt(2, 1, 6);

            var mat3 = new MCJRMatrix();
            lib.multiply(mat1, mat2, mat3);
            PrintMatrix(mat3);
        }

        public void PrintMatrix(MCJRMatrix matrix)
        {
            int rows = matrix.rows();
            int cols = matrix.cols();

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write(matrix.getAt(i, j) + " ");
                }
                Console.WriteLine("");
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public void TestMultBig()
        {
            for (int size = 100; size <= 4500; size += 100)
            {
                try
                {
                    Console.WriteLine(size);
                    var mat1 = new MCJRMatrix(size, size);

                    var random = new Random();

                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            mat1.setAt(i, j, random.NextDouble());
                        }
                    }


                    var mat2 = new MCJRMatrix(size, size);

                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            mat2.setAt(i, j, random.NextDouble());
                        }
                    }

                    var mat3 = new MCJRMatrix();

                    var time = DateTime.Now;
                    var lib = new MLapackLib();

                    Console.WriteLine("multiplication started...");
                    lib.multiply(mat1, mat2, mat3);

                    Console.WriteLine("multiplication completed.");

                    Console.WriteLine("size = " + size + "time = " + (DateTime.Now - time).TotalMilliseconds);

                }
                catch (Exception)
                {

                    Console.WriteLine("exception");
                }
            }

        }
        
        public double TestMultZBig(int size)
        {
            var mat1 = new MCJCMatrix(size, size);
            var mat2 = new MCJCMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble(), random.NextDouble());
                    mat2.setAt(i, j, random.NextDouble(), random.NextDouble());
                }
            }
           
            

            var mat3 = new MCJCMatrix();

            var time = DateTime.Now;
            Console.WriteLine("multiplication started...");
            
            var lib = new MLapackLib();

            lib.multiply(mat1, mat2, mat3);

            double elapsedTime = (DateTime.Now - time).TotalMilliseconds;

            Console.WriteLine("multiplication completed.");

            Console.WriteLine("size = " + size + "time = " + (DateTime.Now - time).TotalMilliseconds);

            return elapsedTime;
        }

        public double TestMultdBig(int size)
        {
            var mat1 = new MCJRMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble());
                }
            }


            var mat2 = new MCJRMatrix(size, size);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat2.setAt(i, j, random.NextDouble());
                }
            }

            var mat3 = new MCJRMatrix();

            var time = DateTime.Now;
            Console.WriteLine("multiplication started...");

            var lib = new MLapackLib();

            lib.multiply(mat1, mat2, mat3);

            double elapsedTime = (DateTime.Now - time).TotalMilliseconds;

            Console.WriteLine("multiplication completed.");

            Console.WriteLine("size = " + size + "time = " + (DateTime.Now - time).TotalMilliseconds);

            return elapsedTime;
        }

        public void TestMultZ()
        {
            var lib = new MLapackLib();

            var mat1 = new MCJCMatrix(2, 2);
            mat1.setAt(0, 0, 1, 0);
            mat1.setAt(0, 1, 2 ,0);
            mat1.setAt(1, 0, 3, 0);
            mat1.setAt(1, 1, 4, 0);

            var mat2 = new MCJCMatrix(2, 2);
            mat2.setAt(0, 0, 1, 0);
            mat2.setAt(0, 1, 2, 0);
            mat2.setAt(1, 0, 3, 0);
            mat2.setAt(1, 1, 4, 0);

            var mat3 = new MCJCMatrix();
            lib.multiply(mat1, mat2, mat3);
            Console.WriteLine(new NComplexMatrix(mat3));
        }

        public void TestInv()
        {
            var mat1 = new MCJRMatrix(2, 2);
            mat1.setAt(0, 0, 1);
            mat1.setAt(0, 1, 2);

            mat1.setAt(1, 0, 3);
            mat1.setAt(1, 1, 4);

            var lib = new MLapackLib();

            var result = new MCJRMatrix();
            lib.inv(mat1, result);

            PrintMatrix(result);
        }

        public void TestNorm()
        {
            var mat1 = new MCJRMatrix(3, 2);

            mat1.setAt(0, 0, 8);
            mat1.setAt(0, 1, 8);

            mat1.setAt(1, 0, 3);
            mat1.setAt(1, 1, -2);

            mat1.setAt(2, 0, 8);
            mat1.setAt(2, 1, -8);

            CalcNorm(mat1, MatrixNormType.Frobenius);
        }

        private static void CalcNorm(MCJRMatrix matrix, MatrixNormType normType)
        {
            var lib = new MLapackLib();
            double norm = lib.norm(Convert.ToSByte(normType), matrix);

            Console.WriteLine("norm = " + norm);
        }

        public void JMatrixTest()
        {
            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;

            var matrix2 = new NRealMatrix(2, 2);
            matrix2[0, 0] = 5;
            matrix2[0, 1] = 6;
            matrix2[1, 0] = 7;
            matrix2[1, 1] = 8;

            var matrix3 = matrix1 * matrix2;

        }

        public void LupDecompositionTest()
        {
            var a = new NRealMatrix(3, 3);
            a[0, 0] = 1;
            a[0, 1] = 2;
            a[0, 2] = 3;

            a[1, 0] = 4;
            a[1, 1] = 5;
            a[1, 2] = 6;

            a[2, 0] = 7;
            a[2, 1] = 8;
            a[2, 2] = 9;

            var p = new NRealMatrix(3, 3);
            p[0, 0] = 1;
            p[0, 1] = 0;
            p[0, 2] = 0;

            p[1, 0] = 0;
            p[1, 1] = 0;
            p[1, 2] = 1;

            p[2, 0] = 0;
            p[2, 1] = 1;
            p[2, 2] = 0;


            Console.WriteLine(p * a);

            var l = new NRealMatrix(3, 3);
            var u = new NRealMatrix(3, 3);

            Console.WriteLine(a);
            Console.WriteLine(p);

            
            var mlib = new NLapackLib();
            mlib.LupDecompostion(a, p, l, u);

            //var lib = new MLapackLib();
            //lib.LUPDecomposition(a.ManagedMatrix, p.ManagedMatrix, l.ManagedMatrix, u.ManagedMatrix);

            Console.WriteLine(l);
            Console.WriteLine(u);

            var result = l * u;
            Console.WriteLine(result);

            Console.WriteLine(p * a);
        }

        public void EigenValsTest()
        {
            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;

            var w = new MCJCMatrix(2, 2);
            var vl = new MCJCMatrix(2, 2);
            var vr = new MCJCMatrix(2, 2);

            var lib = new MLapackLib();

            lib.eigenVals(matrix1.ManagedMatrix, w, vl, vr);

            Console.WriteLine("w");
            PrintComplexMatrix(w);

            Console.WriteLine("vl");
            PrintComplexMatrix(vl);

            Console.WriteLine("vr");
            PrintComplexMatrix(vr);
        }

        public void EigenValsTestManaged()
        {
            var w = new NComplexMatrix(2, 2);
            var vl = new NComplexMatrix(2, 2);
            var vr = new NComplexMatrix(2, 2);

            var lib = new NLapackLib();

            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;

            lib.EigenVals(matrix1, w, vl, vr);

            Console.WriteLine("w=\n" + w);
            Console.WriteLine("vl=\n" + vl);
            Console.WriteLine("vr=\n" + vl);
        }

        public void PrintComplexMatrix(MCJCMatrix matrix)
        {
            int cols = matrix.cols();
            int rows = matrix.rows();

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    double re = matrix.getAt(i, j);
                    double im = matrix.getAtIm(i, j);

                    Console.Write("({0};{1})  ", re, im);
                }
                Console.WriteLine();
            }
        }

        public void CholTest()
        {
            var a = new NRealMatrix(3, 3);

            a[0, 0] = 2;
            a[0, 1] = 1;
            a[0, 2] = 1;

            a[1, 0] = 1;
            a[1, 1] = 2;
            a[1, 2] = 1;

            a[2, 0] = 1;
            a[2, 1] = 1;
            a[2, 2] = 2;

            var lib = new NLapackLib();

            var result = lib.Chol(a);

            Console.WriteLine(result);
        }

        public void SvdDecompositionTest()
        {
            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;

            var s = new NRealMatrix();
            var u = new NRealMatrix();
            var vt = new NRealMatrix();

            var lib = new MLapackLib();

            lib.SVDDecomposition(matrix1.ManagedMatrix, s.ManagedMatrix, u.ManagedMatrix, vt.ManagedMatrix);

            Console.WriteLine(matrix1);
            Console.WriteLine(s);
            Console.WriteLine(u);
            Console.WriteLine(vt);
        }

        public void ConditionNumerTest()
        {
            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;

            var lib = new MLapackLib();

            var conditionNumber = lib.matrixRConditionNumber(Convert.ToSByte(MatrixNormType.OneNorm), matrix1.ManagedMatrix);

            Console.WriteLine("condNum = " + conditionNumber);
            /*var norm = (double)matrix1;
            var normInv = (double)(!matrix1);
            
            Console.WriteLine(norm + " " + normInv);
            Console.WriteLine(1/(norm * normInv));*/
        }

        public void RandomMatrixTest()
        {
            var seed = new MCJIMatrix(2, 2);
            seed.setAt(0, 0, 1);
            seed.setAt(0, 1, 3);
            seed.setAt(1, 0, 5);
            seed.setAt(1, 1, 7);

            var nlib = new NLapackLib();

            for (int i = 0; i < 10; i++)
            {
                var result = nlib.RandomMatrix(RandomDistributionType.Uniform_0_1, seed, 2, 2);
                Console.WriteLine(result);
            }
        }

        public void EigenValsXTest()
        {
            var matrix1 = new NRealMatrix(2, 2);
            matrix1[0, 0] = 1;
            matrix1[0, 1] = 2;
            matrix1[1, 0] = 3;
            matrix1[1, 1] = 4;


            var w = new NComplexMatrix(2, 2);
            var vl = new NComplexMatrix(2, 2);
            var vr = new NComplexMatrix(2, 2);

            var rconde = new NRealMatrix(2, 2);
            var rcondv = new NRealMatrix(2, 2);

            //var lib = new MLapackLib();
            //lib.eigenValsX(Convert.ToInt16(BalanceType.None), matrix1, w, vl, vr, rconde, rcondv);
            
            var nlib = new NLapackLib();
            nlib.EigenValsX(BalanceType.None, matrix1, w, vl, vr, rconde, rcondv);

            Console.WriteLine("w=");
            Console.WriteLine(w);

            Console.WriteLine("vl=");
            Console.WriteLine(vl);

            Console.WriteLine("vr=");
            Console.WriteLine(vr);

            Console.WriteLine("rconde=");
            Console.WriteLine(rconde);

            Console.WriteLine("rcondv=");
            Console.WriteLine(rcondv);
        }

        public double SvdTestBig(int size)
        {
            var mat1 = new MCJRMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble());
                }
            }

            var lib = new MLapackLib();

            Console.WriteLine("multiplication started...");

            var s = new MCJRMatrix();
            var u = new MCJRMatrix();
            var vt = new MCJRMatrix();

            var time = DateTime.Now;
            lib.SVDDecomposition(mat1, s, u, vt);

            double elapsedTime = (DateTime.Now - time).TotalMilliseconds;
            Console.WriteLine("time = " + elapsedTime);
            return elapsedTime;
        }

        public double SvdzTestBig(int size)
        {
            var mat1 = new MCJCMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble(), 0);
                }
            }

            var lib = new MLapackLib();

            Console.WriteLine("multiplication started...");

            var s = new MCJRMatrix();
            var u = new MCJCMatrix();
            var vt = new MCJCMatrix();

            var time = DateTime.Now;
            lib.SVDDecomposition(mat1, s, u, vt);

            double ms = (DateTime.Now - time).TotalMilliseconds;
            Console.WriteLine("time = " + ms);
            return ms;
        }

        public double SleTestBig(int size)
        {
            var mat1 = new MCJRMatrix(size, size);
            var mat2 = new MCJRMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble());
                    mat2.setAt(i, j, random.NextDouble());
                }
            }

            var time = DateTime.Now;
            var lib = new MLapackLib();

            var result = new MCJRMatrix(size, size);

            Console.WriteLine("multiplication started...");


            lib.solveSLE(mat1, mat2, result);


            Console.WriteLine("multiplication completed.");

            double ms = (DateTime.Now - time).TotalMilliseconds;
            Console.WriteLine("time = " + ms);
            return ms;
        }

        public double SlezTestBig(int size)
        {
            var mat1 = new MCJCMatrix(size, size);
            var mat2 = new MCJCMatrix(size, size);

            var random = new Random();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mat1.setAt(i, j, random.NextDouble(), 0);
                    mat2.setAt(i, j, random.NextDouble(), 0);
                }
            }

            var time = DateTime.Now;
            var lib = new MLapackLib();

            var result = new MCJCMatrix(size, size);

            Console.WriteLine("multiplication started...");


            lib.solveSLE(mat1, mat2, result);


            Console.WriteLine("multiplication completed.");

            double ms = (DateTime.Now - time).TotalMilliseconds;
            Console.WriteLine("time = " + ms);
            return ms;
        }

        public void SlezTest()
        {
            const int size = 2;
            var mat1 = new MCJCMatrix(2, 2);
            var mat2 = new MCJCMatrix(2, 2);

            mat1.setAt(0, 0, 1, 1);
            mat1.setAt(0, 1, 2, 2);
            mat1.setAt(1, 0, 3, 3);
            mat1.setAt(1, 1, 4, 4);

            mat2.setAt(0, 0, 1, 0);
            mat2.setAt(0, 1, 2, 0);
            mat2.setAt(1, 0, 3, 0);
            mat2.setAt(1, 1, 4, 0);


            Console.WriteLine(new NComplexMatrix(mat1));

            /* mat1.setAt(0, 0, 1);
             mat1.setAt(0, 1, 2);
             mat1.setAt(1, 0, 3);
             mat1.setAt(1, 1, 4);

             mat2.setAt(0, 0, 1);
             mat2.setAt(0, 1, 2);
             mat2.setAt(1, 0, 3);
             mat2.setAt(1, 1, 4);*/

            var time = DateTime.Now;
            var lib = new MLapackLib();

            var result = new MCJCMatrix(size, size);

            lib.solveSLE(mat1, mat2, result);

            Console.WriteLine(new NComplexMatrix(result));

            double ms = (DateTime.Now - time).TotalMilliseconds;
            Console.WriteLine("time = " + ms);
        }

        public void Test()
        {
            //double totalms = 0;
            //for (int i = 0; i < 10; i++)
            //{
            //    totalms += slezTestBig(500);
            //}

            //Console.WriteLine(totalms);
            
            double totalms = 0;
            const int ntests = 3;
            
            TestMultZBig(500);

            for (int i = 0; i < ntests; i++)
            {
                totalms += TestMultZBig(1500);
            }

            Console.WriteLine(totalms / ntests);

            //for (int i = 0; i < 5; i++)
            //    System.Console.Beep();

            //TestMult();
            //slezTest();
            //TestMultBig();
            //EigenValsTestManaged();
        }
    }
}
