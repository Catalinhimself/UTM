[t,x]=ode45(@fex4b,[-10 10],[0;20]);
plot(t,x(:,1),'r-');
grid on
w0=4;
x0=0;
V0=2;
h=4;
w=sqrt(w0^2-h^2)
%amplitudinea
A=sqrt(x0^2+((V0+h*x0)^2/w^2))
%perioada
T=2*pi/w
%faza initiala
eps=atan((w*x0)/(V0+h*x0))
%frecventa
f=1/T
%decrementul de amortizare
eta=exp(-h*T)
%decrementul logaritmic de amortizare
lambda=h*T