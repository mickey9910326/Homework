clc; clear;
fprintf('\n(a)�s����\n')
err = 1;
i = 1; 
while(err>0.5*0.01)
    i = i*2;
    I_Rich = 4/3*I_f(i) - 1/3*I_f(i/2);
    err = abs( I_Rich - I_f(i) )/I_Rich;
end
i
I_Rich
err

% (b) ���I�����G���� -- �Ѧҽҥ�p452
fprintf('\n(b) ���I�����G����\n')
a=0;    
b=3; 
x_d1=1/sqrt(3);
x_d2=-1/sqrt(3);
f_x1=((a+b)/2+(b-a)/2*x_d1)*exp((a+b)+(a+b)*x_d1)*(b-a)/2;
f_x2=((a+b)/2+(b-a)/2*x_d2)*exp((a+b)+(a+b)*x_d2)*(b-a)/2;
f_x=(f_x1+f_x2)

% �ϥ�quad �M quad1
fprintf('\n(c) �ϥ�quad �M quad1\n')
f = @(x) x.*exp(2*x);

q  = quad (f,0,3,0.5*0.01) 
ql = quadl(f,0,3,0.5*0.01) 


