%--10.3
clear; clc;
A = [7 2 -3 -12 ;2 5 -3 -20 ;1 1 -6 -26];
%--find U
%--高斯簡單消去法求U-----------------------------
U = A;
D = size(A); 
for i=2:1:D(1)      %handle the i col
    for j = 1:i-1   %handle the j position in i col
        U(i,:) = U(i,:)-U(i,j)/U(j,j).*U(j,:);
        %minus the j row to make the j position in i col become 0
    end
end
%-----------------------------------------------
U
%--find L---------------------------------------
L = A/U

%--利用 lu() 驗證--------------------------------
[luL,luU] = lu(A);
luU
luL