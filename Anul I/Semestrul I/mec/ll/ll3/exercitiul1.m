x = 0:0.05:1;
f = ex1(x);
plot(x,f,"ko-");
grid on
title("Exercitiul 1 folosind comanda fplot");
xlabel("Axa X");
ylabel("Axa Y");
legend("f(x)=2 * sin(7 * π * |x-1/3|* x^2)");
line([0 0], ylim);
line(xlim, [0 0]);
%fplot(@ex1,[0,1])