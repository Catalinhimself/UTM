x = [-1:0.05:3];
f = (x.^2).*sin(x).^2;
g = x.*cos(x);
%soimplu

plot(x,f,'k.-')
title('Functia f(x)')
legend('(x^2)*sin(x)^2')
xlabel('Axa X')
ylabel('Axa Y')
plot(x,g,'r*-')
title('Functia g(x)')
legend('x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')

plot(x,f,'b.-',x,g,'g.-')
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')
%pe acelasi desen
subplot(3,1,1); plot(x,f)
title('Functia f(x)')
legend('(x^2)*sin(x)^2')
xlabel('Axa X')
ylabel('Axa Y')
subplot(3,1,2); plot(x,g)
title('Functia g(x)')
legend('x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')
subplot(3,1,3); plot(x,f,x,g)
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')


subplot(1,3,1); plot(x,f)
title('Functia f(x)')
legend('(x^2)*sin(x)^2')
xlabel('Axa X')
ylabel('Axa Y')
subplot(1,3,2); plot(x,g)
title('Functia g(x)')
legend('x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')
subplot(1,3,3); plot(x,f,x,g)
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')


subplot(2,2,1); plot(x,f)
title('Functia f(x)')
legend('(x^2)*sin(x)^2')
xlabel('Axa X')
ylabel('Axa Y')
subplot(2,2,3); plot(x,g)
title('Functia g(x)')
legend('x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')
subplot(2,2,[2 4]); plot(x,f,x,g)
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')

subplot(1,3,3); plot(x,f,x,g)
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')

subplot(2,2,3); plot(x,f)
title('Functia f(x)')
legend('(x^2)*sin(x)^2')
xlabel('Axa X')
ylabel('Axa Y')
subplot(2,2,4); plot(x,g)
title('Functia g(x)')
legend('x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')
subplot(2,2,[1 2]); plot(x,f,x,g)
title('Functiile f(x) si g(x)')
legend('(x^2)*sin(x)^2','x*cos(x)')
xlabel('Axa X')
ylabel('Axa Y')

%3
[x,y]=meshgrid(0:0.1:1,-2:0.1:2)
 z = (exp(x).*(cos(x.*y)+x.*y))
 %mesh
 mesh(x,y,z)
 title('Graficul functiei de 2 variabile')
xlabel('Axa X')
ylabel('Axa Y')
zlabel('Axa Z')

meshc(x,y,z)
 title('Graficul functiei de 2 variabile')
xlabel('Axa X')
ylabel('Axa Y')
zlabel('Axa Z')

surfc(x,y,z)
 title('Graficul functiei de 2 variabile')
xlabel('Axa X')
ylabel('Axa Y')
zlabel('Axa Z')

contour3(x,y,z)
 title('conturul graficului functiei de 2 variabile')
xlabel('Axa X')
ylabel('Axa Y')
zlabel('Axa Z')