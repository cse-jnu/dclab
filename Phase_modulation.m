%Fs must be at least 2*Fc

clear;
clc;
t=0:0.005:1; 

% Equation of carrier signal
fc=10;
x=sin(2*pi*fc*t);	
subplot(3,1,1); 
plot(t,x), grid on;% Graphical representation of Modulating signal
title ( '  Carrier signal  ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');


% Equation of (modulating (mEssage) signal
fs=20;
yc=sin(2*pi*fs*t);	
subplot(3,1,2);
plot(t,yc), grid on; 
title ( '  modulating signal   ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');


% Equation of modulated signal
phasedev = pi/2;
tx = pmmod(x,fc,fs,phasedev);
subplot(3,1,3);
plot(t,tx), grid on; 
title ( '  Modulated Signal   ');
xlabel ( ' time(sec) ');
ylabel (' Amplitude');
