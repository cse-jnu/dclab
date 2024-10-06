clear;
clc;
b = [0 1 0 1 1 1 0];
n = length(b);

t1 = 0:.01:n;
sint1=sin(2*pi*t1);
sint2=sin(2*pi*110*t1);

for i = 1:n
    bm(i*100:(i+1)*100) = b(i)
end

bm = bm(100:end)

for i = 1:length(bm)
    if bm(i)==0
        bm(i) = -1
    end
end

% bm(bm==0)=-1

for i = 1:length(bm)
    if bm(i) == -1
        bw(i)=sint1(i)
    else
        bw(i)=sint2(i)
    end
end

subplot(4,1,1)
plot(t1,bm)
grid on ;
axis([0 n -2 +2])
subplot(4,1,2)
plot(t1,sint1)
grid on ;
axis([0 n -2 +2])
subplot(4,1,3)
plot (t1, sint2);
grid on ;
axis([0 n -2 +2])
subplot(4,1,4)
plot (t1, bw);
grid on ;
axis([0 n -2 +2])
