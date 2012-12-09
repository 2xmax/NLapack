using System;
using NLapack.Matrices;

namespace NLapack.Numbers
{

    public class NComplex : INumber
    {
        public NComplex(double re, double im)
        {
            Re = re;
            Im = im;
        }

        public NComplex()
        {
            throw new NotImplementedException();
        }

        public double DoubleValue
        {
            set
            {
                Re = value;
                Im = 0;
            }
        }

        public INumber Value
        {
            set
            {
                Re = ((NComplex) value).Re;
                Im = ((NComplex) value).Im;
            }
        }

        public double Re { get; private set; }
        
        public double Im { get; private set; }

        public IMatrix<NComplex> GetMatrix()
        {
            return new NComplexMatrix();
        }

        public INumber Isum(INumber arg)
        {
            return new NComplex(Re + ((NComplex)arg).Re, Im + ((NComplex)arg).Im);
        }

        public INumber Idif(INumber arg)
        {
            return new NComplex(Re - ((NComplex)arg).Re, Im - ((NComplex)arg).Im);
        }

        public INumber Imul(INumber arg)
        {
            return new NComplex(Re * ((NComplex)arg).Re - Im * ((NComplex)arg).Im, Re * ((NComplex)arg).Im + Im * ((NComplex)arg).Re);
        }

        public INumber Idiv(INumber arg)
        {
            double z = (((NComplex)arg).Re) * (((NComplex)arg).Re) + (((NComplex)arg).Im) * (((NComplex)arg).Im);
            return new NComplex((Re * ((NComplex)arg).Re + Im * ((NComplex)arg).Im) / z, (-Re * ((NComplex)arg).Im + Im * ((NComplex)arg).Re) / z);
        }
        
        public INumber Sum(INumber arg)
        {
            return JNumberMath.Sum(this, arg);
        }

        public INumber Mul(INumber arg)
        {
            return JNumberMath.Mul(this, arg);
        }

        public INumber Dif(INumber arg)
        {
            return JNumberMath.Dif(this, arg);
        }

        public INumber Div(INumber arg)
        {
            return JNumberMath.Div(this, arg);
        }
        
        public double Abs()
        {
            return Math.Sqrt(Re * Re + Im * Im);
        }

        public double Abssqr()
        {
            return Re * Re + Im * Im;
        }
        
        public INumber Conj()
        {
            return new NComplex(Re, -Im);
        }

        public override int GetHashCode()
        {
            int hash = 371;
            hash += 117 * Re.GetHashCode() + 23 * Im.GetHashCode();
            return hash;
        }

        public override string ToString()
        {
            return "[" + Re + "+i*" + Im + "]";
        }
    }

}
