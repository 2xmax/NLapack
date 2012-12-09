using System;
using MLapack;
using NLapack.Matrices;

namespace NLapack
{
    public class NLapackLib
    {
        private readonly MLapackLib _lib = new MLapackLib();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <param name="x"></param>
        public void SolveSle(NRealMatrix a, NRealMatrix b, NRealMatrix x)
        {
            _lib.solveSLE(a.ManagedMatrix, b.ManagedMatrix, x.ManagedMatrix);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <returns></returns>
        public NRealMatrix Chol(NRealMatrix a)
        {
            var result = new NRealMatrix();
            _lib.chol(a.ManagedMatrix, result.ManagedMatrix);

            int rows = result.Rows;

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < i; j++)
                    result.ManagedMatrix.setAt(i, j, 0);

            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="matrix"></param>
        /// <param name="w"></param>
        /// <param name="vl"></param>
        /// <param name="vr"></param>
        public void EigenVals(NRealMatrix matrix, NComplexMatrix w, NComplexMatrix vl, NComplexMatrix vr)
        {
            _lib.eigenVals(matrix.ManagedMatrix, w.ManagedMatrix, vl.ManagedMatrix, vr.ManagedMatrix);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="balancec"></param>
        /// <param name="a"></param>
        /// <param name="w"></param>
        /// <param name="vl"></param>
        /// <param name="vr"></param>
        /// <param name="rconde"></param>
        /// <param name="rcondv"></param>
        public void EigenValsX(BalanceType balancec, NRealMatrix a, NComplexMatrix w, NComplexMatrix vl, NComplexMatrix vr, NRealMatrix rconde, NRealMatrix rcondv)
        {
            _lib.eigenValsX(Convert.ToInt16(balancec), a.ManagedMatrix, w.ManagedMatrix, vl.ManagedMatrix, vr.ManagedMatrix, rconde.ManagedMatrix, rcondv.ManagedMatrix);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="p"></param>
        /// <param name="l"></param>
        /// <param name="u"></param>
        public void LupDecompostion(NRealMatrix a, NRealMatrix p, NRealMatrix l, NRealMatrix u)
        {
            _lib.LUPDecomposition(a.ManagedMatrix, p.ManagedMatrix, l.ManagedMatrix, u.ManagedMatrix);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="s"></param>
        /// <param name="u"></param>
        /// <param name="vt"></param>
        public void SvdDecomposition(NRealMatrix a, NRealMatrix s, NRealMatrix u, NRealMatrix vt)
        {
            _lib.SVDDecomposition(a.ManagedMatrix, s.ManagedMatrix, u.ManagedMatrix, vt.ManagedMatrix);
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="distrubutionType"></param>
        /// <param name="seed"></param>
        /// <param name="m"></param>
        /// <param name="n"></param>
        public NRealMatrix RandomMatrix(RandomDistributionType distrubutionType, MCJIMatrix seed, int m,int n)
        {
            return new NRealMatrix(_lib.randomMatrix(Convert.ToUInt16(distrubutionType), seed, m, n));
        }
    }

    internal class NLapackSingleton
    {
        private static MLapackLib _instance;

        private NLapackSingleton()
        {

        }

        public static MLapackLib Instance
        {
            get { return _instance ?? (_instance = new MLapackLib()); }
        }
    }
}
