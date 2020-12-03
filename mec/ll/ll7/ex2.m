x0 = 0;
y0 = 0;
z0 = 0;
v0x = 0;
v0y = 0.5;
v0z = 2;
u0 = [x0, y0, z0, v0x, v0y, v0z];
tmin = 0;
tmax = 10;
t = [tmin, tmax];
[t, u] = ode45('fn2', t, u0);
figure(1);
x = u(:,1);
y = u(:,2);
z = u(:,3);
plot(t, x, t, y, t, z);
grid on;
title('Graficul dependentelor x=x(t), y=y(t), z=z(t)');
xlabel('t');
ylabel('pozitia');
figure(2);
plot3(x, y, z);
hold on;
quiver3(x0, y0, z0, v0x*3, v0y*3, v0z*3, '-r');
