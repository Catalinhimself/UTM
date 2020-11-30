[t,x]=ode45(@fex4d,[0 10],[0;2]);
plot(t,x(:,1),'-');
grid on

h=5; w0=14; H0=8;
p=[0:0.1:3*w0];
A=H0./sqrt((w0.^2-p.^2)+4.*h.^2*p.^2);
plot(p,A)
grid on

gamma=atan(2.*h.*p)./(w0.^2-p.^2);
plot(p,gamma)
grid on