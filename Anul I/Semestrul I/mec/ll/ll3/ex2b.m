% Viteza 

syms t;
x = 2*cos(t+1);
vx = diff(x);
t = 1;
vx = -2*sin(t + 1)

syms t;
y = 3.*sin(2.*t+t);
vy = diff(y);
t = 1;
vy =9*cos(3*t)
v = ((vx^2) +( vy^2))^(1/2)

% Acceleratia

syms t;
vx = -2*sin(t + 1);
ax = diff(vx);
t = 1;
ax =-2*cos(t + 1)

syms t;
vy =9*cos(3*t);
ay = diff(vy);
t = 1;
ay =-27*sin(3*t)
a = ((ax^2) +( ay^2))^(1/2)

% Acceleratia tangentiala 

 vx =-1.8186;
vy =-8.9099;
v =9.0936;
ax =0.8323;
ay =-3.8102;
 at=abs((vx*ax+vy*ay))/v

% Acceleratia normala 

at = 3.5668;
a = 3.9001;
an = abs(a-abs(at))

% Raza curburii

p=v^2/an