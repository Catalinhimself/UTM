[t,x]=ode45(@fex4c,[0 10],[0;2]);
plot(t,x(:,1));
grid on

