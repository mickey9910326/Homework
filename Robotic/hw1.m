%---- prove
syms a alpha d theta

Rx = [1 0 0 0 
      0 cos(alpha) -sin(alpha) 0
      0 sin(alpha) cos(alpha)  0
      0 0 0 1];
Dx = [1 0 0 a
      0 1 0 0
      0 0 1 0
      0 0 0 1];
Rz = [cos(theta) -sin(theta) 0 0
      sin(theta) cos(theta)  0 0
      0 0 1 0
      0 0 0 1];
Dz = [1 0 0 0
      0 1 0 0 
      0 0 1 d
      0 0 0 1];
Rx
Dx
Rz
Dz
fprintf('Ti = Rx*Dx*Rz*Dz\n');
Ti = Rx*Dx*Rz*Dz
fprintf('The above 4x4 matrix is the general form of the transformation matrix between two sequential revolute joint.\n');

%---- [0 0 0 0 0 0]
a_im1     = [0     0. 425 0.392 0 0   0    ];
alpha_im1 = [90    0  0   -90   90    0    ];
d_i       = [0.089 0  0   0.109 0.095 0.082];
theta_i   = [0     0  0   0     0     0   ];
alpha_im1 = alpha_im1 *pi/180;
theta_i   = theta_i *pi/180;

for i=1:6
    a = a_im1(i);
    alpha = alpha_im1(i);
    d = d_i(i);
    theta = theta_i(i);
    T_a(:,:,i) = subs(Ti);
end
T_0_6_a = double( T_a(:,:,1)*T_a(:,:,2)*T_a(:,:,3)*T_a(:,:,4)*T_a(:,:,5)*T_a(:,:,6) )
fprintf('for theta = [0 0 0 0 0 0]\n');

%---- [0 20 30 40 50 60]
a_im1     = [0     0. 425 0.392 0 0   0    ];
alpha_im1 = [90    0  0   -90   90    0    ];
d_i       = [0.089 0  0   0.109 0.095 0.082];
theta_i   = [0     20 30  40    50    60   ];
alpha_im1 = alpha_im1 *pi/180;
theta_i   = theta_i *pi/180;

for i=1:6
    a = a_im1(i);
    alpha = alpha_im1(i);
    d = d_i(i);
    theta = theta_i(i);
    T_b(:,:,i) = subs(Ti);
end
T_0_6_b = double( T_b(:,:,1)*T_b(:,:,2)*T_b(:,:,3)*T_b(:,:,4)*T_b(:,:,5)*T_b(:,:,6) )
fprintf('for theta = [0 20 30 40 50 60]\n');
