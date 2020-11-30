function [v1,v2,v3]=b2 (t)
x1=2.5;
x2=1.2;
omega1=2;
omega2=2;
alfa1=1;
alfa2=1.1;
v1=x1*cos(omega1*t+alfa1);
v2=x2*cos(omega2*t+alfa2);
v3=v1+v2;
end