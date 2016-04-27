clear;clc;
% �P���ʪ�����-�ɼw�k
% Gauss-Seidel method with Relation
% Step 1 �ѼƳ]�m
A = [10,-2;-3,12];
b = [8;9];
[D,d] = size(A);
es    = 10;    %percent
lambda= 1.2;   %lambda
Max_iter = 20; %�̤j���N����
r     =  1.2;
% Step 2 �x�}�ഫ

C = A;
x(1:D,1) = 0; %initial the x tj store the answer
xr(1:D,1) = 0;
for i = 1:D
    C(i,i)   = 0;
    C(i,1:D) = C(i,1:D)/A(i,i);
    d(1,i)   = b(i)    /A(i,i);
end
% Step 3 �}�l���N
iteration = 0;   %�g���p��
ea(1:D,1)   = 100; %�O�_�l�~�t��100%
while( (max(ea)>es) && (iteration < Max_iter) )
    iteration = iteration +1;
    xrold = xr;
    for i = 1:D
        %Gauss-Seidel method  with Relation operation
        x(i) = d(i)-C(i,:)*xr;
        xr(i) = lambda*x(i) +(1-lambda)*xrold(i);
        if x(i) ~= 0
            ea(i) = abs( ( xr(i)-xrold(i) )/xr(i) ) *100;  %calculate the err in iteration
        end
    end
end
xr
iteration
