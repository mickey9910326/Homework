clear;clc;
A  = 2;
PHI = 1*pi;
W = 1*pi;
V0 = 30;
Lambda = 0.6;
dt = 0.1;
t  = [0:dt:20];
n  = randi([0 100],1,length(t)) *0.001;

figure(1)
Vt = A * exp( -1*Lambda*t ) .* cos(W*t+PHI) + V0 ;
plot(t,Vt);
hold on;
Vt = A * exp( -1*Lambda*t ) .* cos(W*t+PHI) + V0 +n;
plot(t,Vt,'g');

%% STEP1 ¦ôºâsteady state

% for i=length(t):-1:1
%     
% end
v0 = mean(Vt(length(t):-1:length(t)-20))
%% ¨ú¥X·¥­È

% ex_point(1) = max(Vt)
% for i = 1:6
%     ex_point(i) = max(Vt)

% point = [1;100;20;130;120;140;150;200];
% 
% for i=1:length(point)
%     Y(i,1) = log(Vt(point(i)));
%     A(i,1) = 1;
%     A(i,2) = -t(point(i));
% end
% 
% theta_hat = inv(A'*A)*(A')*Y;
% e_hat = Y-A*theta_hat;
% v0 = exp(theta_hat(1))
% lambda = theta_hat(2)
% 
% 
% vt = v0 * exp( -1*lambda*t );
% hold on;
% plot(t,vt,'g')
% 
% [theda,Yh,E,E_std,theda_std,theda_cov,E_corrcoef] = lse_std(Y,A);