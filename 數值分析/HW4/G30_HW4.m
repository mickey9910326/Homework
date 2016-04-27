
x = [3 4 5 7 8 9 11 12 ];
y = [1.6 ];
m = 2;

n = length(x);
sx  = sum(x.^1);
sx2 = sum(x.^2);
sx3 = sum(x.^3);
sx4 = sum(x.^4);

sy   =sum(y);
sxy  =sum(x.*y);
sx2y =sum(x.*x.*y);

sy2  =sum(y.^2);

N = [   n,  sx, sx2
       sx, sx2, sx3
      sx2, sx3, sx4];
r = [sy;sxy;sx2y];
a = N\r;

ay = mean(y)
St  = sum((y-ay).^2)
Sr  = sum( ( y-a(1)-a(2)*x-a(3)*(x.^2) ).^2 )
Syx = sqrt(Sr/(n-m-1));
r2  = (St-Sr)/St;
%R = (n*sxy-sx*sy)/sqrt(n*sx2-sx^2)/sqrt(n*sy2-sy^2);

a
r2
Syx
