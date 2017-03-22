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
Vt_true = A * exp( -1*Lambda*t ) .* cos(W*t+PHI) + V0 ;
plot(t,Vt_true);
hold on;
Vt = A * exp( -1*Lambda*t ) .* cos(W*t+PHI) + V0 +n;
plot(t,Vt,'g');

%% STEP1 估算steady state

% for i=length(t):-1:1
%     
% end
v0 = mean(Vt(length(t):-1:length(t)-20))
%% 取出極值
% how to get exterme point in Noisy Data

[M,ex_point(1)] = max(Vt);
[M,ex_point(2)] = min(Vt(ex_point(1):length(t)));
ex_point(2) = ex_point(1) + ex_point(2);

i = 3;
[M,ex_point(i)] = max(Vt(ex_point(i-1):length(t)));
ex_point(i) = ex_point(i-1) + ex_point(i);

i = 4;
[M,ex_point(i)] = min(Vt(ex_point(i-1):length(t)));
ex_point(i) = ex_point(i-1) + ex_point(i);

i = 5;
[M,ex_point(i)] = max(Vt(ex_point(i-1):length(t)));
ex_point(i) = ex_point(i-1) + ex_point(i);

%% 取出零點

% 取一開始到極點5之零點
err = 0.05;
ze_point =  find( abs(Vt(1:ex_point(5)) - v0 )< err );

%% 算w
sum = 0;
n = length(ex_point)-1;
for i = 1 : n
    sum = sum + t(ex_point(i+1)) - t(ex_point(i));
end
w = (sum/n)*pi

%% 算 phi
sum = 0;
n = length(ex_point)-1;
for i = 1 : n
    de_angel(i) = t(ex_point(i))*w - sum;
    sum = sum + pi; % cos每180度一次極點，第一次極點為0
end
phi = mean(de_angel)

%% 算 a
% t = 0
a = (Vt(1)-v0) / cos(phi)

%% 
vtt = (Vt-v0)./cos(w*t+phi);


%% LSE
point = ex_point;

for i=1:length(point)-1
    Y(i,1) = log( abs(Vt(point(i))-v0) );
    A(i,1) = 1;
    A(i,2) = -t(point(i));
end

figure(2)
plot(abs(Vt(ex_point)-v0)) 

theta_hat = inv(A'*A)*(A')*Y;
e_hat = Y-A*theta_hat;
a = exp(theta_hat(1))
lambda = theta_hat(2)

figure(3)
plot(t,Vt);
hold on;
plot(t,Vt_true,'r')
hold on;
vt = a * exp( -1*lambda*t ) .* cos(w*t+phi) + v0 ;
plot(t,vt,'g');
