clear;
clc;

t=0:0.0005:1; 

% Equation of modulating (Message signal) signal
ym=5*sin(2*pi*5*t); 	
subplot(3,1,1); 
plot(t,ym), grid on;
title ( '  Modulating Signal  ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');


% Equation of carrier signal
yc=5*sin(2*pi*100*t);	
subplot(3,1,2);
plot(t,yc), grid on; 
title ( '  Carrier Signal   ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');

% Amplitude modulated signal
y=ym.*yc; 
subplot(3,1,3);
plot(t,y);			
title ( ' Amplitude Modulated signal  ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');
grid on
