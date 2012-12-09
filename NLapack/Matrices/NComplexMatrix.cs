using System;
using System.Text;
using MLapack;
using NLapack.Numbers;

namespace NLapack.Matrices
{
    public class NComplexMatrix : IMatrix<NComplex>
    {
        private readonly MCJCMatrix _mat;

        public NComplexMatrix()
        {
            _mat = new MCJCMatrix();
        }

        public NComplexMatrix(MCJCMatrix mat)
        {
            _mat = mat;
        }

        public NComplexMatrix(int rows, int cols)
        {
            _mat = new MCJCMatrix(rows, cols);
        }

        public MCJCMatrix ManagedMatrix
        {
            get { return _mat; }
        }

        public void Allocate(int r, int c)
        {
            throw new NotImplementedException();
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
            throw new NotImplementedException();
        }

        public void Zero()
        {
            throw new NotImplementedException();
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
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public int Columns
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public NComplex GetObjectAt(int r, int c)
        {
            throw new NotImplementedException();
        }

        public void SetAt(int r, int c, NComplex v)
        {
            throw new NotImplementedException();
        }

        public NComplex[][] ToArray()
        {
            throw new NotImplementedException();
        }

        public void SetArray(NComplex[][] data)
        {
            throw new NotImplementedException();
        }

        public NComplex[] GetRowArray(int r)
        {
            throw new NotImplementedException();
        }

        public void SetRow(int r, NComplex[] v)
        {
            throw new NotImplementedException();
        }

        public NComplex[] GetColumnArray(int c)
        {
            throw new NotImplementedException();
        }

        public void SetColumn(int r, NComplex[] v)
        {
            throw new NotImplementedException();
        }

        public NComplex[][] GetSubMatrixArray(int r, int c, int nr, int nc)
        {
            throw new NotImplementedException();
        }

        public void SetSubMatrix(int r, int c, NComplex[][] v)
        {
            throw new NotImplementedException();
        }

        public IMatrix<NComplex> MakeSubMatrix(int r, int c, int nr, int nc)
        {
            throw new NotImplementedException();
        }

        public void SetSubMatrix(int r, int c, IMatrix<NComplex> v)
        {
            throw new NotImplementedException();
        }

        public void CopyBlock(int r, int c, int nr, int nc, int dr, int dc, IMatrix<NComplex> dst)
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

        public NComplex this[int row, int col]
        {
            get
            {
                //todo:
                return new NComplex(_mat.getAt(row, col), _mat.getAtIm(row, col));
            }
            set
            {
                _mat.setAt(row, col, value.Re, value.Im);
            }
        }

        public static NComplexMatrix operator *(NComplexMatrix a, NComplexMatrix b)
        {
            var c = new MCJCMatrix();
            NLapackSingleton.Instance.multiply(a.ManagedMatrix, b.ManagedMatrix, c);
            return new NComplexMatrix(c);
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
                    sb.Append(new NComplex(_mat.getAt(i, j), _mat.getAtIm(i, j)) + " ");
                }
                sb.Append("\n");
            }

            return sb.ToString();
        }
    }
}
