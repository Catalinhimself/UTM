function [x,y] = b3(fig,alfa)
t=[0:pi/250:13];
xx=2;
xy=3;
omega1=3;
omega2=6;
alfa1=5;
alfa2=alfa1 - alfa;
y=xx*cos(omega1*t+alfa1);
x=xy*cos(omega2*t+alfa2);
figure(fig);
end

