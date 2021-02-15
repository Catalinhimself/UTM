[t,x]=ode45(@fex4a,[0 10],[0;2]);
plot(t,x(:,1),'k-');
grid on
%amplituudinea
x0=0;
V0=7;
w0=15;
A=sqrt(x0^2+(V0^2/w0^2))

%perioada
T=2*pi/w0
%faza initiala
eps=atan(w0*x0/V0)
%frecventa
%f1
  f=w0/(2*pi)
%f2
 f=1/T

