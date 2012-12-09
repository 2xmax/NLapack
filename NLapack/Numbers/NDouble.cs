using System;
using NLapack.Matrices;

namespace NLapack.Numbers
{
    public class NDouble : INumber
    {
        //todo: make private
        public double _value;

        public NDouble(double value)
        {
            _value = value;
        }

        public static double ValueOf(NDouble arg)
        {
            return arg._value;
        }
        
        public double DoubleValue
        {
            set { _value = value; }
        }

        public INumber Value
        {
            set { _value = ((NDouble) value)._value; }
        }

        public double Re
        {
            get { return _value; }
        }

        
        public IMatrix<NDouble> GetMatrix()
        {
            return new NRealMatrix();
        }

        public INumber Isum(INumber arg)
        {
            throw new NotImplementedException();
        }
        

        public INumber Idif(INumber arg)
        {
            return new NDouble(_value - ((NDouble)arg)._value);
        }

        public INumber Imul(INumber arg)
        {
            throw new NotImplementedException();
        }


        public INumber Idiv(INumber arg)
        {
            return new NDouble(_value / ((NDouble)arg)._value);
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
            return (_value > 0) ? _value : -_value;
        }

        public double Abssqr()
        {
            return _value * _value;
        }

        public INumber Conj()
        {
            return this;
        }


        public override string ToString()
        {
            return _value.ToString();
        }
    }
}
