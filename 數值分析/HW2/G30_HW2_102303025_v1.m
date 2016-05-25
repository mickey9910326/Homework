clear;
clc;
%funtion set
syms a;
y = a^5 - 16.05*a^4 + 88.75*a^3 - 192.0375*a^2 + 116.35*a + 31.6875;
dy = diff(y);
f  = inline(y);
df = inline(dy);

%Newton-Ranphson method
x(1)   = 0.5825;
es     = 0.01*0.01;
err(1) = 1;
i      = 1;
while(err(i) > es)
    x(i+1)   = x(i) - f( x(i) ) / df( x(i) );
    err(i+1) = abs( ( x(i+1)-x(i) )/x(i+1) );
    i = i+1;
end
fprintf('Newton-Ranphson method  -> ');
fprintf('times: %d ,root: %f ,err: %.df%% \n',i-1,x(i),err(i)*100);

clear x err;
%modified secant mothod
x(1)   = 0.585;
delta  = 0.05;
es     = 0.01*0.01;
err(1) = 1;
i      = 1;
while(err(i)>es)
    x(i+1)   = x(i) - (delta*x(i)*f(x(i))) / ( f( x(i)+delta*x(i) ) - f(x(i)) ) ;
    err(i+1) = abs( ( x(i+1)-x(i) )/x(i+1) );
    i = i+1;
end
fprintf('modified secant mothod  -> ');
fprintf('times: %d ,root: %f ,err: %.df%% \n',i-1,x(i),err(i)*100);

fprintf('�]���y�w�Ԥҥͪk�b���禡�W�J��F���Ĥ��}�����ΡA�bx=1���a��]�ײv�Ӥp�A�ҥH���Ĩ�F�������a��\n');
fprintf('�ӥ��Ϊk�S�������D�A�ҥH���M��l�Ȥ@�ˡA����̨D�X���Ѧb���P��m�W\n');

