clc;clear;
format long

f=@(x) 2/sqrt(pi)*exp(-x^2);
a=0;
b=1.5;
x=@(x2) ((b+a)+(b-a)*x2)/2;
dx=(b-a)/2;

I_g2=(f(x(-1/sqrt(3))) + f(x(1/sqrt(3))) )*dx
err_I_g2=abs(I_g2-erf(1.5))/erf(1.5)

I_g3=(5/9*f(x(-sqrt(3/5)))+8/9*f(x(0))+5/9*f(x(sqrt(3/5))))*dx
err_I_g3 = abs(I_g3-erf(1.5))/erf(1.5)
