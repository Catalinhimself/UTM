function dudt=fun(t,u)
m=0.5;
x=u(1);
y=u(2);
xp=u(3);
yp=u(4);
F1x = 2*sin(x);
F1y = 1.5*y;
F2x = 3*cos(x);
F2y = 1.4;

xpp=(F1x+F2x)/m; 
ypp=(F1y+F2y)/m; 
dudt=[xp;yp;xpp;ypp];
end 
 
