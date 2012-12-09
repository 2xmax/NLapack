using System;
using NLapack.Numbers;

namespace NLapack
{
    public class JNumberMath
    {
        static int GetClassPrior(INumber n)
        {
            if (n is NDouble)
                return 2;
            else if (n is NComplex)
                return 3;
            return -1;
        }

        static INumber Conv(INumber n, INumber nType)
        {
            if (nType is NComplex)
            {
                if (n is NDouble)
                {
                    double re = ((NDouble)n)._value;
                    return new NComplex(re, 0);
                }

                else return n;
            }
            else if (nType is NDouble)
            {

                return n;
            }
            throw new ArgumentException("wrong use of conv method for INumbers");
        }

        static INumber[] GetOps(INumber a, INumber b)
        {
            INumber op1, op2;
            if (GetClassPrior(a) > GetClassPrior(b))
            {
                op1 = a;
                op2 = Conv(b, a);
            }
            else
            {
                op2 = b;
                op1 = Conv(a, b);
            }

            return new INumber[] { op1, op2 };
        }

        public static INumber Sum(INumber a, INumber b)
        {
            INumber[] ops = GetOps(a, b);
            return ops[0].Isum(ops[1]);
        }

        public static INumber Dif(INumber a, INumber b)
        {
            INumber[] ops = GetOps(a, b);
            return ops[0].Idif(ops[1]);
        }

        public static INumber Mul(INumber a, INumber b)
        {
            INumber[] ops = GetOps(a, b);
            return ops[0].Imul(ops[1]);
        }

        public static INumber Div(INumber a, INumber b)
        {
            INumber[] ops = GetOps(a, b);
            return ops[0].Idiv(ops[1]);
        }
    }
}
