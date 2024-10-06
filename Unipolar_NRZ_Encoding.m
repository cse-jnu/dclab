clear;
clc;
b =[1 0 1 1 1 1 0];
n = length(b);
t = 0:.01:n;
for i = 1:n
bw(i*100:(i+1)*100) = b(i);
end
bw = bw(100:end);
subplot(1,1,1)
plot(t,bw)
grid on ; 
axis([0 n -2 +2])
