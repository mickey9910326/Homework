clear;clc;
%兩矩陣求線性回歸

%
x = [ 10 20  30  40 50    60  70   80];
y = [ 25 70 380 550 610 1220 830 1450];
%
n = length(x)
x = x(:);
y = y(:);
sx  = sum(x);
sy  = sum(y);
sx2 = sum(x.*x);
sy2 = sum(y.*y);
sxy = sum(x.*y);
a(1)= n*sxy-sx*sy
a(2)= sy/n-a(1)*sx/n;
r2  = ( (n*sxy-sx*sy)/sqrt(n*sx2-sx^2)/sqrt(n*sy2-sy^2) )^2;

x_plot = linespace(min(x),max(x),2);
y_plot = a(1)*x_plot+a(2);
plot(x,y,'o',x_plot,y_plot);
grid on;
