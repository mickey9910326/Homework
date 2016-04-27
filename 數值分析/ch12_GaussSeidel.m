clear;clc;
% 高斯-賽德法 Gauss-Seidel method
% 記得觀察收斂情形
% Step 1 參數設置
A = [3, -0.1, -0.2 ; 0.1, 7, -0.3 ; 0.3, -0.2, 10];
b = [7.85, -19.3, 71.4];
[D,d] = size(A);
es    = 0.05; %percent
max_iteration = 120; %最大迭代次數
% Step 2 矩陣轉換
C = A;
x(1:D,1) = 0; %initial the x tj store the answer
for i = 1:D
    C(i,i)   = 0;
    C(i,1:D) = C(i,1:D)/A(i,i);
    d(1,i)   = b(i)    /A(i,i);
end
% Step 3 開始迭代
iteration = 0;   %週期計數
ea(1:D,1)   = 100; %令起始誤差為100%
while( (max(ea)>es) && (iteration < max_iteration) )
    iteration = iteration +1;
    xold = x;
    for i = 1:D
        x(i) = d(i)-C(i,:)*x;  %Gauss-Seidel method operation
        if x(i) ~= 0
            ea(i) = abs( ( x(i)-xold(i) )/x(i) ) *100;  %calculate the err in iteration
        end
    end
end
x
iteration
