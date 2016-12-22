%% Jacobians: Velocities and Static Forces
% Get a linear velocity to describe a linear motion of a point.
% date:2016/12/22 
%%
clear all
clc
%% Define T and get R and P
syms z4 dtheta1 dtheta2 dtheta3 

% T(i) = T_(i-1)_i
T(1:4,1:4,1:4) = sym(0);

T(:,:,1) = [ cosd(30) -sind(30) 0 0 ;
             sind(30)  cosd(30) 0 0 ;
             0 0 1 60;
             0 0 0 1 ;];
T(:,:,2) = [ cosd(30) -sind(30) 0 30;
             sind(30)  cosd(30) 0 0 ;
             0 0 1 0 ;
             0 0 0 1 ;];
T(:,:,3) = [ cosd(30) -sind(30) 0 30;
             sind(30)  cosd(30) 0 0 ;
             0 0 1 0;
             0 0 0 1 ;];
T(:,:,4) = [ cosd(0) -sind(0) 0 0 ;
             sind(0)  cosd(0) 0 0 ;
             0 0 1 -40+z4;
             0 0 0 1 ;];

R(1:3,1:3,1:4) = sym(0);
P(1:3,4) =  sym(0);
for i = 1:4
    R(:,:,i) = T(1:3,1:3,i);
    P(:,i) = T(1:3,4,i);
end

%% Solve W and V

% rotational velocity
% 算出每個點相對原點的轉動速度
% W(i) = W_(i-1)_(i-1)
W(1:3,4) = sym(0);

W(:,2) = R(:,:,1)*W(:,1) + dtheta1 * [ 0 ; 0 ; 1 ];
W(:,3) = R(:,:,2)*W(:,2) + dtheta2 * [ 0 ; 0 ; 1 ];
W(:,4) = R(:,:,3)*W(:,3) + dtheta3 * [ 0 ; 0 ; 1 ];

% linear velocity
% 算出每個點相對原點的線性速度
% V(i) = V_(i-1)_(i-1)
V(1:3,5) = sym(0);

V(:,2) = R(:,:,1)*( V(:,1) + cross(W(:,1),P(:,1)) );
V(:,3) = R(:,:,2)*( V(:,2) + cross(W(:,2),P(:,2)) );
V(:,4) = R(:,:,3)*( V(:,3) + cross(W(:,3),P(:,3)) );
V(:,5) = R(:,:,4)*( V(:,4) + cross(W(:,4),P(:,4)) );

% Vp P點速度狀態
Vp = [10;0;0];

for i = 1:3
    EQU(i) = eq( V(i,5) , Vp(i) );
end
s = solve(EQU(1),EQU(2));
%% Outcome

dtheta1 = vpa(s.dtheta1)
dtheta2 = vpa(s.dtheta2)

W1 = subs(W(:,2))
W2 = subs(W(:,3))

fprintf('W3不影響P點速度，位置')

V4 = vpa(subs(V(:,5)))

