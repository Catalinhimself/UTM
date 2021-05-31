function [x,y] = figpas(fig,pas)
start = 0;
sfarsit = 2*pi;
t = start:pas:sfarsit;
[x,y]=xy(t);
figure(fig)
clf
hold on
grid on 
%plot(x,y)
comet(x,y)
t=1;
title(['t =  ',num2str(t)])
[x,y]=xy(t);
plot(x,y,'ro-')
line([0 0], ylim);
line(xlim, [0 0]);
xlabel("Axa X")
ylabel("Axa Y")
end