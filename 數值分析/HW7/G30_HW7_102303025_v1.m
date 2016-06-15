clear; clc;
fprintf('(a)\n')
figure(1);
t=0:0.001:2;
ya=exp((1/4)*t.^4-1.5*t);
plot(t,ya);
fprintf('(b)歐拉法\n')
figure(2);

h(1)=0.5;   h(2)=0.25;
for i=1:2
    subplot(2,1,i)
    fprintf('當步長大小為%f\n',h(i))
    y0=1;
    ti=0;   tf=2;
    t=(ti:h(i):tf)';
    n=length(t);
    if(t(n)<tf)
        t(n+1)=tf
        n=n+1;
    end
    y=y0*ones(n,1);
    for i=1:n-1
        y(i+1)=y(i)+(y(i)*t(i)^3-1.5*y(i))*(t(i+1)-t(i));
    end
    disp([t,y])
    plot(t,y)
end

fprintf('(c)中點法\n')
figure(3);
y0=1;
h=0.5;
ti=0;   tf=2;
t=(ti:h:tf)';
n=length(t);
if(t(n)<tf)
    t(n+1)=tf
    n=n+1;
end
y=y0*ones(n,1);
for i=1:n-1
    y(i+1)=y(i)+(y(i)*t(i)^3-1.5*y(i))*(t(i+1)-t(i));
end
for i=1:n-1
    yh(i)=y(i)+(y(i)*t(i)^3-1.5*y(i))*(t(i+1)-t(i))/2;
    th(i)=(t(i)+t(i+1))/2;
end
for i=1:n-1
    y(i+1)=y(i)+(yh(i)*th(i)^3-1.5*yh(i))*(t(i+1)-t(i))/2;
end
disp([t,y])
plot(t,y)

fprintf('(d)4分RK法\n')
figure(4);
yy(1)=1;
h=0.5;
ti=0;   tf=2;
t=(ti:h:tf);
for i=1:4
k1=yhtf(t(i),yy(i));
k2=yhtf(t(i)+h/2,yy(i)+k1*h/2);
k3=yhtf(t(i)+h/2,yy(i)+k2*h/2);
k4=yhtf(t(i)+h,yy(i)+k3*h);
phih=(k1+2*k2+2*k3+k4)/6;
yy(i+1)=yy(i)+phih*h;
end
yy
plot(t,yy)