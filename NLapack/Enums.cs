namespace NLapack
{
    public enum MatrixNormType
    {
        OneNorm = '1',
        Infinity = 'I',
        Frobenius = 'F'
    }

    public enum RandomDistributionType
    {
        Uniform_0_1 = 1,
        Uniform_minus1_1 = 2,
        Normal = 3
    }

    /// <summary>
    /// Indicates how the input matrix should be diagonally scaled   
    ///       and/or permuted to improve the conditioning of its   
    ///        eigenvalues
    /// </summary>
    public enum BalanceType
    {
        None = 0,//Do not diagonally scale or permute;  
        Permutation = 1,//Perform permutations to make the matrix more nearly upper triangular. Do not diagonally scale; 
        Scale = 2, /*Diagonally scale the matrix, i.e. replace A by   
                   D*A*D**(-1), where D is a diagonal matrix chosen   
                   to make the rows and columns of A more equal in   
                   norm. Do not permute; */
        Both = 3 //Both diagonally scale and permute A.
    }
}
