clear; clc;
A = [0 2 5; 2 1 1; 3 1 0];
Y = [1;1;2];
%9.4-a
D = det(A)
%9.4-b
for i=1:1:3
    Atmp = A;
    Atmp(:,i) = Y;
    X(i)= det(Atmp)/D;
end
X
%9.4-c
% A = [0 2 5 1; 2 1 1 1; 3 1 0 2];
U = A;
D = size(A); 
U(:,D(2)+1) = Y;

% Ytmp = Y;
%--軸元排序
for i = 1:1:D(1)-1
    for j = i:1:D(1)
        if U(i,i) < U(j,i)
            tmp = U(i,:);
            U(i,:) = U(j,:);
            U(j,:) = tmp;
        end
    end
end
%--下三角消去
for i = 2:1:D(1)
    for j = 1:1:i-1
        U(i,:) = U(i,:) - U(i,j)/U(j,j).*U(j,:);
    end
end
%--上三角消去+求解
for i = D(1):-1:1
    U(i,:) = U(i,:)/U(i,i);
    for j  = D(1):-1:i+1
        U(i,:) = U(i,:) - U(i,j)/U(j,j).*U(j,:);
    end
end
U