function m=naspline(x,y,dy0,dyn,xx)
    n=length(x)-1;
    h=diff(x);
    lemda=h(2/n)./(h(1:n-1)+h(2:n));
    mu=1-lemda;
    g=3*(lemda.*diff(y(1:n))./h(1:n-1)+mu.*diff(y(2:n+1))./h(2:n));
    g(1)=g(1)-lemda(1)*dy0;g(n-1)=g(n-1)-mu(n-1)*dyn;
    dy=nachase(lemda,2*ones(1:n-1),mu,g);
    m=[dy0;dy;dyn];
    if nargin>=5
        s=zeros(size(xx));
        for i=1:n
            if i==1,
                kk=find(xx<=x(2));
            elseif i==n
                kk=find(xx>x(n));
            else
                kk=find(xx>x(i)&xx<=x(i+1));
            end
            xbar=(xx(kk)-x(i))/h(i);
            s(kk)=alpha0(xbar)*y(i)+alpha1(xbar)*y(i+1)+h(i)*beta0(xbar)*m(i)+h(i)*beta1(xbar)*m(i+1);
        end
        m=s;
    end
function x=nachase(a,b,c,d) n=length(a);
    for k=2:n
        b(k)=b(k)-a(k)/b(k-1)*c(k-1);
        d(k)=d(k)-a(k)/b(k-1)*d(k-1);
    end
    x(n)=d(n)/b(n);
    for k=n-1:-1:1
        x(k)=(d(k)-c(k)*x(k+1))/b(k);
    end
x=x(:);
function y=alpha0(x)
    y=2*x.^3-3*x.^2+1;
function y=alpha1(x)
    y=-2*x.^3+3*x.^2;
function y=beta0(x)
    y=x.^3-2*x.^2+x;
function y=beta1(x)
    y=x.^3-x.^2;
