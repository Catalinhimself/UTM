function dxdt = fex4c(t,x)
H0=1;
w0=13;
p=13;
dxdt = zeros(2,1);    
dxdt(1) = x(2);
dxdt(2) = -w0.^2.*x(1)+H0.*sin(p.*t); 
end