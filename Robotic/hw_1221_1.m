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
             0 0 1 -40;
             0 0 0 1 ;];

R(1:3,1:3,1:4) = sym(0);
P(1:3,4) =  sym(0);
for i = 1:4
    R(:,:,i) = T(1:3,1:3,i);
    P(:,i) = T(1:3,4,i);
end

%% Solve f (force) and n
fz4  = 2;
nz4  = 1;
f(:,4) = [0;0;-fz4];
f(:,3) = R(:,:,4)*f(:,4);
f(:,2) = R(:,:,3)*f(:,3);
f(:,1) = R(:,:,2)*f(:,2);

n(:,4) = [0;0;nz4];
n(:,3) = R(:,:,4)*n(:,4) + cross(P(:,4),f(:,3));
n(:,2) = R(:,:,3)*n(:,3) + cross(P(:,3),f(:,2));
n(:,1) = R(:,:,2)*n(:,2) + cross(P(:,2),f(:,1));
%% Outcome
n
f1 = f(:,1)
f2 = f(:,2)
f3 = f(:,3)
f4 = f(:,4)

z1 = n(3,1)
z2 = n(3,2)
z3 = n(3,3)
z4 = n(3,4)
