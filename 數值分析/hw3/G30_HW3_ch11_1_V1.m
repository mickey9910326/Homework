
%11.1
%{
    10  2   -1  26
    -3  -6  2   -61.5
    1   1   5   -21.5
%}
clear; clc;
A=[10 2 -1 ;-3 -6 2 ;1 1 5];
[L,U]=lu(A);
dt1=inv(L)*[1; 0; 0];
dt2=inv(L)*[0; 1; 0];
dt3=inv(L)*[0; 0; 1];
invA=zeros(3);
invA(:,1)=inv(U)*dt1;
invA(:,2)=inv(U)*dt2;
invA(:,3)=inv(U)*dt3;
A
invA
invA_cross_A = invA*A
