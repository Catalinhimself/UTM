fi_1 = 65 * pi / 180
for t = [0:0.00001:1]
fi_e = 2*t^3-t^2+t;
if round(fi_e,4) == round(fi_1,4)
    t
    fi_e    
    break
end
end