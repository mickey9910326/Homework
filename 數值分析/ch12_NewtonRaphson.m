clear;clc;
% 非線性系統：牛頓-拉夫生法

% F = '[ (5+x(1)+x(2)) / (50-2*x(1)-x(2))^2 / (20-x(1)) - 0.0004 ; (5+x(1)+x(2)) / (50-2*x(1)-x(2))   / (10-x(2)) - 0.037]'
% f = inline( F ,'x')

F = @(x) ( (5+x(1)+x(2)) / (50-2*x(1)-x(2))^2 / (20-x(1)) - 0.0004  )
%syms x
J = jacobian(F,[x(1),x(2)])

f = inline(F)
j = inline(J)

Max_iter = 10;
es = 0.01;

x =[1,1] 
iter = 0;
ea   = 100;

while iter<Max_iter && ea>es
    jx = j(x);
    fx = f(x);
    dx = jx\fx;
    x  = x-dx;
    iter = iter+1;
    ea = max(abs(dx./x))*100;
end
