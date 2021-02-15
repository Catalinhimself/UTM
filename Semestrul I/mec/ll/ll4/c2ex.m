close all;
t=(0:pi/70:120);
n=0;
for style=[0.03,0.07,0.1]
            n=n+1;
            [v1,v2,v3]=c2(t,style);
            figure(n);
            plot(t,v3,'--g','linewidth',1.5);
            legend('v3');
            title(['\Delta\alpha=',num2str(style),'rad']);
             xlabel('t,sec');
             ylabel('v,m');
end