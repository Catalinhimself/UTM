hold on 
grid on 
t1 = 1/6
t =[ 0:0.01:1]
x = 4*cos(2*pi*t)
y = 14*(1 - cos(2*pi*t).^2).^(1/2)
plot(x,y)
t=t1
x = 4*cos(2*pi*t)
y = 14*(1 - cos(2*pi*t).^2).^(1/2)
plot(x,y,'ro-')