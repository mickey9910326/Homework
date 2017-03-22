clear;clc;
V0 = 30;
Lambda = 0.87;
t  = [0:0.01:20];
dt = 0.01;
n  = randi([0 100],1,length(t)) * dt;

Vt = V0 * exp( -1*Lambda*t ) + n;

plot(t,Vt)

point = [1;100;20;130;120;140;150;200];

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