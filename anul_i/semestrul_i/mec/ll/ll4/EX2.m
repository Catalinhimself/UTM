t=[0:pi/250:13];
[x1t,x2t,xt]=b2(t);
figure(1);
plot(t,x1t,'m',t,x2t,'b',t,xt,'k-.','linewidth',1);
legend('x1t','x2t','xt');
title('Oscilatii armonice coerente');
xlabel('t,sec');
ylabel('x,m');