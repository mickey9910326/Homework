%% ANS
% T_0_6_a =
% 
%     1.0000         0         0  817.0000
%          0         0   -1.0000 -109.3000
%          0    1.0000         0   94.7500
%          0         0         0    1.0000
% 
% for theta = [0 0 0 0 0 0]
% 
% T_0_6_b =
% 
%    -0.9194   -0.3772    0.1116  567.1160
%     0.2268   -0.7402   -0.6330  -10.9883
%     0.3214   -0.5567    0.7660  445.6480
%          0         0         0    1.0000
% 
% for theta = [10 20 30 40 50 60]
%% �e�m�@�~
clear;clc;
% syms a1 a2 a3 a4 a5 a6
syms f1 f2 f3 f4 f5 f6
syms d1 d2 d3 d4 d5 d6
syms t1 t2 t3 t4 t5 t6
a = sym('a',[1 6]);
% a =[ a1 a2 a3 a4 a5 a6];
f =[ f1 f2 f3 f4 f5 f6];
d =[ d1 d2 d3 d4 d5 d6];
t =[ t1 t2 t3 t4 t5 t6];
a = sym(a);
f = sym(f);
d = sym(d);
t = sym(t);

for i=1:6
    % T_(i-1)_(i)  =  T(:,:,i)
    T(1,1,i) =  cos( t(i) );
    T(1,2,i) = -sin( t(i) );
    T(1,3,i) =  0;
    T(1,4,i) =  a(i);
    T(2,1,i) =  sin( t(i) )*cos( f(i) );
    T(2,2,i) =  cos( t(i) )*cos( f(i) );
    T(2,3,i) = -sin( f(i) );
    T(2,4,i) = -sin( f(i) )*d(i);
    T(3,1,i) =  sin( t(i) )*sin( f(i) );
    T(3,2,i) =  cos( t(i) )*sin( f(i) );
    T(3,3,i) =  cos( f(i) );
    T(3,4,i) =  cos( f(i) )*d(i);
    T(4,1,i) = 0;
    T(4,2,i) = 0;
    T(4,3,i) = 0;
    T(4,4,i) = 1;
end
P_6 =  eye(4);

T_0_6 = T(:,:,1)*T(:,:,2)*T(:,:,3)*T(:,:,4)*T(:,:,5)*T(:,:,6);

P_0 = T_0_6 * P_6 ;

% P_6 is the position and orientation of the tool frame relative to the frame 6
% P_0 is the position and orientation of the tool frame relative to the frame 0. 

% simplify(P_0)

syms r11 r12 r13 r21 r22 r23 r31 r32 r33
syms p1  p2  p3
r =[ r11 r12 r13 ; r21 r22 r23 ; r31 r32 r33 ];
p =[ p1 ; p2 ; p3 ];
r= sym(r);
p= sym(p);

ANS_T_0_6 = [ r(1,1) r(1,2) r(1,3) p(1);
              r(2,1) r(2,2) r(2,3) p(2);
              r(3,1) r(3,2) r(3,3) p(3);
              0      0      0      1   ;];


ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6;

T_1_6 = T(:,:,2)*T(:,:,3)*T(:,:,4)*T(:,:,5)*T(:,:,6);

a = [0 0 425 392 0];
f = [0 pi/2 0 0 -pi/2 pi/2];
d = [0 0 0 109.3 94.75 0];

a1 = 0;
a2 = 0;
a3 = 425;
a4 = 392;
a5 = 0;
a6 = 0;

f1 = 0;
f2 = pi/2;
f3 = 0;
f4 = 0;
f5 = -pi/2;
f6 = pi/2;

d1 = 0;
d2 = 0;
d3 = 0;
d4 = 109.3;
d5 = 94.75;
d6 = 0;

% p1 = 567.1160;
% p2 = -10.9883;

%% 
fprintf('## \n')
fprintf('�Q�ΤU�C��x�}�۵��A�D�Xt1,t5,t6\n')

T = subs(T);
ANS_T_0_6 = subs(ANS_T_0_6);
ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6
T_1_6     = T(:,:,2)*T(:,:,3)*T(:,:,4)*T(:,:,5)*T(:,:,6)

ANS_T_2_6 = inv(T(:,:,2))*ANS_T_1_6;
ANS_T_3_6 = inv(T(:,:,3))*ANS_T_2_6;
ANS_T_4_6 = inv(T(:,:,4))*ANS_T_3_6;
ANS_T_5_6 = inv(T(:,:,5))*ANS_T_4_6;

T_2_6     = T(:,:,3)*T(:,:,4)*T(:,:,5)*T(:,:,6);
T_3_6     = T(:,:,4)*T(:,:,5)*T(:,:,6);
T_4_6     = T(:,:,5)*T(:,:,6);
T_5_6     = T(:,:,6);
%% �D t1
%�� (2,4) �D�Xt1�G
fprintf('## �Dt1\n')
fprintf('�ϥ� (2,4) �D�Xt1\n')
fprintf('���� %s == %s \n',char( T_1_6(2,4) ),char( ANS_T_1_6(2,4) ));

