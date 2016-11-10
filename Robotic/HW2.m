% syms a1 a2 a3 a4 a5 a6
syms f1 f2 f3 f4 f5 f6
syms d1 d2 d3 d4 d5 d6
syms t1 t2 t3 t4 t5 t6
a = sym('a',[1 6])
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

% a = [0 0 425 392 0];
% f = [0 pi/2 0 0 -pi/2 pi/2];
% d = [0 0 0 109.3 94.75 0];

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


T = subs(T)
ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6;
ANS_T_2_6 = inv(T(:,:,1))*ANS_T_0_6;
ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6;
ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6;
ANS_T_1_6 = inv(T(:,:,1))*ANS_T_0_6;
T_1_6     = T(:,:,2)*T(:,:,3)*T(:,:,4)*T(:,:,5)*T(:,:,6);


ans_t1 = solve( ANS_T_1_6(2,4) == T_1_6(2,4) , t1)

% 再來要觀察矩陣的關係，求出t2,t3,t4,t5

%先帶入t1之一：
t1 = ans_t1(0);
ANS_T_1_6 = subs(ANS_T_1_6);
T_1_6 = subs(T_1_6);


% ans_t1 = solve( [ANS_T_1_6(1,4) == T_1_6(1,4) , ANS_T_1_6(2,4) == T_1_6(2,4) , ANS_T_1_6(3,4) == T_1_6(3,4) ], [t1,t2,t3])
% t1 = 0;
% solve( [ANS_T_1_6(2,4) == T_1_6(2,4) , ANS_T_1_6(1,4) == T_1_6(1,4) , ANS_T_1_6(3,4) == T_1_6(3,4) , ANS_T_1_6(2,3) == T_1_6(1,3) , ANS_T_1_6(3,3) == T_1_6(3,3) ], [t1,t2,t3,t4,t5])

