using System;
using System.Text;
using MLapack;
using NLapack.Numbers;

namespace NLapack.Matrices
{
    public class NRealMatrix : IMatrix<NDouble>
    {
        private readonly MCJRMatrix _mat;

        public MCJRMatrix ManagedMatrix
        {
            get { return _mat; }
        }

        public NRealMatrix()
        {
            _mat = new MCJRMatrix();
        }

        public NRealMatrix(int rows, int cols)
        {
            _mat = new MCJRMatrix(rows, cols);
        }

        public NRealMatrix(MCJRMatrix matrix)
        {
            _mat = matrix;
        }

        //deprecated
        public void Allocate(int r, int c)
        {
            _mat.allocate(r, c);
        }

        public bool IsAllocated
        {
            get { throw new NotImplementedException(); }
        }

        public void Release()
        {
            throw new NotImplementedException();
        }

        public IMatrix<INumber> Fabric()
        {
            throw new NotImplementedException();
        }

        public IMatrix<INumber> Fabric(int r, int c)
        {
            throw new NotImplementedException();
        }

        public void Transpose()
        {
            _mat.transpose();
        }

        public void Zero()
        {
            _mat.zero();
        }

        public void One()
        {
            throw new NotImplementedException();
        }

        public void Rand()
        {
            throw new NotImplementedException();
        }

        public void RandSymm()
        {
            throw new NotImplementedException();
        }

        public int Rows
        {
            get { return _mat.rows(); }
        }

        public int Columns
        {
            get { return _mat.cols(); }
        }

        public NDouble GetObjectAt(int r, int c)
        {
            throw new NotImplementedException();
        }

        public void SetAt(int r, int c, NDouble v)
        {
            _mat.setAt(r, c, v._value);
        }

        public NDouble[][] ToArray()
        {
            throw new NotImplementedException();
        }

        public void SetArray(NDouble[][] data)
        {
            throw new NotImplementedException();
        }

        public NDouble[] GetRowArray(int r)
        {
            throw new NotImplementedException();
        }

        public void SetRow(int r, NDouble[] v)
        {
            throw new NotImplementedException();
        }

        public NDouble[] GetColumnArray(int c)
        {
            throw new NotImplementedException();
        }

        public void SetColumn(int r, NDouble[] v)
        {
            throw new NotImplementedException();
        }

        public NDouble[][] GetSubMatrixArray(int r, int c, int nr, int nc)
        {
            throw new NotImplementedException();
        }

        public void SetSubMatrix(int r, int c, NDouble[][] v)
        {
            throw new NotImplementedException();
        }

        public IMatrix<NDouble> MakeSubMatrix(int r, int c, int nr, int nc)
        {
            throw new NotImplementedException();
        }

        public void SetSubMatrix(int r, int c, IMatrix<NDouble> v)
        {
            throw new NotImplementedException();
        }

        public void CopyBlock(int r, int c, int nr, int nc, int dr, int dc, IMatrix<NDouble> dst)
        {
            throw new NotImplementedException();
        }

        public void Conjugate()
        {
            throw new NotImplementedException();
        }

        public void Diag(INumber[] elts)
        {
            throw new NotImplementedException();
        }

        public void MakePosDefSymmMatrix()
        {
            throw new NotImplementedException();
        }

        public double this[int row, int col]
        {
            get
            {
                return _mat.getAt(row, col);
            }
            set
            {
                _mat.setAt(row, col, value);
            }
        }
        
        public double ConditionNumer
        {
            get
            {
                return NLapackSingleton.Instance.matrixRConditionNumber(Convert.ToSByte(MatrixNormType.OneNorm), _mat);
            }
        }


        public static NRealMatrix operator *(NRealMatrix a, NRealMatrix b)
        {
            var c = new MCJRMatrix();
            NLapackSingleton.Instance.multiply(a.ManagedMatrix, b.ManagedMatrix, c);
            return new NRealMatrix(c);
        }

        public static NRealMatrix operator !(NRealMatrix a)
        {
            var c = new MCJRMatrix();
            NLapackSingleton.Instance.inv(a.ManagedMatrix, c);
            return new NRealMatrix(c);
        }

        static public explicit operator double(NRealMatrix a)
        {
            return NLapackSingleton.Instance.norm(Convert.ToSByte(MatrixNormType.OneNorm), a.ManagedMatrix);
        }

        public void Fill(Func<int, int, double > f)
        {
            int rows = Rows;
            int cols = Columns;
            
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    this[i, j] = f(i, j);
                }
            }
        }


        public override string ToString()
        {
            int rows = _mat.rows();
            int cols = _mat.cols();

            var sb = new StringBuilder();
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    sb.Append(_mat.getAt(i, j) + " ");
                }
                sb.Append("\n");
            }

            return sb.ToString();
        }
    }
}
