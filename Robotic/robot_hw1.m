clear all
a=[0,0,0,0,0,0];
b=[0,20,30,40,50,60];
b=b*pi/180;

EX(1,:) = [0,      0,    0.089];
EX(2,:) = [-0.425, pi/2, 0    ];
EX(3,:) = [-0.392, 0,    0    ];
EX(4,:) = [0,      0,    0.109];
EX(5,:) = [0,      pi/2, 0.095];
EX(6,:) = [0,     -pi/2, 0.082];

EX_a = EX;
EX_b = EX;
EX_a(:,4) = a;
EX_b(:,4) = b;

for i=1:6    
    F_a(1,1,i)=cos(EX_a(i,4));
    F_a(1,2,i)=-sin(EX_a(i,4));
    F_a(1,3,i)=0;
    F_a(1,4,i)=EX_a(i,1);
    F_a(2,1,i)=cos(EX_a(i,2))*sin(EX_a(i,4));
    F_a(2,2,i)=cos(EX_a(i,2))*cos(EX_a(i,4));
    F_a(2,3,i)=-sin(EX_a(i,2));
    F_a(2,4,i)=-sin(EX_a(i,2))*EX_a(i,3);
    F_a(3,1,i)=sin(EX_a(i,4))*sin(EX_a(i,2));
    F_a(3,2,i)=cos(EX_a(i,4))*sin(EX_a(i,2));
    F_a(3,3,i)=cos(EX_a(i,2));
    F_a(3,4,i)=cos(EX_a(i,2))*EX_a(i,3);
    F_a(4,1,i)=0;
    F_a(4,2,i)=0;
    F_a(4,3,i)=0;
    F_a(4,4,i)=1;
end

E_a = F_a(:,:,1)*F_a(:,:,2)*F_a(:,:,3)*F_a(:,:,4)*F_a(:,:,5)*F_a(:,:,6)

for i=1:6    
    F_b(1,1,i)=cos(EX_b(i,4));
    F_b(1,2,i)=-sin(EX_b(i,4));
    F_b(1,3,i)=0;
    F_b(1,4,i)=EX_b(i,1);
    F_b(2,1,i)=cos(EX_b(i,2))*sin(EX_b(i,4));
    F_b(2,2,i)=cos(EX_b(i,2))*cos(EX_b(i,4));
    F_b(2,3,i)=-sin(EX_b(i,2));
    F_b(2,4,i)=-sin(EX_b(i,2))*EX_b(i,3);
    F_b(3,1,i)=sin(EX_b(i,4))*sin(EX_b(i,2));
    F_b(3,2,i)=cos(EX_b(i,4))*sin(EX_b(i,2));
    F_b(3,3,i)=cos(EX_b(i,2));
    F_b(3,4,i)=cos(EX_b(i,2))*EX_b(i,3);
    F_b(4,1,i)=0;
    F_b(4,2,i)=0;
    F_b(4,3,i)=0;
    F_b(4,4,i)=1;
end

E_b = F_b(:,:,1)*F_b(:,:,2)*F_b(:,:,3)*F_b(:,:,4)*F_b(:,:,5)*F_b(:,:,6)

