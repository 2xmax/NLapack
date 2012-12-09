using NLapack.Numbers;

namespace NLapack.Matrices
{
    public interface IMatrix<T> where T : INumber
    {
        void Allocate(int r, int c);
        bool IsAllocated { get; }
        void Release();
        IMatrix<INumber> Fabric();
        IMatrix<INumber> Fabric(int r, int c);
        void Transpose();
        void Zero();
        void One();
        void Rand();
        void RandSymm();
        int Rows { get; }
        int Columns { get; }
        T GetObjectAt(int r, int c);
        void SetAt(int r, int c, T v);
        T[][] ToArray();
        void SetArray(T[][] data);
        T[] GetRowArray(int r);
        void SetRow(int r, T[] v);
        T[] GetColumnArray(int c);
        void SetColumn(int r, T[] v);
        T[][] GetSubMatrixArray(int r, int c, int nr, int nc);
        IMatrix<T> MakeSubMatrix(int r, int c, int nr, int nc);
        void SetSubMatrix(int r, int c, T[][] v);
        void SetSubMatrix(int r, int c, IMatrix<T> v);
        void CopyBlock(int r, int c, int nr, int nc, int dr, int dc, IMatrix<T> dst);
        void Conjugate();
        void Diag(INumber[] elts);
        void MakePosDefSymmMatrix();
    }
}
