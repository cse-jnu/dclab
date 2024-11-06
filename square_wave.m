f = 2;            
T = 1 / f;          
t = 0:0.001:4*T;
for i=1:length(t)
    sqwave(i)=4/pi*(sin(2*pi*f*t(i))+(1/3)*sin(2*pi*3*f*t(i))+(1/5)*sin(2*pi*5*f*t(i))+(1/7)*sin(2*pi*7*f*t(i))+(1/9)*sin(2*pi*9*f*t(i)));
end
subplot(1,1,1);
plot(t, sqwave);
title('Square Wave Approximation Using Sum of First Five Odd Harmonics');
xlabel('Time(s)');
ylabel('Amplitude');
grid on;