eq1 = eq(ANS_T_1_6(2,4),T_1_6(2,4));
ans_t1 = solve( eq1 , t1);
ans_t1 = simplify(ans_t1);
ans_t1
% �o��ո�
% �A�ӭn�[��x�}�����Y�A�D�Xt2,t3,t4,t5

%% �D t5
%�̧Ǳa�Jt1�A�å� (2,3) �D�Xt5�G
fprintf('## �Dt5\n')
fprintf('�̧Ǳa�Jt1�A�èϥ� (2,3) �A���O�o����t5\n')
fprintf('���� %s == %s \n',char( T_1_6(2,3) ),char( ANS_T_1_6(2,3) ));

t1 = ans_t1(1);
tANS_T_1_6 = subs(ANS_T_1_6);
tT_1_6 = subs(T_1_6);

eq5 = eq(tANS_T_1_6(2,3),tT_1_6(2,3));
ans_t5 = solve( eq5 , t5);

t1 = ans_t1(2);
tANS_T_1_6 = subs(ANS_T_1_6);
tT_1_6 = subs(T_1_6);

eq5 = eq(tANS_T_1_6(2,3),tT_1_6(2,3));
ans_t5(3:4) = solve( eq5 , t5);
%
ans_t5 = simplify(ans_t5);
ans_t5
% �o4��t5
% �o�{

%% �D t6
% �̧Ǳa�Jt1�A�å� (2,1)/(2,2) �D�Xt6�G
% -cos(t6)/sin(t6) = xxxxx
% �C��t1�����@�Ӱߤ@��
fprintf('## �Dt6\n');
fprintf('�̧Ǳa�Jt1�A�å� (2,1)/(2,2) �D�Xt6\n');
fprintf('(2,1) :%s\n',char( T_1_6(2,1) ));
fprintf('(2,2) :%s\n',char( T_1_6(2,2) ));
fprintf('�۰� %s == %s \n',char( T_1_6(2,1)/T_1_6(2,2) ),char( ANS_T_1_6(2,1)/ANS_T_1_6(2,2) ));

fprintf('\n�o�{��t1�ұot6�۵��A�o�ߤ@t6\n');

t1 = ans_t1(1);

tANS_T_1_6 = subs(ANS_T_1_6);
tT_1_6 = subs(T_1_6);

eq6 = eq( tANS_T_1_6(2,1) / tANS_T_1_6(2,2) , tT_1_6(2,1) / tT_1_6(2,2) );
ans_t6 = solve( eq6 , t6);

t1 = ans_t1(2);

tANS_T_1_6 = subs(ANS_T_1_6);
tT_1_6 = subs(T_1_6);

eq6 = eq( tANS_T_1_6(2,1) / tANS_T_1_6(2,2) , tT_1_6(2,1) / tT_1_6(2,2) );
ans_t6(2,1) = solve( eq6 , t6);
ans_t6 = simplify(ans_t6);
ans_t6

% �o�{��t1�ұot6�۵��A�o�ߤ@t6
%% t2 |
% �a���󵥨Ƴ��o�L�N�q(NaN)
t1 = ans_t1(1);
t5 = ans_t5(1);
t6 = ans_t6(1);
tANS_T_3_6 = subs(ANS_T_3_6);
tT_3_6 = subs(T_3_6);

eq2 = eq(ANS_T_3_6(3,3),tT_3_6(3,3));
ans_t2 = solve( eq2 , t2)
ans_t2 = simplify(ans_t2);
ans_t2


%% �a�J����1
% T_0_6_a =
% 
%     1.0000         0         0  817.0000
%          0         0   -1.0000 -109.3000
%          0    1.0000         0   94.7500
%          0         0         0    1.0000
% 
% for theta = [0 0 0 0 0 0]
fprintf('## �a�J���� theta = [0 0 0 0 0 0] \n');

r11 = 1;
r12 = 0;
r13 = 0;
r21 = 0;
r22 = 0;
r23 = -1;
r31 = 0;
r32 = 1;
r33 = 0;
p1  = 817;
p2  = 109.3;
p3  = 94.75;

T1 = double(subs(ans_t1))*180/pi
T5 = double(subs(ans_t5))*180/pi
% T6 = double(subs(ans_t6))*180/pi
% T6 �a�J�o�Ϳ��~ Division by zero

%% �a�J����2
% T_0_6_b =
% 
%    -0.9194   -0.3772   -0.3772  567.1160
%     0.2268   -0.7402   -0.6330  -10.9883
%     0.3214   -0.5567    0.7660  445.6480
%          0         0         0    1.0000
% 
% for theta = [10 20 30 40 50 60]
fprintf('## �a�J���� theta = [10 20 30 40 50 60]\n');

r11 = -0.9194;
r12 = -0.3772;
r13 = -0.3772;
r21 =  0.2268;
r22 = -0.7402;
r23 = -0.6330;
r31 =  0.3214;
r32 = -0.5567;
r33 =  0.7660;
p1  = 567.1160;
p2  = -10.9883;
p3  = 445.6480;

T1 = double(subs(ans_t1))*180/pi
T5 = double(subs(ans_t5))*180/pi
T6 = double(subs(ans_t6))*180/pi