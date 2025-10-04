class Solution {
public:
    double power(double b, int e) {
        if (e == 0) return 1.0;
        long exp = e;
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }
        double result = 1.0;
        double currentProduct = b;
        for (long i = exp; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= currentProduct;
            }
            currentProduct *= currentProduct;
        }
        return result;
    }
};
