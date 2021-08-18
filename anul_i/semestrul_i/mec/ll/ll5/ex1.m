
coef = [2,-1,1,-65*pi/180]
t = roots(coef)
t1=0.7844

syms t
fi = 2*t^3-t^2+t;
W = diff(fi);
t = t1;
W = 6*t^2 - 2*t + 1
a = 25;
OM = a / 4;
O1M = sqrt((2*a)^2+(a-OM)^2)
V = W*O1M

syms t
w = 6*t^2 - 2*t + 1;
E = diff(w);
t = t1;
E = 12*t - 2

a_ax = W^2 *O1M
a_rot = E * O1M
a = sqrt (a_ax^2+a_rot^2)