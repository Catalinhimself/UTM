% Viteza 
format long;
syms t;
x = exp(t).*sin(2. *t);
vx = diff(x);
t = 1;
vx = 2*cos(2*t)*exp(t) + sin(2*t)*exp(t);

syms t;
y = t.*(1+cos(t));
vy = diff(y);
t = 1;
vy = cos(t) - t*sin(t) + 1;

syms t;
z = 1.3.*t.^(1/2);
vz = diff(z);
t = 1;
vz =13/(20*t^(1/2));

v =((vx^2) +( vy^2)+( vz^2))^(1/2) 
% Acceleratia

syms t;
vx = 2*cos(2*t)*exp(t) + sin(2*t)*exp(t);
ax = diff(vx);
t = 1;
ax = 4*cos(2*t)*exp(t) - 3*sin(2*t)*exp(t);

syms t;
vy = cos(t) - t*sin(t) + 1;
ay = diff(vy);
t = 1;
ay = 2*sin(t) - t*cos(t);

syms t;
vz =13/(20*t^(1/2));
az = diff(vz);
t = 1;
az = -13/(40*t^(3/2));

a = ((ax^2) +( ay^2))^(1/2)

% Acceleratia tangentiala 
vx = 0.209317904491192;
vy =0.698831321060243;
vz = 0.650000000000000;
ax = -11.939997551041712;
ay = 1.142639663747653;
az =  -0.325000000000000;
at=abs((vx*ax+vy*ay+vz*az))/v

% Acceleratia normala 

at = 3.95685;
a = 11.994547382875746;
an = abs(a-abs(at))

% Raza curburii

p=(v^2)/an