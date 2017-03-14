clear;clc;
A  = 2;
PHI =
V0 = 30;
LAMBDA = 0.87;
t  = [0:0.01:20];
n  = randi([0 100],1,length(t)) *0.01;

Vt = A * exp( -1*LAMBDA*t ) * cos(W*t+PHI) + V0 + n;

plot(t,Vt)

point = [1;100;20;130;120;140;150;200];

% 

for i=1:length(point)
    Y(i,1) = log(Vt(point(i)));
    A(i,1) = 1;
    A(i,2) = -t(point(i));
end

theta_hat = inv(A'*A)*(A')*Y;
e_hat = Y-A*theta_hat;
v0 = exp(theta_hat(1))
lambda = theta_hat(2)


vt = v0 * exp( -1*lambda*t );
hold on;
plot(t,vt,'g')

[theda,Yh,E,E_std,theda_std,theda_cov,E_corrcoef] = lse_std(Y,A);
