function [x,y,z] = figpas2(fig,pas)
start = 0;
sfarsit = pi;
t = start:pas:sfarsit;
[x,y,z]=xyz(t);
figure(fig)
clf
plot3(x,y,z);
%comet3(x,y,z);
hold on
grid on 
%t=sfarsit*rand;
t=1;
[x,y,z]=xyz(t);
plot3(x,y,z,"ro:");
title(['t =  ',num2str(t)]);
xlabel('Axa-Ox')
ylabel('Axa-Oy')
zlabel('Axa-Oz')
end

