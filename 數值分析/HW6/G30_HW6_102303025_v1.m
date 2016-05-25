clc;clear;
format long
% input
f = @(x) 2/sqrt(pi)*exp(-x^2);
a = 0;
b = 0.8;

% operation
x = @(xd) ((b+a) + (b-a)*xd)/2;
const_dx = (b-a)/2;

c2 = [1 1];
x2 = [-1/sqrt(3) 1/sqrt(3)];
I_guass_2     = ( c2(1)*f(x(x2(1))) + c2(2)*f(x(x2(2))) )*const_dx
err_I_guass_2 = abs(I_guass_2-erf(1.5))/erf(1.5)

c3 = [5/9 8/9 5/9];
x3 = [-sqrt(3/5) 0.0 sqrt(3/5)];
I_guass_3     = ( c3(1)*f(x(x3(1))) + c3(2)*f(x(x3(2))) + c3(1)*f(x(x3(3))) )*const_dx
err_I_guass_3 = abs(I_guass_3-erf(1.5))/erf(1.5)