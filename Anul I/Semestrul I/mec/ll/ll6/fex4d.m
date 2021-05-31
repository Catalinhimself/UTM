function dxdt = fex4d(t,x)
h=2;
w0=14;
H0=8;
p=25;
dxdt = zeros(2,1);    
dxdt(1) = x(2);
dxdt(2) = -2.*h.*x(2)-w0.^2.*x(1)+H0.*sin(p*t);
end