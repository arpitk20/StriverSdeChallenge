class Solution {
public:
    double myPow(double x, long long n) {
        
        if(n==0)
            return 1.0;
        
        if(n<0)
            return (1.0/pow(x, -n));
        
        double temp = myPow(x, n/2);
        
        if(n%2==0)
            return temp*temp;
        
        else if(n%2==1)
            return x*temp*temp;
        
        return 1.0;
    }
};