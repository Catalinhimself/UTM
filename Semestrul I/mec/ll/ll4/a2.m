function [v1,v2,v3]=a2(t)
x1=4;
x2=5;
omega1=7;
omega2=4;
alfa1=0;
alfa2=25;
v1=x1*cos(omega1*t+alfa1);
v2=x2*cos(omega2*t+alfa2);
v3=v1+v2;
end

