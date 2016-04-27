clear;clc;
% ����-�ɼw�k Gauss-Seidel method
% �O�o�[��ı���
% Step 1 �ѼƳ]�m
A = [3, -0.1, -0.2 ; 0.1, 7, -0.3 ; 0.3, -0.2, 10];
b = [7.85, -19.3, 71.4];
[D,d] = size(A);
es    = 0.05; %percent
max_iteration = 120; %�̤j���N����
% Step 2 �x�}�ഫ
C = A;
x(1:D,1) = 0; %initial the x tj store the answer
for i = 1:D
    C(i,i)   = 0;
    C(i,1:D) = C(i,1:D)/A(i,i);
    d(1,i)   = b(i)    /A(i,i);
end
% Step 3 �}�l���N
iteration = 0;   %�g���p��
ea(1:D,1)   = 100; %�O�_�l�~�t��100%
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
