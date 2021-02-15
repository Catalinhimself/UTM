n=0;
for alfa= [0,pi/5,pi/3,pi/2,pi/2,5*pi/3,8*pi/5,6*pi/7,pi]
n=n+1;
subplot(3,3,n);
[x,y]=b3(1,alfa);
plot(x,y,'g-','linewidth',1.5);
title(['\delta\alpha=',num2str(alfa),'rad']);
xlabel('t(s)');
ylabel('x(m)');
grid on;
end