clear;clc;
x = [3 4 5 7 8 9 11 12 ];
y = [1.6 3.6 4.4 3.4 2.2 2.8 3.8 4.6];
m = 3;

n = length(x);
sx  = sum(x.^1);
sx2 = sum(x.^2);
sx3 = sum(x.^3);
sx4 = sum(x.^4);
sx5 = sum(x.^5);
sx6 = sum(x.^6);

sy   =sum(y);
sxy  =sum(x.*y);
sx2y =sum(x.^2.*y);
sx3y =sum(x.^3.*y);

sy2  =sum(y.^2);

N = [   n,  sx, sx2, sx3
       sx, sx2, sx3, sx4
      sx2, sx3, sx4, sx5
      sx3, sx4, sx5, sx6];
r = [sy;sxy;sx2y;sx3y];
a = N\r;

ay = mean(y);
St  = sum((y-ay).^2);
Sr  = sum( ( y-a(1) - a(2)*x - a(3)*(x.^2) - a(4)*(x.^3) ).^2 );
Syx = sqrt(Sr/(n-m-1));
r2  = (St-Sr)/St;

a
r2
Syx
