function [q,ea,iter]=romberg(func,a,b,es,maxit,varargin)
if nargin<3,error('at least 3 input arguments required'),end
if nargin<4|isempty(es),es=0.000001;end
if nargin<5|isempty(maxit),maxit=50;end
n=1;
I(1,1)=trap(func,a,b,n,varargin{:});
iter=0;
while iter<maxit
    iter=iter+1;
    n=2^iter;
    I(iter+1,1)=trap(func,a,b,n,varargin{:});
    for k=2:iter+1
        j=2+iter-k;
        I(j,k)=(4^(k-1)*I(j+1,k-1)-I(j,k-1))/(4^(k-1)-1);
    end
    ea=abs(I(1,iter+1)-I(2,iter))/I(1,iter+1)*100;
    if ea<=es
        break;
    end
end
q=I(1,iter+1);
        