clear all
%%
% w : rotation speeds of the propellers
% T : forces generated by the propellers

% ω1, ω2, ω3, ω4: rotation speeds of the propellers
% T1, T2, T3, T4: forces generated by the propellers
% Ti ? (ωi)^2 : on the basis of propeller shape, air density, etc.
% m: mass of the quadrotor
% mg: weight of the quadrotor Corrado

% M1,M2,M3,M4: moments generated by the forces
% Mi = L × Ti

% Equilibrium of forces: P(i=1~4)Ti = ?mg
% Equilibrium of directions: T1,2,3,4||g
% Equilibrium of moments: P(i=1~4)Mi = 0
% 4 Equilibrium of rotation speeds: (ω1 +ω3)?(ω2 +ω4) = 0

%%
% φ phi (Roll): angle of rotation along axis xB||xE
% θ theta (Pitch) : angle of rotation along axis yB||yE
% ψ psi (Yaw): angle of rotation along axis zB||zE

%%
%  parameter
g = 9.81;
m = 2.00;
L = 0.25;
Ix = 0.00485;
Iy = 0.00485;
Iz = 0.00881;
d = 1.12*10^(-7);
b = 3.10*10^(-7);
Ir = 0.000000000000001;

% initial condition
F = m*g*(cosd(30))^(-1);
r=0.5;

a(1:3,1) = 0;
v(1:3,1) = [0;0;0];
p(1:3,1) = [0;0;10];

phi(1) = 0;
theta(1) = 0;
psi(1) =  0;

dphi(1) = 0;
dtheta(1) = 0;
dpsi(1) = 0;

ddphi(1) = 0;
ddtheta(1) = 0;
ddpsi(1) = 0;

% controllable parameter
u1 = m*g; % 總升力 = b(w1^2 + w2^2 + w3^2 + w4^2)
u2 = 0; % 俯仰力矩 = b(w1^2 + w2^2 - w3^2 + w4^2) x軸 前後
u3 = 0; % 翻轉力矩 = b(w1^2 - w2^2 + W3^2 - w4^2) y軸 左右
u4 = 0; % 偏航力矩 = d(w1^2 - w2^2 + W3^2 - w4^2) z軸 改變方向 (+-為旋翼旋轉方向)

% １　２
% 　Ｘ
% ３　４


dt = 0.1; % 單位時間間隔(s)
Time = 100; % 總時間(s)
t = 0:dt:Time;
for i = 1:1:length(t)
    %% 計算姿態、位置
    dphi(i+1) = dphi(i) + ddphi(i)*dt;
    dtheta(i+1) = dtheta(i) + ddphi(i)*dt;
    dpsi(i+1) = dpsi(i) + ddpsi(i)*dt;

    phi(i+1) = phi(i) + dphi(i)*dt;
    theta(i+1) = theta(i) + dphi(i)*dt;
    psi(i+1) = psi(i) + dpsi(i)*dt;

    ddphi(i+1) = dtheta(i)*dpsi(i)*(Iy-Iz)/Ix  + L/Ix*u2;
    ddtheta(i+1) = dphi(i)*dpsi(i)*(Iz-Ix)/Iy  + L/Iy*u3;
    ddpsi(i+1) = dphi(i)*dtheta(i)*(Ix-Iy)/Iz  + 1/Iz*u4;

    a(1,i+1) = -( cos(phi(i))*sin(theta(i))*cos(psi(i)) + sin(phi(i))*sin(psi(i)) ) *u1/m;
     a(3,i+1) = (cos(phi(i))*cos(theta(i))) *u1/m - g;

    v(1:3,i+1) = v(1:3,i) + a(1:3,i)*dt;
    p(1:3,i+1) = p(1:3,i) + v(1:3,i)*dt;
    
    %%
    dphi(i+1) = pi*sin(i/10);
    dtheta(i+1) = pi*cos(i/10);
    dpsi(i+1) = 0;
end
t(length(t)+1) = Time+dt;

figure(1)
subplot(3,1,1);
plot(t,p(1,:))
title('px-t');
xlabel('t(s)')
ylabel('px(m)')

subplot(3,1,2);
plot(t,p(2,:))
title('py-t');
xlabel('t(s)')
ylabel('py(m)')

subplot(3,1,3);
plot(t,p(3,:))
title('px-t');
xlabel('t(s)')
ylabel('pz(m)')

figure(2)
subplot(3,1,1);
plot(t,theta)
title('theta-t');
xlabel('t(s)')
ylabel('theta)')

subplot(3,1,2);
plot(t,phi)
title('phi-t');
xlabel('t(s)')
ylabel('phi')

subplot(3,1,3);
plot(t,psi)
title('psi-t');
xlabel('t(s)')
ylabel('psi')


%% 
% PID
% tp = [0;0;10];
% ep;
% for  i = 1:1:100
%     ep  = tp - p(1:3,i);
%     u1 = 