    t1 = 1/6 % sec
    AB = 42 %cn
    syms t;
    s = 42*cos(2*pi*t);
    %a
    xa =0;
    ya = sqrt(AB^2-s^2); % pitagora
    vxa = 0;
    vya = diff(ya);
    t = t1;
    vya = (84*pi*cos(2*pi*t)*sin(2*pi*t))/(1 - cos(2*t*pi)^2)^(1/2)
    va = sqrt(vxa^2 + vya^2)
    %b
    xb= s;
    yb = 0;
    syms t;
    vxb = diff(xb);
    vyb = 0;
    t=t1;
    vxb =-84*pi*sin(2*pi*t)
    vb = sqrt(vxb^2+vyb^2)
    %m
    OB = s;
    AM = 14
    xm = OB/AB*AM % cel mai probabil cos
    vxm = diff(xm);
    t=t1;
    vxm =-28*pi*sin(2*pi*t)
    syms t
    xm = OB/AB*AM;
    ym = sqrt(AM^2-xm^2)
    vym=diff(ym);
    t=t1;
    vym =(28*pi*cos(2*pi*t)*sin(2*pi*t))/(1 - cos(2*t*pi)^2)^(1/2)
    vm = sqrt(vxm^2+vym^2)
