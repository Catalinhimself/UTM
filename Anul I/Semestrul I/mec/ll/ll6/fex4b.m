function dxdt = fex4b(t,x)
h=10;
w0=5;
dxdt = zeros(2,1);    
dxdt(1) = x(2);
dxdt(2) = -2.*h.*x(2)-w0.^2*x(1); 
end