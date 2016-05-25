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

fprintf('因牛頓─拉夫生法在此函式上遇到了收斂不良的情形，在x=1的地方因斜率太小，所以收斂到了較遠的地方\n');
fprintf('而正割法沒有此問題，所以雖然初始值一樣，但兩者求出的解在不同位置上\n');

