clear;clc;
x = [3 4 5 7 8 9 11 12 ]';
y = [1.6 3.6 4.4 3.4 2.2 2.8 3.8 4.6]';
m = 3;

[a,r2,Syx]=PolyReg(x,y,m)