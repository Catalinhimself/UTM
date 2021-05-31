t=fzero('myfunction',pi/2);
t1 = t
a = 25;
syms t
fi =18*sin(2*pi*t);
W = diff(fi);
t=t1;
W = 36*pi*cos(2*pi*t)
O1O=sqrt(a^2+(2*a)^2);
V=W*O1O
syms t;
w = 36*pi*cos(2*pi*t);
E=diff(w)
t=t1;
E = -72*pi^2*sin(2*pi*t)
a_ax = W^2 *O1O
a_rot = E * O1O
a = sqrt (a_ax^2+a_rot^2)