clc
clear

f = @(x) x.*exp(2*x);

fprintf('\n(a)romberg\n')
[q,ea,iter]=romberg(f,0,3,0.5);
q
fprintf('\n(b) 兩點高斯二次式\n')
a=0;    
b=3; 
xd1=1/sqrt(3);
xd2=-1/sqrt(3);
f_1=((a+b)/2+(b-a)/2*xd1)*exp((a+b)+(a+b)*xd1)*(b-a)/2;
f_2=((a+b)/2+(b-a)/2*xd2)*exp((a+b)+(a+b)*xd2)*(b-a)/2;
fx=(f_1+f_2)

fprintf('\n(c) 使用內建函數quad,quad1\n')
q  = quad (f,0,3,0.5*0.01) 
ql = quadl(f,0,3,0.5*0.01) 
