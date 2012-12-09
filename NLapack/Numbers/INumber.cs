using NLapack.Matrices;

namespace NLapack.Numbers
{
    public interface INumber
    {
        double DoubleValue { set; }
        double Re { get; }
        //to getter
        INumber Value { set; }
        //IMatrix<> getMatrix();
        INumber Isum(INumber arg);
        INumber Idif(INumber arg);
        INumber Imul(INumber arg);
        INumber Idiv(INumber arg);
        INumber Sum(INumber arg);
        INumber Dif(INumber arg);
        INumber Mul(INumber arg);
        INumber Div(INumber arg);
        INumber Conj();
        double Abs();
        double Abssqr();
    }

}
