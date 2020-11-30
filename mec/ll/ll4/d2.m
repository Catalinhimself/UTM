function [v1,v2,v3]=d2(nr,alfa);
t=(0:pi/120:15);
x1=4;
x2=5;
omega1=3;
omega2=omega1;
alfa1=10;
alfa2=alfa1-alfa;
v1=x1*cos(omega1*t+alfa1);
v2=x2*cos(omega2*t+alfa2);
v3=v1+v2;
figure(nr);
plot(t,v1,'m',t,v2,'b',t,v3,'k-.','linewidth',1);
legend('x1t','x2t','xt');
title('Oscilatii armonice coerente'); xlabel('t,sec');
ylabel('v,m');
end