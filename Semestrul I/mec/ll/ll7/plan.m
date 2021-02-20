v0 = 3;
alpha = pi/4;
x0 = 0;
y0 = 0;
v0x = v0*cos(alpha);
v0y = v0*sin(alpha);
u0=[x0,y0,v0x,v0y];
tmin=0; tmax=10; 
t=[tmin,tmax];
[t,u]=ode45('fun',t,u0);
figure(1); 
x= u(:,1);
y=u(:,2);
vy=u(:,3);
vx= u(:,4);
plot(t,x,t,y);
grid on; 
xlabel('t,sec');
ylabel('x,m'); 
title('Graficul x=x(t), y=y(t)'); 
figure(2);
v=sqrt(vx.^2+vy.^2);
plot(t,vx,t,vy,t,v);
grid on; 
xlabel('x,m');
ylabel('y,m'); 
title('Graficul dependentelor vx(t), vy(t), v(t)'); 
figure(3);
plot(x,y);
grid on;
hold on;
quiver(x0,y0,v0x,v0y,['-r','-k']);
title('traiectoria punctului material');