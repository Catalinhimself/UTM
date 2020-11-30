function [v1,v2,v3]=c2 (t);
x1=4.9;
x2=6.2;
omega1=3;
omega2=3.1;
alfa1=1;
alfa2=1;
v1=x1*cos(omega1*t+alfa1);
v2=x2*cos(omega2*t+alfa2);
v3=v1+v2;
end