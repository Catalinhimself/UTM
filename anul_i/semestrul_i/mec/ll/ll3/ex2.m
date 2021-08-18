t = 0:0.05:2*pi;
[x,y] = xy(t);
plot(x,y)
%comet(x,y)
hold on
%Determinam timpul de calcul si pozitia punctului
t=1%2*pi*rand
[x,y]=xy(t);
%Construim pozitia punctului pe traiectorie
plot(x,y,'ro-')